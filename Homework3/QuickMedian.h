/**
* Title : Heaps
* Author : Deniz Çalkan
* ID: 21703994
* Section : 01
* Assignment : 3
* Description : Quick median data structure interface.
*/

#include "MaxHeap.h"
#include "MinHeap.h"
#ifndef QuickMedian_h
#define QuickMedian_h

class QuickMedian {
    
public:
    QuickMedian();
    void insert(int val); // inserts an element into QuickMedian
    double getMedian(); // returns the median of elements
    
protected:
    
     void rebalance();
    
    
private:
    
    int size;
    MinHeap minH;
    MaxHeap maxH;
    
    
    
};
#endif /* QuickMedian_h */
