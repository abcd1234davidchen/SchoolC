#ifndef USER_H
#define USER_H
#include<iostream>
#include "security.h"

using namespace std;

class User{
    public:
        bool isUser(string username, string password);
};

#endif // USER_H
