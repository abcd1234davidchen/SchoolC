#include<iostream>
using namespace std;

int dayOfYear(int m, int d){
    int Month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int rt=0;
    for(int i=0;i<m-1;i++){
        rt+=Month[i];
    }
    rt+=d;
    return rt;
}

int main(){
    string dayOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};    int monday = dayOfYear(4,4)%7;
    int time;
    cin>>time;
    for(int i=0;i<time;i++){
        int m,d;
        cin>>m>>d;
        cout<<dayOfWeek[(dayOfYear(m,d)+7-monday)%7]<<endl;
    }
}