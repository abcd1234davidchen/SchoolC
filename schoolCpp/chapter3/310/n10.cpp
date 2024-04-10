#include<iostream>
using namespace std;

double height(bool male,double father,double mother){
    if(male){
        return ((1.0*mother*13/12)+father)/2;
    }
    else{
        return ((1.0*father*12/13)+mother)/2;
    }
}

int main(){
    bool male;
    double father,mother;
    string sex;
    cin>>sex>>father>>mother;
    if(sex=="Boy") male=true;
    else male=false;
    cout<<height(male,father,mother);
}
