#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpos);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<setw(10)<<123.456<<endl;
}