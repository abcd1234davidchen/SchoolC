#include<iostream>
using namespace std;

int main(){
    string ipt;
    while(cin>>ipt){
        int flat=0;
            for(size_t i=0;i<ipt.size();i++){
            flat+=(ipt[i]-'0');
        }
        //cout<<"FLAT"<<flat<<endl;
        while(flat>=10){
            int newFlat = 0;
            int processFlat = flat;
            while(processFlat>=10){
                newFlat+=processFlat%10;
                processFlat/=10;
            }
            newFlat+=processFlat%10;
            flat = newFlat;
        }
        cout<<flat<<endl;
    }
}
