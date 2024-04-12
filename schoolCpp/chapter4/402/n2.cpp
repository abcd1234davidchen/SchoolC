#include<iostream>
using namespace std;

const double pi = 3.14159;

void calculate (double radius, double& area, double& circumference){
    area=pi*radius*radius;
    circumference=pi*2*radius;
}

int main(){
    double radius,area,circumference;
    cin>>radius;
    calculate(radius,area,circumference);
    cout<<area<<endl<<circumference;
}
