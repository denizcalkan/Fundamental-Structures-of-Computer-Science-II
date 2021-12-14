/**
* Title : Heaps
* Author : Deniz Çalkan
* ID: 21703994
* Section : 01
* Assignment : 3
* Description : Min heap data structure interface.
*/



#ifndef MinHeap_h
#define MinHeap_h

class MinHeap {

public:
    MinHeap();
    ~MinHeap();
    void insert(int val); // inserts an element into heap
    int getMin(); // retrieves the minimum element
    int removeMin(); // retrieves and removes the minimum element
    int getSize(); // returns the number of elements in heap in O(1) time
    int getHeight(); // returns the height of heap in O(1) time
    int* getLessThan(int val); // returns an array of integer elements that are less than given value by doing a preorder traversal on the heap
    void preorder(int*& arr, int node, int& arrSize, const int val);
   
   
protected:
    
    void heapDelete(int& rootItem);
    void heapRebuild(int root);
    
private:
    
    int size;
    int *items;

};
#endif /* MinHeap_h */
