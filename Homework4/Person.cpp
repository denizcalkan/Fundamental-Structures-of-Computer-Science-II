/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description: Person implementation
*/
#include "Person.h"

Person::Person(string name) {
    friends = NULL;
    pName = name;
    
}

Person::~Person() {
    pNode* current = friends;
    pNode* next = current;
    delete current;
    current = next;
    
    while (current != NULL)
    {
        next = current->next;
        delete current;
        
        current = next;
    }
}


void Person::getFriends() {
   
    pNode* current = friends;
    while (current != NULL)
    {
        cout << current->p->pName << " ";
        current = current->next;
    }
}

void Person::removeFriend(Person* person) {

    pNode* current = friends;
    pNode* previous = NULL;
    while ((current->p->pName != person->pName) && current != NULL) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && previous != NULL) {
        previous->next = current->next;
        delete current;
    }

    if( (current == friends) && (current != NULL)) {
        delete current;
    }
}

pNode* Person::addFriend(Person* person) {

    pNode* personToAdd = new pNode(person);
    pNode* temp = friends;
    
    friends = personToAdd;
    personToAdd->next = temp;
    return personToAdd;
}


pNode::pNode(Person *person) {
    p = person;
    next = NULL;
}


pNode::~pNode() {

}

