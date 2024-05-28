#include<iostream>
#include "admin.h"
#include "security.h"
using namespace std;

bool Admin::isAdmin(string username, string password){
    int id = Security::validate(username, password);
    if (id==2) return true;
    return false;
}
