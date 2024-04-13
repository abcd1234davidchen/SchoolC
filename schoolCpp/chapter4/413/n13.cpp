#include<iostream>
using namespace std;

double convertToMPH(int minute,int second){
    second+=60*minute;
    return 1.0*3600/second;
}

double convertToMPH(double kph){
    return kph*1.0/1.61;
}

int main(){
    cout<<convertToMPH(5,30)<<endl<<convertToMPH(1.61);
}
