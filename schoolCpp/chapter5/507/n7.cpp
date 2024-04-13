#include<iostream>
using namespace std;

int main(){
    int score[6]={0},student;
    cin>>student;
    while(student!=-1){
        score[student]+=1;
        cin>>student;
    }
    for(int i=0;i<=5;i++){
        cout<<"score"<<i<<"have"<<score[i]<<"students"<<endl;
    }
}
