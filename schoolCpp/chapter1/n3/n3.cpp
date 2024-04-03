#include<iostream>
using namespace std;

int main(){
    const double salesGain = 0.13,profitGain = 0.27;
    double currentSales,currentProfit;
    cout<<"input the current sals and profit in million ";
    cin>>currentSales>>currentProfit;
    cout<<"Gain of sales would be "<<currentSales*salesGain<<" million"<<endl<<"Gain of profit would be "
        <<currentProfit*profitGain<<" million";
}
