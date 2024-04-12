#include<iostream>
using namespace std;



void inputFeet(double& feet, double& inch){
    cin>>feet>>inch;
    feet+=inch/12;
}

void toMeter(double& feet,double& meter,double&centi){
    meter=0.3048*feet;
    centi=meter*100;
}

void outputMeter(double meter,double centi){
    cout<<meter<<"meter"<<centi<<"cm";
}

void inputMeter(double& meter, double& centi){
    cin>>meter>>centi;
    meter+=centi/100;
}

void toFeet(double& feet,double& meter,double& inch){
    feet=meter/0.3048;
    inch=feet*12;
}

void outputFeet(double feet,double inch){
    cout<<feet<<"feet or "<<inch<<"inches";
}

void feetToMeter(double& feet,double& inch,double& meter,double& centi){
    inputFeet(feet,inch);
    toMeter(feet,meter,centi);
    outputMeter(meter,centi);
}

void meterToFeet(double& feet,double& inch,double& meter,double& centi){
    inputMeter(meter,centi);
    toFeet(feet,meter,inch);
    outputFeet(feet,inch);
}
int main(){
    int mode;
    double feet,inch,meter,centi;
    cin>>mode;
    if(mode==1){
        feetToMeter(feet,inch,meter,centi);
    }
    else{
        meterToFeet(feet,inch,meter,centi);
    }
}
