#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("test.txt");
    string digit;
    int total=0,one=0,nine=0;
    while(in>>digit){
        if(digit[0]=='1'){
            one+=1;
        }
        if(digit[0]=='9'){
            nine+=1;
        }
        total+=1;
    }
    cout<<"One takes up "<<one*1.0/total*100<<"% Nine takes up"<<nine*1.0/total*100<<"%";
}
