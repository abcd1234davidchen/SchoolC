#include<iostream>

#include"user.h"
#include"password.h"

using namespace std;
int main(){
    Authenticate::inputUserName();
    Authenticate::inputPassword();
    cout<<"User Name: "<<Authenticate::getUserName()<<endl;
    cout<<"Password: "<<Authenticate::getpassword()<<endl;
    return 0;
}
