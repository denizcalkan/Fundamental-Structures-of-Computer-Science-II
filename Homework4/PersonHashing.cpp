/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description:  PersonHashing implementation
*/
#include "PersonHashing.h"


PersonHashing::PersonHashing()
{
    
}


PersonHashing::~PersonHashing()
{
    
    for (int i = 0; i < 11; i++)
    {
        people[i] = NULL;
       
    }
}

Person* PersonHashing::getPerson(string pName) {
    
    pNode* current;
    current = people[hashFunct(pName)];
    while(current->p->pName != pName) {
        current = current->next;
    }
    return current->p;
}


void PersonHashing::personHash(Person* p) {

    int k = hashFunct(p->pName);
   
    pNode* personNode = new pNode(p);
    pNode* current;
    current = people[k];
    people[k] = personNode;
    people[k]->next = current;
    current = NULL;
    personNode = NULL;
    
}

int PersonHashing::hashFunct(string pName) {
   
    int res = 0;
    
    for (int i = 0; i < pName.size(); i++) {
        
        res = res + pName[i];
    }
    res = res % 11;
    return res;
}

