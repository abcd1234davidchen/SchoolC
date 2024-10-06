#include <iostream>
#include <string>
using namespace std;

int main(){
    string ipt;
    while(cin>>ipt,ipt!="0"){
        int cvt=0;
        for(size_t i=0;i<ipt.size();i++){
            cvt+=(ipt[i]-'0');
        }
        if(cvt%9==0){
            int process = 1;
            while(cvt!=9){
                process+=1;
                int temp=0;
                while(cvt>0){
                    temp+=cvt%10;
                    cvt/=10;
                }
                cvt = temp;
            }
            cout<<ipt<<" is a multiple of 9 and has 9-degree "<<process<<"."<<endl;
        }
        else{
            cout<<ipt<<" is not a multiple of 9."<<endl;
        }
    }
}
