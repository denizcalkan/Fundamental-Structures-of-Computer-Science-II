/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description:  Friendship  header
*/
#ifndef Friendship_h
#define Friendship_h
#include <string>
#include "Person.h"

class Friendship {
public:
 
    pNode* person1;
    pNode* person2;
    string order;
    Friendship(pNode* person1, pNode* person2);
    ~Friendship();
    
    
};
#endif /* Friendship_h */
