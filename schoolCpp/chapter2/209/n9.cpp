#include<iostream>
using namespace std;
int main(){
    double n,r,guess,firstguess;
    cin>>n;
    guess=n/2;
    do
    {
        firstguess=guess;
        r=n/guess;
        guess=(guess+r)/2;
    } while (firstguess/guess>1.01);
    cout<<guess;
}