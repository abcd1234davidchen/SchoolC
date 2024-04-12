#include<iostream>
using namespace std;

double squareroot(double n){
    double r,guess,firstguess;
    guess=n/2;
    do
    {
        firstguess=guess;
        r=n/guess;
        guess=(guess+r)/2;
    } while (firstguess/guess>1.01);
    return guess;
}

int main(){
    double n;
    cin>>n;
    cout<<squareroot(n);
}
