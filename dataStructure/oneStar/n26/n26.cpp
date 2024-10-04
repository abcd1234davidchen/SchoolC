#include <iostream>
using namespace std;

int main(){
    vector <int> fib;
    fib.push_back(1);
    fib.push_back(2);
    int dec;
    cin>>dec;
    while(fib.back()<=dec){
        size_t size = fib.size();
        fib.push_back(fib[size-1]+fib[size-2]);
    }
    fib.pop_back();
    reverse(fib.begin(),fib.end());
    for(size_t i=0;i<fib.size();i++){
        //cout<<"FIB"<<fib[i];
        if(dec>=fib[i]){
            cout<<1;
            dec-=fib[i];
        }
        else{
            cout<<0;
        }
        //cout<<endl;
    }
}
