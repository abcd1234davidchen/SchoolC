#include<iostream>
using namespace std;

int main(){
    string one,two,three;
    string whole;
    getline(cin,whole);
    
    int firstWhite=whole.find(' ');
    int lastWhite=whole.rfind(' ');
    
    one = whole.substr(0, firstWhite);
    if(firstWhite != lastWhite){
        two = whole.substr(firstWhite + 1, lastWhite - firstWhite - 1);
        three = whole.substr(lastWhite + 1);
        cout<<three<<", "<<one<<" "<<two[0]<<".";
    }
    else {
        three = whole.substr(firstWhite + 1);
        cout<<three<<", "<<one;
    }
}