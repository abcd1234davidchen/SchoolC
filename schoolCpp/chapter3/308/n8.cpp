#include<iostream>
using namespace std;

string first(int tenth){
    char str[8][10] ={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty"};
    return str[tenth];
}

string second(int oneth){
    char str[9][10] ={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    return str[oneth];
}

string underTwenty(int oneth){
    char str[9][10]={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen"};
    return str[oneth];
}

int main(){
    int tenth,oneth;
    for(int i=99;i>=0;i--){
        tenth=i/10;
        oneth=i%10;

        if(oneth==0){
            if(i==0){
                cout<<"Zero bottle"<<endl;
                break;
            }
            else if(i==10){
                cout<<"Ten bottle"<<endl;
            }
            else{
                cout<<first(tenth-2)<<"bottle"<<endl;
            }
        }
        else{
            if(i>20){
                cout<<first(tenth-2)<<"-"<<second(oneth-1)<<endl;
            }
            else if(i>10){
                cout<<underTwenty(oneth-1)<<endl;
            }
            else{
                cout<<second(oneth-1)<<endl;
            }
        }
    }
}
