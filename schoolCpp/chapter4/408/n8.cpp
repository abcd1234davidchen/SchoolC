#include<iostream>
using namespace std;

void input(double& kilogram, double& gram){
    cin>>kilogram>>gram;
    kilogram+=gram/1000;
}

void kiloToPound(double& pound,double& kilogram,double& ounce){
    pound=kilogram*2.2046;
    ounce=pound*16;
}

void output(double pound,double ounce){
    pound=(int)pound;
    ounce-=16*pound;
    cout<<pound<<" pound and "<<ounce<<" ouncees";
}

int main(){
    double pound,ounce,kilogram,gram;
    input(kilogram,gram);
    kiloToPound(pound,kilogram,ounce);
    output(pound,ounce);
}
