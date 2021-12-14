/**
* Title : Heaps
* Author : Deniz Çalkan
* ID: 21703994
* Section : 01
* Assignment : 3
* Description : Implementation of max heap data structure.
*/

#include "MaxHeap.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int MAX_HEAP = 100;

MaxHeap::MaxHeap(): size(0){
    
    items = new int[MAX_HEAP];
}
MaxHeap::~MaxHeap() {
    
    if (getSize() != 0) {
        
        delete []items;
    }
    size = 0;
}
void MaxHeap::insert(int val) {
    
    if (size >= MAX_HEAP) {
        cout<<"HeapException: Heap is full"<<endl;
        return;
    }
    if (size < MAX_HEAP) {
        
        items[size] = val;
        int place = size;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place] > items[parent]) ) {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
         }
    
    }
    ++size;
}

int MaxHeap::getMax() {
    
    if (size == 0) {
      
        cout<<"HeapException: Heap is empty"<<endl;
        return -1;
    }
    else {
        
        return items[0];
    }
}
int MaxHeap::removeMax() {
    
    if (size == 0) {
        cout<<"HeapException: Heap is empty"<<endl;
        return -1;
    }
    else {
        
        int max = getMax();
        heapDelete(items[0]);
        return max;
    }
}
int MaxHeap::getSize() {
    
    return size;
}
int MaxHeap::getHeight() {
    
    return ceil(log2(size + 1));
}
int* MaxHeap::getGreaterThan(int val) {
    
    int* arr = new int[size];
     int node = 0;
     int arrSize = 0;
    
     preorder(arr, node, arrSize, val);

     cout << "Values: ";
     for (int i = 0; i < arrSize; i++) {
         cout<<arr[i];
         cout<<" ";
     }
     cout<<endl;
     return arr;
}

void MaxHeap::heapDelete(int& rootItem) {
    
    if (size == 0) {
        cout<<"HeapException: Heap is empty"<<endl;
     }
     else {
            rootItem = getMax();
            items[0] = items[--size];
            heapRebuild(0);
        }
}


void MaxHeap::heapRebuild(int root) {
    
    int child = 2 * root + 1;
    if ( child < size ) {
      
        int rightChild = child + 1;
        if ( (rightChild < size) && (items[rightChild] >items[child]) ) {
            child = rightChild;     // index of larger child
        }
       
        if ( items[root]  < items[child] ) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

           heapRebuild(child);
                    
        }
    }
}

void MaxHeap::preorder(int*& arr, int node, int& arrSize, const int val) {

    if (node >= size ) {
        
        return;
    }
    if ( items[node] > val ) { // this is where we add an item to the list.
        
        arr[arrSize] = items[node];
    
        arrSize++;

    }
    preorder(arr, (node*2 + 1), arrSize, val); // go left child
    preorder(arr, (node*2 + 2), arrSize, val); // go right child
}
