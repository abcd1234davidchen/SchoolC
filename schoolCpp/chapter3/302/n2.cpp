#include<iostream>
using namespace std;
int main(){
    double currentYear,lastYear,rate;
    while(1){
        cout<<"current/last"<<endl;
        cin>>currentYear>>lastYear;
        rate=(currentYear-lastYear)/lastYear;
        cout<<rate*100<<"%"<<endl;
    }
}
