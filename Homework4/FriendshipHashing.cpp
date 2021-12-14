/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description:  FriendshipHashing implementation
*/

#include "FriendshipHashing.h"



FriendshipHashing::FriendshipHashing() {
    
}


FriendshipHashing::~FriendshipHashing() {
    for (int i = 0; i < 71; i++) {
    
        allFriendships[i] = NULL;
     }

}


int FriendshipHashing::probing(int hashedValue, int i) {
    
    int result = (i * i) + hashedValue;
    result = result % 71;
    
    return result;
}

void FriendshipHashing::removeFriend(string name1, string name2) {

    int prob = 0;
    string order = "";
    order = name1 > name2 ? (name2 + name1) : (name1 + name2);
    int hash = hashFunct(order);
   
    for (int i = 0; i < 71; i++)
    {
        prob = probing(hash, i);
        
        if (allFriendships[prob]->order == order)
                 
            return;
        }

        if (allFriendships[prob] == NULL) {
           
            return;
        }

       
    delete allFriendships[prob];
    
    allFriendships[prob] = NULL;
    
    check[prob] = 1;

}


bool FriendshipHashing::findFriend(string name1, string name2) {

    string order ="";
    order = name1 > name2 ? (name2 + name1) : (name1 + name2);
    int hash = hashFunct(order);
    
    for (int i = 0; i < 71; i++) // assumption is that hash table is never full
    {
        int prob = probing(hash, i);

        if (allFriendships[prob]->order == order) {
           
            return 1;
        }
        
        if (allFriendships[prob] == NULL) {
           
            return 0;
        }
    }
    return 0;
}

int FriendshipHashing::hashFunct(string name) {
   
    int result = accumulate(name.begin(), name.end(), 0);
    result = result % 71;
    
    return result;
}

void FriendshipHashing::friendshipHash(Friendship* friendship) {

    int hash = hashFunct(friendship->order);
    int prob;
    for (int i = 0; i < 71; i++)
    {
        prob = probing(hash, i);

        if (allFriendships[prob] == NULL)
        {
            allFriendships[prob] = friendship;
            check[prob] = false;
        }
    }
}


