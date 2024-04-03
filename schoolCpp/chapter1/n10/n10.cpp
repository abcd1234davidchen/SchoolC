#include<iostream>
using namespace std;
int main(){
    int time;
    double speed;
    cin>>speed>>time;
    cout<<(speed/3600)*1609.344<<"m/s"<<speed*time<<"miles";
}
