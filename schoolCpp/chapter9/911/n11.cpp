#include<iostream>
using namespace std;

int main(){
    string first,second;
    int firstCount[26]={0};
    int secondCount[26]={0};
    getline(cin,first);
    getline(cin,second);
    for(size_t i=0;i<first.size();i++){
        if(isalpha(first[i])){
            firstCount[tolower(first[i])-'a']++;
        }
    }
    for(size_t i=0;i<second.size();i++){
        if(isalpha(second[i])){
            secondCount[tolower(second[i])-'a']++;
        }
    }
    bool comp=true;
    for(size_t i=0;i<26;i++){
        if(firstCount[i]!=secondCount[i]){
            comp=false;
        }
    }
    cout<<comp;
}
