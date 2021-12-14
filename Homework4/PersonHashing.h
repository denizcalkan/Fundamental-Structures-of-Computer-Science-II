/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description:  PersonHashing header
*/
#ifndef PersonHashing_h
#define PersonHashing_h
using namespace std;
#include "Person.h"
#include <string>
#include <numeric>


class PersonHashing {
    
public:
    
    PersonHashing();
    ~PersonHashing();
    Person* getPerson(string pname);
    void personHash(Person* p);
    

private:

    int hashFunct(string pName);
     pNode* people[11];

};
#endif /* PersonHashing_h */
