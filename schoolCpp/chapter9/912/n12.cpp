#include<iostream>
using namespace std;

int main(){
    string first,second;
    string subF,subS;
    int one,two;
    getline(cin,first);
    getline(cin,second);

    for(size_t i=0;i<first.size();i++){
        if(first[i]=='-'){
            subF+='-';
        }
        else if(isdigit(first[i])){
            subF+=first[i];
        }
    }
    for(size_t i=0;i<second.size();i++){
        if(second[i]=='-'){
            subS+='-';
        }
        else if(isdigit(second[i])){
            subS+=second[i];
        }
    }
    one=atoi(subF.c_str());
    two=atoi(subS.c_str());
    cout<<(one==two);
}