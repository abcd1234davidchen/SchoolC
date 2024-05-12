#include<iostream>
#include<cctype>
using namespace std;

string process(string og){
    string processed;
    for(size_t i=0;i<og.size();i++){
        if(isalpha(og[i])){
            processed+=(char)tolower(og[i]);
        }
    }
    return processed;
}

int main(){
    string one,two;
    while (1){
        getline(cin,one);
        getline(cin,two);
        one=process(one);
        two=process(two);
        cout<<(one==two)<<endl;
    }
}
