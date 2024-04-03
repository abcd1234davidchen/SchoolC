#include<iostream>
using namespace std;
//1000*0.15*1.5=225 "775" face-(face*rate*(month/12))="receive"
//receive=face(1-rate*(month/12)) face=receive/(1-rate*(month/12))
int main(){
    double faceValue, interestRate, duration, receive;
    cout<<"Input the money needed, interest rate, and duration of month ";
    cin>>receive>>interestRate>>duration;
    faceValue=receive/(1-0.01*interestRate*(duration/12));
    cout<<"The face value would be "<<faceValue<<" Monthly Payment would be "<<faceValue/duration;
}
