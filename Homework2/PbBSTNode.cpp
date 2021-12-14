/**
* Title: Binary Search Tree Node
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 2
* Description: Pointer based binary search tree node implementation.
*/

#include "PbBSTNode.h"


PbBSTNode::PbBSTNode(){
    
}
PbBSTNode::PbBSTNode(const int& item, PbBSTNode *leftPtr, PbBSTNode *rightPtr) {
    
    data = item;
    left = leftPtr;
    right = rightPtr;
    
}
