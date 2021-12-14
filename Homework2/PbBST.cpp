/**
* Title: Binary Search Tree
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 2
* Description: Pointer based binary search tree  implementation.
*/
#include "PbBST.h"
#include "PbBSTNode.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

PbBST::PbBST() : root(NULL) {

    
}

PbBST::~PbBST() {
    
    destroyTree(root);
}

void PbBST::insertKey(int key) {
    
    insertKey(key, root);
}
void PbBST::insertKey(const int key, PbBSTNode *&node){
   
    if (node == NULL) {
        node = new PbBSTNode(key, NULL, NULL);
    } else {

        if (key < node->data) {
          
            insertKey(key, node->left);
        } else {
            
            insertKey(key, node->right);
        }
    }
 
}
void PbBST::deleteKey(int key) {
    
    deleteNode(root, key);
    
}
void PbBST::deleteNode(PbBSTNode *&root, int key) {
    
     if(root == NULL) {
         return;
     }
     else if(key < root->data) {
        
         deleteNode(root->left,key);
     }
     else if (key > root->data) {
        deleteNode(root->right,key);
     }
    else {
        // Case 1: No childeren
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        //Case 2: One child
        else if(root->left == NULL) {
            PbBSTNode *temp = root;
            root = root->right;
            temp->right = NULL;
            delete temp;
        }
        else if(root->right == NULL) {
            PbBSTNode *temp = root;
            root = root->left;
            temp->left = NULL;
            delete temp;
        }
        // case 3:2 children
        else {
            PbBSTNode *temp = processLeftMost(root->right);
            root->data = temp->data;
            deleteNode(root->right,temp->data);
        }
    }
}

int PbBST::getHeight() {
    
    return getHeight(root);
}
int PbBST::getNodeCount() {
   
    int nodeCount = 0;
    countNodes(nodeCount, root);
    return nodeCount;
}
int PbBST::findNodesRequired() {
    
    return pow(2.0, getHeight() - 0.0) - 1 - getNodeCount();
}

void PbBST::mirrorTree() {
    if(root == NULL) {
        
        return;
        
    }
    cout<<"Mirrored Tree"<<endl;
    root = constructMirrorOfTreeAux(root);
    
}

PbBSTNode* PbBST::constructMirrorOfTreeAux(PbBSTNode *&node) {
    
    if(node == NULL) {
        
        return NULL;
    }
        PbBSTNode *left = constructMirrorOfTreeAux(node->left);
        PbBSTNode *right = constructMirrorOfTreeAux(node->right);
        PbBSTNode *current = new PbBSTNode();
        current->data = node->data;
        current->left = right;
        current->right = left;
        return current;
    
}
void PbBST::preorderTraversal() {
    
    preorder(root);
}

void PbBST::preorder(PbBSTNode *&node) {
    
    if (node == 0) {
        return;
    }

    cout<< node->data << " ";
    preorder(node->left);
    preorder(node->right);
    
    
}

void PbBST::destroyTree(PbBSTNode *root) {
    
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root = NULL;
    }
    
}

PbBSTNode* PbBST::processLeftMost( PbBSTNode *node){
   
    while(node->left != NULL) {
        node = node->left;
    }
   return node;
}

int PbBST::getHeight(PbBSTNode *root){
    if (root == NULL) {
        return 0;
    }
    else {
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
}

double PbBST::medianOfBST() {
    
    int *arr = new int[getNodeCount()];
    double median = 0.0;
    int index = 0;
    findMedian(arr, index, root, median);
    return median;
    
}

void PbBST::countNodes(int& nodeCount, PbBSTNode *&node) {
    if (node == NULL) {
        return;
    }
   
    countNodes(nodeCount,node->left);
    nodeCount++;
    countNodes(nodeCount,node->right);
}

void PbBST::inToArray(int *arr, int &index, PbBSTNode *&node) {
   if (node == NULL) {
        return;
    }
   
    inToArray(arr, index, node->left);
    arr[index++] = node->data;
    inToArray(arr, index, node->right);
    
}

void PbBST::findMedian(int *arr, int &index, PbBSTNode *&node, double &median) {
    
    int size = getNodeCount() - 1;
    inToArray(arr, index, node);
    
    if (size % 2 == 0) {
        
        median = (arr[size / 2] + arr[size / 2] + 1 ) / 2;
    }
    else {
        
        median = arr[(size + 1) / 2];
    }
    
}
