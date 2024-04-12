#include<iostream>
using namespace std;

void purchase(int& money){
    cout<<money<<" left"<<endl;
    int bread[4]={10,20,30,40};
    cout<<"Bread of choice:";
    for(int i=0;i<4;i++){
        cout<<" "<<bread[i];
    }
    cout<<endl;
    int item;
    cin>>item;
    money-=bread[item-1];
    if(money<0){
        money+=bread[item-1];
        cout<<"Not enough for that"<<endl;
    }
}

int main(){
    int money=200;
    while(money>=10){
        purchase(money);
        
    }
    cout<<money<<"left"<<200-money<<"spent";
}
