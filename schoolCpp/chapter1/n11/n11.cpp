#include<iostream>
using namespace std;
int main(){
    int second;
    cin>>second;
    cout<<second/3600<<"hour"<<second%3600/60<<"minute"<<second%60<<"second";
}
