#include<iostream>
using namespace std;

int main(){
    string ipt;
    while(getline(cin,ipt)){
        bool type1 = true;
        for(int i=0;i<ipt.size();i++){
            if(ipt[i]=='"'){
                if(type1){
                    cout<<"``";
                    type1 = false;
                }
                else{
                    cout<<"\"\"";
                    type1 = true;
                }
            }
            else cout<<ipt[i];
        }
    }
}