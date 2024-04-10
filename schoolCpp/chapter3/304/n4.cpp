#include<iostream>
using namespace std;

const double GRAVITY=6.673/100000000;

double force(double m1,double m2, double distance){
    return GRAVITY*m1*m2/distance/distance;
}

int main(){
    double m1,m2,distance;
    cin>>m1>>m2>>distance;
    cout<<force(m1,m2,distance);
}
