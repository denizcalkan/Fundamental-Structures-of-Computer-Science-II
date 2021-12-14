/**
* Title: Algorithm Efficiency and Sorting
*Author: Deniz Çalkan
* ID: 21703994
* Section: 1
* Assignment: 1
* Description: Main file to test the program. */

#include <iostream>
#include "sorting.h"
using namespace std;


int main() {

    int arr1[10] = {20, 1, 100, 57, 92, 43, 99, 93, 17, 58};
    int arr2[10] = {20, 1, 100, 57, 92, 43, 99, 93, 17, 58};
    int arr3[10] = {20, 1, 100, 57, 92, 43, 99, 93, 17, 58};
    int compCount = 0;
    int moveCount = 0;
    
    cout<<"Quick Sort Test"<<endl;
    quickSort(arr1, 0, 9, compCount, moveCount);
    printArray(arr1, 10);
    
    compCount = 0;
    moveCount = 0;

    cout<<"Insertion Sort Test"<<endl;
    insertionSort(arr2, 10, compCount, moveCount);
    printArray(arr2, 10);
    
    compCount = 0;
    moveCount = 0;
    
    cout<<"Hybrid Sort Test"<<endl;
    hybridSort(arr3, 10, compCount, moveCount);
    printArray(arr3, 10);
    
    performanceAnalysis();
}
