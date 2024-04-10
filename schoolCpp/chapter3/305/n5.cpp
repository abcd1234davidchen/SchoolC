#include<iostream>
using namespace std;

double hatSize (double weight, double height){
    return (weight/height)*2.9;
}

double jacketSize(double weight,double height,int age){
    if(age<=30) return(height*weight)/288;
    else return(height*weight)/(288+(age-30)/10)*0.125;
}

double waist(double weight,int age){
    if(age<=28) return(weight)/5.7;
    else return(weight)/5.7+0.1*((age-28)/2);
}

int main(){
    double weight,height;
    int age;
    while(1){
        cin>>weight>>height>>age;
        cout<<"hat"<<hatSize(weight,height)<<endl<<"jacket"<<jacketSize(weight,height,age)<<endl<<"waist"<<waist(weight,age);
    }
}
