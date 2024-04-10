#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int list[10],inputNum,i=0;
    ifstream in;
    in.open("test.txt");
    while (in>>list[i])
    {
        i++;
    }
    bool find=false;
    cin>>inputNum;
    for(i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(list[i]+list[j]==inputNum){
                find=true;
                cout<<"NUM1 "<<list[i]<<" NUM2 "<<list[j]<<endl;
            }
        }
    }
    if(!find) cout<<"Not a shit";
}
