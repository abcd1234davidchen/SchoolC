#include<iostream>
using namespace std;

void input(double& feet, double& inch){
    cin>>feet>>inch;
    feet+=inch/12;
}

void centimeter(double& feet,double& meter,double&centi){
    meter=0.3048*feet;
    centi=meter*100;
}

void output(double meter,double centi){
    cout<<meter<<"meter"<<centi<<"cm";
}

int main(){
    double feet,inch,meter,centi;
    input(feet,inch);
    centimeter(feet,meter,centi);
    output(meter,centi);
}
