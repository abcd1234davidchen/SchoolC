#include<iostream>
using namespace std;

int gcd(int one, int two) {
    while (two != 0) {
        int temp = two;
        two = one % two;
        one = temp;
    }
    return one;
}

bool convertLowerestTerms(int& numerator,int& denominator){
    int theGCD;
    if(denominator==0) return false;
    else{
        theGCD=gcd(numerator,denominator);
        //cout<<theGCD;
        numerator/=theGCD;
        //cout<<"NUMER"<<numerator;
        denominator/=theGCD;
        //cout<<denominator;
        return true;
    }
}

int main(){
    int numerator,denominator;
    while(1){
        cin>>numerator>>denominator;
        if(convertLowerestTerms(numerator,denominator)) cout<<numerator<<" and "<<denominator<<endl;
        else cout<<"INVALID"<<endl;
    }
}
