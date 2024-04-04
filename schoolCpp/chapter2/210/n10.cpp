#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in;
    in.open("text.txt");
    if(in.fail()){
        cout<<"FAIL";
    }
    while(!in.eof()){
        string inText;
        in>>inText;
        if(inText=="hate"){
            cout<<"love"<<" ";
        }
        else{
            cout<<inText<<" ";
        }
    }
    in.close();
    
}
