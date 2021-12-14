/**
* Title: Algorithm Efficiency and Sorting
*Author: Deniz Çalkan
* ID: 21703994
* Section: 1
* Assignment: 1
* Description: Header File */

#ifndef sorting_h
#define sorting_h
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>  
#include <iomanip>
using namespace std;

void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount);

void insertionSort(int *arr, int size, int &compCount, int &moveCount);

void hybridSort(int *arr, int size, int &compCount, int &moveCount);

void printArray(int *arr, int size);

void performanceAnalysis();

void partition(int *arr, int f, int l, int &pivotIndex, int &compCount, int &moveCount);

void swap(int &a, int &b);

void hybridSort(int *arr, int f ,int l, int &compCount, int &moveCount);

void PartitionH(int* theArray, int first, int last, int &pivotIndex, int& compCount, int& moveCount);























#endif /* sorting_h */
