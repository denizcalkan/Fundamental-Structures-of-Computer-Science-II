/**
* Title : Heaps
* Author : Deniz Çalkan
* ID: 21703994
* Section : 01
* Assignment : 3
* Description : Main
*/

#include "MaxHeap.h"
#include "MinHeap.h"
#include "QuickMedian.h"
#include <iostream>
using namespace std;

int main() {
    
    MinHeap min;
    
    min.insert(15);
    min.insert(50);
    min.insert(45);
    min.insert(30);
    min.insert(60);
    min.insert(55);
    min.insert(20);
    min.insert(35);
    min.insert(10);
    min.insert(25);
    min.insert(65);
    
    cout<<"Get min from min heap"<<endl;
    cout<<min.getMin()<<endl;
    cout<<"Get size of min heap"<<endl;
    cout<<min.getSize()<<endl;
    cout<<"Get height of min heap"<<endl;
    cout<<min.getHeight()<<endl;
    cout<<"Get the values less than 40 from min heap"<<endl;
    min.getLessThan(40);
   
    MaxHeap max;
    
    max.insert(15);
    max.insert(50);
    max.insert(45);
    max.insert(30);
    max.insert(60);
    max.insert(55);
    max.insert(20);
    max.insert(35);
    max.insert(10);
    max.insert(25);
    max.insert(65);
    
    cout<<"Get max from max heap"<<endl;
    cout<<max.getMax()<<endl;
    cout<<"Get size of max heap"<<endl;
    cout<<max.getSize()<<endl;
    cout<<"Get height of max heap"<<endl;
    cout<<max.getHeight()<<endl;
    cout<<"Get the values greater than 40 from max heap"<<endl;
    max.getGreaterThan(40);
    
    
   
    QuickMedian med;
    med.insert(10);
    med.insert(40);
    med.insert(30);
    med.insert(50);
    med.insert(70);
    med.insert(60);
    med.insert(20);
    med.insert(90);
    med.insert(100);
    med.insert(110);
    med.insert(0);
    med.insert(25);
    med.insert(123);
    med.insert(11);
    med.insert(200);
    
    cout<<"Get the median"<<endl;
    cout<< med.getMedian()<<endl;
    
    
    return 0;
}
