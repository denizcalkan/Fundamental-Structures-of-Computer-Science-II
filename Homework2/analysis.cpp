/**
* Title: Binary Search Tree Analysis
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 2
* Description: Pointer based binary search tree analysisi.
*/

#include <stdio.h>
#include "analysis.h"
#include "PbBST.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
using namespace std;

void heightAnalysis() {
    
    cout<<"------------------------------------------------------------"<<endl;
    cout<< "Part e - Height analysis of Binary Search Tree - part 1"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout << "Tree Size" << setw(16) << "Tree Height"<< endl;
    cout<<"------------------------------------------------------------"<<endl;
    
    int arr[15000];
    PbBST tree;
    
    for (int i = 0; i < 15000; i++) {
        
       
        int randomNum = rand() % 15000 + 1;
        
            arr[i] = randomNum;
    }
    
    for (int i = 0; i < 15000; i++) {
      
       
            
            tree.insertKey(arr[i]);
        
        if ((i+1) % 1500 == 0) {
        cout << tree.getNodeCount() << setw(15) << tree.getHeight() << endl;
       
    }
}
    
    shuffleArray(arr, 15000);
    
    
    
    cout<<"------------------------------------------------------------"<<endl;
    cout<< "Part e - Height analysis of Binary Search Tree - part 2"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout << "Tree Size" << setw(15) << "Tree Height"<< endl;
    cout<<"------------------------------------------------------------"<<endl;
   
    for (int i = 0; i < 15000; i++) {
       
        
             
             tree.deleteKey(arr[i]);
             if ((i+1) % 1500 == 0) {
                 cout << tree.getNodeCount() << setw(15) << tree.getHeight() << endl;
                
             }

 }
}

void shuffleArray(int arr[], int size) {
    
    int temp = 0;
    int random = 0;
    
    for (int i = 0; i < size; i++) {
        
        random = rand() % size;
        temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;
    }
 }
    

