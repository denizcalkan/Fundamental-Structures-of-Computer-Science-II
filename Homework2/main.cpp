/**
* Title: Binary Search Tree
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 2
* Description: Pointer based binary search tree  main.
*/

#include <iostream>
using namespace std;
#include "PbBST.h"
#include "PbBSTNode.h"
#include "analysis.h"

int main() {
   
    PbBST tree;
    tree.insertKey(42);
    tree.insertKey(19);
    tree.insertKey(22);
    tree.insertKey(35);
    tree.insertKey(56);
    tree.insertKey(11);
    tree.insertKey(94);
    tree.insertKey(32);
    tree.insertKey(28);
    tree.insertKey(8);
    tree.insertKey(6);
    tree.insertKey(81);
    tree.insertKey(63);
    tree.insertKey(13);
    tree.insertKey(45);
    cout<<"Tree after insertions"<<endl;
    tree.preorderTraversal();
    cout<<endl;
    cout<<"Required nodes to be a full tree"<<endl;
    int a = tree.findNodesRequired();
    cout<< a <<endl;
    tree.deleteKey(56);
    tree.deleteKey(19);
    cout<<"Tree after deletions"<<endl;
    tree.preorderTraversal();
    cout<<endl;
    cout<<"Median of BST"<<endl;
    int b = tree.medianOfBST();
     cout<<b<<endl;
    tree.mirrorTree();
    tree.preorderTraversal();
    cout<<endl;
    
    heightAnalysis();
    
  
    return 0;
}
