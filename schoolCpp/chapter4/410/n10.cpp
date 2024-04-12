#include<iostream>
using namespace std;
//ptk
void inputPound(double& pound, double& ounce){
    cin>>pound>>ounce;
    pound+=ounce/16;
}

void poundToKilo(double& pound,double& kilogram,double&gram){
    kilogram=pound/2.2046;
    gram=kilogram*1000;
}

void outputKilo(double kilogram,double gram){
    kilogram=(int)kilogram;
    gram-=kilogram*1000;
    cout<<kilogram<<" kilogram and "<<gram<<" g";
}
//ktp
void inputKilo(double& kilogram, double& gram){
    cin>>kilogram>>gram;
    kilogram+=gram/1000;
}

void kiloToPound(double& pound,double& kilogram,double& ounce){
    pound=kilogram*2.2046;
    ounce=pound*16;
}

void outputPound(double pound,double ounce){
    pound=(int)pound;
    ounce-=16*pound;
    cout<<pound<<" pound and "<<ounce<<" ouncees";
}
//pack
void poundTokilo(double& pound,double& ounce,double& kilo,double& gram){
    inputPound(pound,ounce);
    poundToKilo(pound,kilo,gram);
    outputKilo(kilo,gram);
}

void kiloToPound(double& pound,double& ounce,double& kilo,double& gram){
    inputKilo(kilo,gram);
    kiloToPound(pound,kilo,ounce);
    outputPound(pound,ounce);
}
//itm
void inputFeet(double& feet, double& inch){
    cin>>feet>>inch;
    feet+=inch/12;
}

void feetToMeter(double& feet,double& meter,double&centi){
    meter=0.3048*feet;
    centi=meter*100;
}

void outputMeter(double meter,double centi){
    meter=(int)meter;
    centi-=meter*100;
    cout<<meter<<" meter and "<<centi<<" cm";
}
//mti
void inputMeter(double& meter, double& centi){
    cin>>meter>>centi;
    meter+=centi/100;
}

void meterToFeet(double& feet,double& meter,double& inch){
    feet=meter/0.3048;
    inch=feet*12;
}

void outputFeet(double feet,double inch){
    feet=(int)feet;
    inch-=feet*12;
    cout<<feet<<"feet and "<<inch<<"inches";
}
//pack
void feetToMeter(double& feet,double& inch,double& meter,double& centi){
    inputFeet(feet,inch);
    feetToMeter(feet,meter,centi);
    outputMeter(meter,centi);
}

void meterToFeet(double& feet,double& inch,double& meter,double& centi){
    inputMeter(meter,centi);
    meterToFeet(feet,meter,inch);
    outputFeet(feet,inch);
}
//seperate
void convertWeight(){
    int mode;
    double pound,ounce,kilo,gram;
    cin>>mode;
    
    if(mode==1){
        cout<<"PTK";
        poundTokilo(pound,ounce,kilo,gram);
    }
    else{
        cout<<"KTP";
        kiloToPound(pound,ounce,kilo,gram);
    }
}
void convertHeight(){
    int mode;
    double feet,inch,meter,centi;
    cin>>mode;
    if(mode==1){
        cout<<"FTM";
        feetToMeter(feet,inch,meter,centi);
    }
    else{
        cout<<"MTF";
        meterToFeet(feet,inch,meter,centi);
    }
}

int main(){
    int mode;
    cin>>mode;
    if(mode==1){
        cout<<"HEI";
        convertHeight();
    }
    else{
        cout<<"WEI";
        convertWeight();
    }
}
