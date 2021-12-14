/**
* Title: Binary Search Trees and Hashing
* Author: Deniz Çalkan
* ID: 21703994
* Section: 01
* Assignment: 4
* Description:  Friendship Hashing header
*/

#ifndef FriendshipHashing_h
#define FriendshipHashing_h
#include <numeric>
#include <string>
#include "Friendship.h"

class FriendshipHashing {
public:
    FriendshipHashing();
    ~FriendshipHashing();
    bool findFriend(string name1, string name2);
    void removeFriend(string name1, string name2);
     void friendshipHash(Friendship* friendship);

private:
    
    int hashFunct(string f);
    int probing(int hashedValue, int i);
    bool check[71] = {0};
    Friendship* allFriendships[71] = {NULL};

};

#endif /* FriendshipHashing_h */
