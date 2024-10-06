#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkPrime(string s){
    int check = stoi(s);
    if (check==2) return true;
    if (check<2) return false;
    for(int i=2;i*i<=check;i++){
        if(check%i==0) return false;
    }
    return true;
}

int main(){
    string ipt,rv;
    while(cin>>ipt){
        if(checkPrime(ipt)){
            reverse(ipt.begin(),ipt.end());
            rv = ipt;
            reverse(ipt.begin(),ipt.end());
            if(rv == ipt){
                cout<<ipt<<" is prime."<<endl;
                continue;
            }
            if(checkPrime(rv)){
                cout<<ipt<<" is emirp."<<endl;
            }
            else{
                cout<<ipt<<" is prime."<<endl;
            }
        }
        else{
            cout<<ipt<<" is not prime."<<endl;
        }
    }
}
