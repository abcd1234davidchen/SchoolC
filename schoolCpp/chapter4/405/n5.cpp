#include<iostream>
using namespace std;

void input(double& meter, double& centi){
    cin>>meter>>centi;
    meter+=centi/100;
}

void toFeet(double& feet,double& meter,double& inch){
    feet=meter/0.3048;
    inch=feet*12;
}

void output(double feet,double inch){
    cout<<feet<<"feet or "<<inch<<"inches";
}

int main(){
    double feet,inch,meter,centi;
    input(meter,centi);
    toFeet(feet,meter,inch);
    output(feet,inch);
}
