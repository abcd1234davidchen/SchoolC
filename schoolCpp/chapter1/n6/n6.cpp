#include<iostream>

using namespace std;
int main(){
    int duration, distance;
    double fee;

    //input kilometers and minute
    cin>>distance>>duration;
    if(distance<=2){
        fee=2;
    }
    else if(distance<=8){
        fee=2+0.5*(distance-2);
    }
    else{
        fee=5+distance-8;
    }

    fee+=0.2*duration;
    cout<<fee;
}