#include<iostream>
#include"TwoD.h"

using namespace std;

int main(){
    
    TwoD one;
    one.setValue(0,0,1);
    one.setValue(0,1,2);
    one.setValue(0,2,3);
    one.setValue(1,1,4);
    cout<<one;
    TwoD two(4,3);
    cout<<two;
    cout<<two*one;
}
