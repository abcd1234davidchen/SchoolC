#include <iostream>
using namespace std;
int gcd(int one,int two){
    if (two==0) return one;
    else return gcd(two,one%two);
}

int main(){
    int one,two;
    cin>>one>>two;
    cout<<gcd(one,two)<<endl;
    cout<<one*two/gcd(one,two)<<endl;
}