#include<iostream>
using namespace std;

int main(){
    string in;
    while(1){
        getline(cin,in);
        for(int i=0;i<in.size();i++){
            if(in.substr(i,2)=="he"&&!isalpha(in[i-1])&&!isalpha(in[i+2])){
                cout<<"he or she";
                i+=1;
            }
            else if(in.substr(i,3)=="him"&&!isalpha(in[i-1])&&!isalpha(in[i+3])){
                cout<<"him or her";
                i+=2;
            }
            else if(in.substr(i,3)=="she"&&!isalpha(in[i-1])&&!isalpha(in[i+3])){
                cout<<"he or she";
                i+=2;
            }
            else if(in.substr(i,3)=="her"&&!isalpha(in[i-1])&&!isalpha(in[i+3])){
                cout<<"him or her";
                i+=1;
            }
            else{
                cout<<in[i];
            }
        }
    }
}