/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description: Main
*/
#include <string>
#include <sstream>
#include <numeric>
#include <iostream>
#include <fstream>
#include "Person.h"
#include "PersonHashing.h"
#include "Friendship.h"
#include "FriendshipHashing.h"
using namespace std;


int main() {
   
    ifstream input("input.txt");
    FriendshipHashing friendshipH;
    PersonHashing personH;
    bool find = 0;
    int X;
    char c;
    string str;
    string line;
    string person1;
    string person2;
    Person* pers1;
    Person* pers2;

    while ( getline(input, line) )
    {
        c = line.at(0);
        str = line.replace(0, 2, "");

        if (c == 'P')
        {
            Person* person = new Person(str);
            personH.personHash(person);
        }
        if (c == 'F') {
            person1 = str.substr(0, str.find(" "));
            person2 = str.substr(str.find(" ")+1, str.length());
            pers1 = personH.getPerson(person1);
            pers2 = personH.getPerson(person2);
            pNode* f1 = pers1->addFriend(pers2);
            pNode* f2 = pers2->addFriend(pers1);
            Friendship* f = new Friendship(f1, f2);
            friendshipH.friendshipHash(f);
        }
        
        if (c == 'U') {
             person1 = str.substr(0, str.find(" "));
             person2 = str.substr(str.find(" ") + 1, str.length());
             pers1 = personH.getPerson(person1);
             pers2 = personH.getPerson(person2);
             pers1->removeFriend(pers2);
             pers2->removeFriend(pers1);

             friendshipH.removeFriend(person1, person2);
        }
        
        if (c == 'L') {
           
            Person* person = personH.getPerson(str);
            person->getFriends();
        }
        
        if (c == 'Q')
        {
            
            person1 = str.substr(0, str.find(" "));
            person2 = str.substr(str.find(" ") + 1, str.length());
            pers1 = personH.getPerson(person1);
            pers2 = personH.getPerson(person2);
            find = friendshipH.findFriend(pers1->pName, pers2->pName);
            
            if (find == 1) {
                 cout <<"Yes" << endl;
            }
            else {
                
                cout << "No" << endl;
            }

        }
    }
    cin >> X;
    return 0;
}
