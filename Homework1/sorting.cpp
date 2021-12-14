/**
* Title: Algorithm Efficiency and Sorting
*Author: Deniz Çalkan
* ID: 21703994
* Section: 1
* Assignment: 1
* Description: There are three sorting algorithms in this prgram. These algorithms are compared by their running time. */

#include <iostream>
#include <ctime>
#include <cmath>
#include "sorting.h"
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
using namespace std;


void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount){

        // choose the first element as pivot
        int pivotIndex;

        if (f < l) {

            // create the partition: S1, pivot, S2
            partition(arr, f, l, pivotIndex, compCount, moveCount);

            // sort regions S1 and S2
            quickSort(arr, f, pivotIndex - 1, compCount, moveCount);
            quickSort(arr, pivotIndex + 1, l, compCount, moveCount);
        }
    }

void partition(int *arr, int f, int l, int &pivotIndex, int &compCount, int &moveCount){

    //choosePivot(theArray, first, last);

    int pivot = arr[f];
    moveCount++;

    int lastS1 = f;
    int firstUnknown = f + 1;

     for (  ; firstUnknown <= l; ++firstUnknown) {

         compCount++;
         if (arr[firstUnknown] < pivot) { // belongs to S1
             ++lastS1;
             swap(arr[firstUnknown], arr[lastS1]);
             moveCount = moveCount + 3;
         }    // else belongs to S2
      }
      // place pivot in proper position and mark its location
      swap(arr[f], arr[lastS1]);
      moveCount = moveCount + 3;
      pivotIndex = lastS1;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}



void insertionSort(int *arr, int size, int &compCount, int &moveCount){

    int nextItem = 0;
    int loc = 0;

    for (int unsorted = 1; unsorted < size; ++unsorted) {

        nextItem = arr[unsorted];
        loc = unsorted -1;
        moveCount++;
        while ( (loc >= 0) && (arr[loc] > nextItem)) {
            arr[loc + 1] = arr[loc];
            --loc;
            compCount++;
            moveCount++;
        }
        arr[loc + 1] = nextItem;
        moveCount++;
    }
}

void hybridSort(int *arr, int size, int &compCount, int &moveCount){
    hybridSort(arr, 0, size-1, compCount, moveCount);
}


void hybridSort(int* arr, int f, int l, int& compCount, int& moveCount){

    int pivotIndex;

   if (f < l) {

      // create the partition: S1, pivot, S2
      PartitionH(arr, f, l, pivotIndex, compCount, moveCount);

      if ((l - f) <= 10)
        return;

      // sort regions S1 and S2
      hybridSort(arr, f, pivotIndex-1,compCount, moveCount);
      hybridSort(arr, pivotIndex+1, l, compCount, moveCount);
   }
}


void PartitionH(int* arr, int f, int l, int &pivotIndex, int& compCount, int& moveCount){

 if ((l - f ) <= 10) {    // insertion sort

         //int counter = 0;
         int nextItem = 0;
         int loc = 0;
         for (int unsorted = f + 1; unsorted < l + 1; ++unsorted) {

             nextItem = arr[unsorted];
             loc = unsorted;
             compCount++;
             while ( (loc > f) && (arr[loc - 1] > nextItem)) {
                 arr[loc] = arr[loc - 1];
                 --loc;
                 compCount++;
             }
             arr[loc] = nextItem;
             moveCount++;
         }
 }
 else { // quick sort
    
         int pivot = arr[f];
         moveCount++;
         int lastS1 = f;
         int firstUnknown = f + 1;

         for (  ; firstUnknown <= l; ++firstUnknown) {

              compCount++;
              if (arr[firstUnknown] < pivot) {      // belongs to S1
                  ++lastS1;
                  swap(arr[firstUnknown], arr[lastS1]);
                  moveCount = moveCount + 3;
              }    // else belongs to S2
           }

           swap(arr[f], arr[lastS1]);
           moveCount = moveCount + 3;
           pivotIndex = lastS1;
    
     }
 }


