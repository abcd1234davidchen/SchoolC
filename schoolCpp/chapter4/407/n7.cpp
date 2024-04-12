#include<iostream>
using namespace std;

void input(double& pound, double& ounce){
    cin>>pound>>ounce;
    pound+=ounce/16;
}

void poundToKilo(double& pound,double& kilogram,double&gram){
    kilogram=pound/2.2046;
    gram=kilogram*1000;
}

void output(double kilogram,double gram){
    kilogram=(int)kilogram;
    gram-=kilogram*1000;
    cout<<kilogram<<" kilogram and "<<gram<<" g";
}

int main(){
    double pound,ounce,kilogram,gram,feet,inch,meter,centi;
    input(pound,ounce);
    poundToKilo(pound,kilogram,gram);
    output(kilogram,gram);
}
