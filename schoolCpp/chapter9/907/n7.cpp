#include<iostream>
#include<cctype>
using namespace std;

int main(){
    string in;
    bool caplocked;
    while(1){
        cin>>in;
        caplocked=false;
        if(islower(in[0])){
            caplocked=true;
            for(size_t i=1;i<in.size();i++){
                if(islower(in[i])){
                    caplocked=false;
                    break;
                }
            }
        }
        if(caplocked){
            cout<<(char)toupper(in[0]);
            for(size_t i=1;i<in.size();i++){
                cout<<(char)tolower(in[i]);
            }
        }
    }
}
