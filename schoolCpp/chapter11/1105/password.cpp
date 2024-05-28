#include<iostream>
#include"password.h"

namespace Authenticate{
    string password;
}

namespace{
    bool isValid(){
        using namespace Authenticate;
        if (password.length() < 8){
            return false;
        }
        for(int i=0;i<password.length();i++){
            if(!isalpha(password[i])){
                return true;
            }
        }
        return false;
    }
}

namespace Authenticate{
    using namespace std;
    void inputPassword(){
        do{
        cout << "Enter your password (at least 8 characters " <<
        "and at least one non-letter)" << endl;
        cin >> password;
        }
        while (!isValid( ));
    }
    string getpassword( ){
        return password;
    }
}

