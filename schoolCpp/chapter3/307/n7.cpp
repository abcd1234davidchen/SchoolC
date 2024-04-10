#include<iostream>
#include<cmath>
using namespace std;

double dis(double x1, double x2, double y1, double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main(){
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<dis(x1,x2,y1,y2);
}
