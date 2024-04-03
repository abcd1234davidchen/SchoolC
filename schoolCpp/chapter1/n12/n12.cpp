#include<iostream>
using namespace std;
int main(){
    int feet,inch;
    cin>>feet>>inch;
    feet-=5;
    inch+=feet*12;
    cout<<110+inch*5<<"pound";
}