void printArray(int *arr, int size) {
    
    cout << "[";
    if (size != 0) {
        for(int i = 0; i < size-1; i++){
            cout << arr[i] << ", ";
        }
        cout << arr[size-1];
        cout << "]" << endl;
    }
    else {
        cout << "]" << endl;
    }
}

void performanceAnalysis() {
    
    clock_t counter;
    int moveCount = 0;
    int compCount = 0;
    string result;
    double timeElapsed;
    
    
    int arrQ2[2000]; //Quick Sort
    int arrI2[2000]; //Insertion Sort
    int arrH2[2000]; //Hybrid Sort
    
    int arrQ4[4000]; //Quick Sort
    int arrI4[4000]; //Insertion Sort
    int arrH4[4000]; //Hybrid Sort
   
    int arrQ6[6000]; //Quick Sort
    int arrI6[6000]; //Insertion Sort
    int arrH6[6000]; //Hybrid Sort
    
    int arrQ8[8000]; //Quick Sort
    int arrI8[8000]; //Insertion Sort
    int arrH8[8000]; //Hybrid Sort
       
    
    int arrQ10[10000]; //Quick Sort
    int arrI10[10000]; //Insertion Sort
    int arrH10[10000]; //Hybrid Sort
    
    int arrQ12[12000]; //Quick Sort
    int arrI12[12000]; //Insertion Sort
    int arrH12[12000]; //Hybrid Sort
    
    int arrQ14[14000]; //Quick Sort
    int arrI14[14000]; //Insertion Sort
    int arrH14[14000]; //Hybrid Sort
    
    int arrQ16[16000]; //Quick Sort
    int arrI16[16000]; //Insertion Sort
    int arrH16[16000]; //Hybrid Sort
    
    int arrQ18[18000]; //Quick Sort
    int arrI18[18000]; //Insertion Sort
    int arrH18[18000]; //Hybrid Sort
    
    int arrQ20[20000]; //Quick Sort
    int arrI20[20000]; //Insertion Sort
    int arrH20[20000]; //Hybrid Sort
    
   for (int i = 0; i < 2000; i++) {
            
          int randomNum = rand() % 2000 + 1 ;
          arrQ2[i] = randomNum;
          arrI2[i] = randomNum;
          arrH2[i] = randomNum;
           
    
   }
    
    for (int i = 0; i < 4000; i++) {
          
        int randomNum = rand() % 4000 + 1 ;
        arrQ4[i] = randomNum;
        arrI4[i] = randomNum;
        arrH4[i] = randomNum;
         
    }
    
    for (int i = 0; i < 6000; i++) {
          
        int randomNum = rand() % 6000 + 1 ;
        arrQ6[i] = randomNum;
        arrI6[i] = randomNum;
        arrH6[i] = randomNum;
         
    }
    
    for (int i = 0; i < 8000; i++) {
             
           int randomNum = rand() % 8000 + 1 ;
           arrQ8[i] = randomNum;
           arrI8[i] = randomNum;
           arrH8[i] = randomNum;
            
       }
    
    for (int i = 0; i < 10000; i++) {
          
        int randomNum = rand() % 10000 + 1 ;
        arrQ10[i] = randomNum;
        arrI10[i] = randomNum;
        arrH10[i] = randomNum;
         
    }
    
    for (int i = 0; i < 12000; i++) {
          
        int randomNum = rand() % 12000 + 1 ;
        arrQ12[i] = randomNum;
        arrI12[i] = randomNum;
        arrH12[i] = randomNum;
         
    }
    
    for (int i = 0; i < 14000; i++) {
          
        int randomNum = rand() % 14000 + 1 ;
        arrQ14[i] = randomNum;
        arrI14[i] = randomNum;
        arrH14[i] = randomNum;
         
    }
    
    for (int i = 0; i < 16000; i++) {
          
        int randomNum = rand() % 16000 + 1 ;
        arrQ16[i] = randomNum;
        arrI16[i] = randomNum;
        arrH16[i] = randomNum;
         
    }
    
    for (int i = 0; i < 18000; i++) {
          
        int randomNum = rand() % 18000 + 1 ;
        arrQ18[i] = randomNum;
        arrI18[i] = randomNum;
        arrH18[i] = randomNum;
         
    }
    
    for (int i = 0; i < 20000; i++) {
          
        int randomNum = rand() % 20000 + 1 ;
        arrQ20[i] = randomNum;
        arrI20[i] = randomNum;
        arrH20[i] = randomNum;
         
    }
    
    cout<<"------------------------------------------------------------"<<endl;
    cout<< "Part a - Time analysis of Quick Sort"<<endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    
    
    counter = clock();
    quickSort(arrQ2, 0, 1999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "2000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
   
    compCount = 0;
    moveCount = 0;
       
    
    counter = clock();
    quickSort(arrQ4, 0, 3999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "4000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
   
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    quickSort(arrQ6, 0, 5999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "6000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
    
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    quickSort(arrQ8, 0, 7999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "8000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
       
    compCount = 0;
    moveCount = 0;
       
    counter = clock();
    quickSort(arrQ10, 0, 9999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "10000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
       
       compCount = 0;
       moveCount = 0;
       
    counter = clock();
    quickSort(arrQ12, 0, 11999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "12000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
       
    compCount = 0;
    moveCount = 0;
       
    counter = clock();
    quickSort(arrQ14, 0, 13999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "14000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
       
       compCount = 0;
       moveCount = 0;
       
    counter = clock();
    quickSort(arrQ16, 0, 15999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "16000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
       
    compCount = 0;
    moveCount = 0;
       
    counter = clock();
    quickSort(arrQ18, 0, 17999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "18000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
       
    compCount = 0;
    moveCount = 0;
       
    counter = clock();
    quickSort(arrQ20, 0, 19999, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "20000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
       
    compCount = 0;
    moveCount = 0;
       
    cout<<"------------------------------------------------------------"<<endl;
    cout<< "Part b - Time analysis of Insertion Sort"<<endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    
    counter = clock();
    insertionSort(arrI2, 2000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "2000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
    
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI4, 4000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "4000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
          
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI6, 6000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "6000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI8, 8000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "8000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI10, 10000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "10000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI12, 12000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "12000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI14, 14000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "14000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI16, 16000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "16000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI18, 18000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "18000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    insertionSort(arrI20, 20000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "20000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
             
    compCount = 0;
    moveCount = 0;
    
    cout<<"------------------------------------------------------------"<<endl;
    cout<< "Part c - Time analysis of Hybrid Sort"<<endl;
    cout << "Array size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15) << "moveCount" << endl;
    
    counter = clock();
    hybridSort(arrH2,2000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "2000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                   
    compCount = 0;
    moveCount = 0;
   
    counter = clock();
    hybridSort(arrH4,4000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "4000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    compCount = 0;
    moveCount = 0;
   
    counter = clock();
    hybridSort(arrH6, 6000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "6000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    hybridSort(arrH8, 8000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "8000" << setw(21) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    hybridSort(arrH10, 10000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "10000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    hybridSort(arrH12, 12000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "12000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    hybridSort(arrH14, 14000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "14000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    hybridSort(arrH16, 16000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "16000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                   
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    hybridSort(arrH18, 18000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "18000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    compCount = 0;
    moveCount = 0;
    
    counter = clock();
    hybridSort(arrH20, 20000, compCount, moveCount);
    counter = clock() - counter;
    timeElapsed = (double) counter * 1000 / CLOCKS_PER_SEC;
    result  =  to_string(timeElapsed) + " ms";
    cout<< "20000" << setw(20) << result << setw(15) << compCount << setw(15) << moveCount <<endl;
                
    
    cout<<"------------------------------------------------------------"<<endl;
}
