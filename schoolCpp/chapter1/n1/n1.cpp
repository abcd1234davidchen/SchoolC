#include<iostream>

using namespace std;
//1 gallon = 3785.41 ml, read package ml convert to gallons, how much package is one gallon

int n1(){
    double ml, gallonPacket;
    cout<<"How much Milileter is in one packet ";
    cin>>ml;
    gallonPacket=ml/3785.41;
    cout<<gallonPacket<<" gallon per packet "<<endl<<1/gallonPacket<<" packet is one gallon";
}
