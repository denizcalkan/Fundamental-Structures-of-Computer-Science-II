/**
* Title : Heaps
* Author : Deniz Çalkan
* ID: 21703994
* Section : 01
* Assignment : 3
* Description :  Implemantation of a combined data structure to find median of the heap.
*/

#include "QuickMedian.h"

QuickMedian::QuickMedian(): size(0) {
    
    minH = MinHeap();
    maxH = MaxHeap();
}
void QuickMedian::insert(int val) {
    
     if((size > 0 ) && (getMedian() > val )){
        
         maxH.insert(val);
         size++;
         rebalance();
         
     }
     else {
        
         minH.insert(val);
         size++;
         rebalance();
         
     }

    
}
double QuickMedian::getMedian() {
    
    double k;
    if ( (minH.getSize() == maxH.getSize())) {
       
        k = (minH.getMin() + maxH.getMax()) / 2;
       
        return k;
    }
    else {
        
        if (minH.getSize() > maxH.getSize()) {
            
            return minH.getMin();
            
            
        }
        else {
          
            return maxH.getMax();
        }
    }
}

void QuickMedian::rebalance() {

    if((minH.getSize() - maxH.getSize()) > 1) {
        
        maxH.insert(minH.removeMin());
    }
    if((maxH.getSize() - minH.getSize()) > 1) {
        
        minH.insert(maxH.removeMax());
    }
}

