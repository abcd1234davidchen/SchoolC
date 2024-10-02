#include<iostream>
using namespace std;

int main(){
    char ipt;
    while(cin>>ipt){
        if(ipt <= '9' && ipt >='1'){
            cout<<(ipt-'0')+1;
        }
        else if(ipt == '0'){
            cout<<2;
        }
        else if(ipt >= 'A' && ipt <='Z'){
            cout<<(ipt-'A')+10+1;
        }
        else if(ipt >= 'a' && ipt <='z'){
            cout<<(ipt-'a')+26+10+1;
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
}