#include<iostream>
#include<fstream>

using namespace std;
int main(){
    ifstream in;
    in.open("text.txt");
    string firstName,lastName;
    int feet,inch,ideal;
    while (in>>firstName>>lastName>>feet>>inch)
    {
        feet-=5;
        ideal=110+(12*feet+inch)*5;
        cout<<firstName<<" "<<lastName<<"'s ideal weight is "<<ideal<<endl;
    }
    
}
