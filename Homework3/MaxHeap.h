/**
* Title : Heaps
* Author : Deniz Çalkan
* ID: 21703994
* Section : 01
* Assignment : 3
* Description : Max heap data structure interface.
*/

#ifndef MaxHeap_h
#define MaxHeap_h


class MaxHeap {

public:
    MaxHeap();
    ~MaxHeap();
    void insert(int val); // inserts an element into heap
    int getMax(); // retrieves the minimum element
    int removeMax(); // retrieves and removes the minimum element
    int getSize(); // returns the number of elements in heap in O(1) time
    int getHeight(); // returns the height of heap in O(1) time
    int* getGreaterThan(int val); // returns an array of integer elements that are less than given value by doing a preorder traversal on the heap
    void preorder(int*& arr, int node, int& arrSize, const int val);
   
protected:
    
    void heapDelete(int& rootItem);
    void heapRebuild(int root);
    
private:
    
    int size;
    int *items;

};
#endif /* MaxHeap_h */
