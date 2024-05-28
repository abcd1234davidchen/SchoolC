#include<iostream>

#include "admin.h"
#include "user.h"

using namespace std;

int main(){
    User user;
    Admin admin;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (user.isUser(username, password)) cout << "User logged in." << endl;
    else if (admin.isAdmin(username, password)) cout << "Admin logged in." << endl;
    else cout << "Invalid username or password." << endl;
    return 0;
}
