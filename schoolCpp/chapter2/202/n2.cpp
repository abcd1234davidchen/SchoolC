#include<iostream>
using namespace std;
int main(){
    double remain,interest,expenses;
    cin>>remain>>interest>>expenses;
    if((1-expenses)*(1+interest)>1){
        cout<<"RICH";
    }
    else{
        int month=0;
        expenses=remain*expenses;
        while (remain>0)
        {
            remain-=expenses;
            cout<<"after spend:"<<remain<<endl;
            if(remain<0) break;
            remain=remain*(1+interest);
            cout<<"after interest"<<remain<<endl;
            month+=1;
        }
        cout<<month;
    }
}
