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

int main(){
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
