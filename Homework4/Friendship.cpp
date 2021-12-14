/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description:  Friendship  implementation
*/

#include "Friendship.h"

Friendship::Friendship(pNode* person1, pNode* person2) {
    
    Person* personA = person1->p;
    Person* personB = person2->p;
    person1 = person1;
    person2 = person2;

    order = personA->pName > personB->pName ? (personB->pName + personA->pName) : (personA->pName + personB->pName);
   
}
Friendship::~Friendship() {
    person1 = NULL;
    person2 = NULL;
}
