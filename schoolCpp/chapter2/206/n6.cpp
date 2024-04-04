#include<iostream>
using namespace std;
int main(){
    double r,weight;
    const double v=62.4;
    cin>>r>>weight;
    if(4/3*3.14*r*r*r*v>weight){
        cout<<"floats";
    }
    else{
        cout<<"sink";
    }
}
