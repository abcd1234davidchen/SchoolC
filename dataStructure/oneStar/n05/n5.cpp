#include<iostream>
using namespace std;

int main(){
    string ipt;
    while(cin>>ipt,ipt!="0"){
        int one=0;
        for(size_t i=0;i<ipt.size();i++){
            int digit = ipt[i] - '0';
            one+=((i%2==0)?digit:-digit);
        }
        cout<<(one%11==0)<<endl;
    }
}
