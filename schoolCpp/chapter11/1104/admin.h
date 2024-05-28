#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>
#include "security.h"
using namespace std;

class Admin{
    public:
        bool isAdmin(string username, string password);
};

#endif // ADMIN_H
