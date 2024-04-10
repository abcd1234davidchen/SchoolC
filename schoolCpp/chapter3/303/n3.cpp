#include<iostream>
using namespace std;
double nextYear(double currentYear, double rate){
    return currentYear*=(1+rate);
}

double yearsLater(double currentYear, double rate, int years){
    double totalIncrease=1;
    for(int i=0;i<years;i++){
        totalIncrease*=(1+rate);
    }
    return currentYear*=totalIncrease;
}

int main(){
    double currentYear,lastYear,rate;
    int years;
    while(1){
        cout<<"current/last"<<endl;
        cin>>currentYear>>lastYear;
        rate=(currentYear-lastYear)/lastYear;
        cout<<rate*100<<"%"<<endl;
        cout<<"Next year would be "<<nextYear(currentYear,rate)<<endl<<"How many years later?"<<endl;
        cin>>years;
        cout<<yearsLater(currentYear,rate,years)<<endl;
    }
}
