#include<iostream>
using namespace std;
// input gram/mice/human output gram divide 0.001

int main(){
    const double percentage=0.001;
    double gram,mice,human;
    cout<<"input as following grams/mice/human";
    cin>>gram>>mice>>human;
    cout<<gram*(human/mice)/percentage;
}
