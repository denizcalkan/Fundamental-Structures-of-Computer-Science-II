/**
* Title: Binary Search Tree Node
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 2
* Description: Pointer based binary search tree node header file.
*/

#ifndef PbBSTNode_h
#define PbBSTNode_h

class PbBSTNode {
    
    
    PbBSTNode();
    PbBSTNode(const int& item, PbBSTNode *leftPtr, PbBSTNode *rightPtr);
    
private:
    int data;
    PbBSTNode *left;
    PbBSTNode *right;
    
friend class PbBST;
    
};


#endif /* PbBSTNode_h */
