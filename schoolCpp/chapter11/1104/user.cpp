#include<iostream>
#include "user.h"
#include "security.h"
using namespace std;

bool User::isUser(string username, string password){
    int id = Security::validate(username, password);
    if (id==1) return true;
    return false;
}
