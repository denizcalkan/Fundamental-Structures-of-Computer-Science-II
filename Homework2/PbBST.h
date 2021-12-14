/**
* Title: Pointer based Binary Search Tree
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 2
* Description: Pointer based binary search tree  header file.
*/
#ifndef _PbBST_h
#define _PbBST_h
#include "PbBSTNode.h"

class PbBST{
 
public:
    PbBST();
    ~PbBST();
    void insertKey(int key);
    void deleteKey(int key);
    int getHeight();
    int getNodeCount();
    int findNodesRequired();
    void mirrorTree();
    double medianOfBST();
    void preorderTraversal();
    void destroyTree(PbBSTNode *root);
    PbBSTNode* processLeftMost( PbBSTNode *node);
    int getHeight(PbBSTNode *root);
    void preorder(PbBSTNode *&node);
    PbBSTNode* constructMirrorOfTreeAux(PbBSTNode *&node);
    void insertKey(const int key, PbBSTNode *&node);
    void deleteNode(PbBSTNode *&root, int key);
    void countNodes (int& nodeCount, PbBSTNode *&node);
    void inToArray(int *arr, int &index, PbBSTNode *&node);
    void findMedian(int *arr, int &index, PbBSTNode *&node, double& median);
    
private:
    
    PbBSTNode *root;
    
};


#endif /* _PbBST_h */
