#include<iostream>
#include"user.h"

namespace Authenticate{
    string username;
}

namespace{
    bool isValid(){
        if (Authenticate::username.length() != 8){
            return false;
        }
        return true;
    }
}

namespace Authenticate{
    using namespace std;
    void inputUserName(){
        do
        {
        cout << "Enter your username (8 letters only)" << endl;
        cin >> username;}
        while (!isValid( ));
    }
    string getUserName( ){
        return username;
    }
}
