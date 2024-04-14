#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("test.txt");
    string digit;
    int leading[10]={0};
    while(in>>digit){
        leading[digit[0]-'0']++;
    }
    
    for(int i=1;i<=9;i++){
        cout<<i<<" "<<leading[i]<<endl;
    }

}
