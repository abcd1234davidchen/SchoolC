#include<iostream>
using namespace std;
int main(){
    int floor;
    double base,amentities,tax;
    cin>>base>>floor>>amentities>>tax;
    for(int i=0;i<floor;i++){
        cout<<base<<" base "<<base*amentities<<" amentities "<<(base*amentities+base)*tax<<" tax "<<endl;
        base*=1.02;
    }
}
