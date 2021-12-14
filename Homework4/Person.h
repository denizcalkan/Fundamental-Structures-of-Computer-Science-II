/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description: Person  header
*/

using namespace std;
#include <string>
#include <iostream>
#ifndef Person_h
#define Person_h

class pNode;

class Person {

public:
    
    string pName;
    pNode* friends;
    Person(string pName);
    ~Person();
    pNode* addFriend(Person* person);
    void getFriends();
    void removeFriend(Person* person);
   

};

class pNode {

public:
    pNode(Person* person);
    ~pNode();
    Person* p;
    pNode* next;
    

};

#endif /* Person_h */
