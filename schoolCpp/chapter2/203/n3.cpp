#include<iostream>
using namespace std;
int main(){
    int child,money;
    cin>>money>>child;
    cout<<money/child<<" kids "<<money%child<<" left "<<child-money%child<<" more for one more kid";
}