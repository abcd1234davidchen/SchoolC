
#include <iostream>
using namespace std;

int count(const int &ipt){
    int theOne = ipt;
    int rtcount = 1;
    while(theOne!=1){
        if (theOne%2==0){
            theOne/=2;
        }
        else{
            theOne*=3;
            theOne+=1;
        }
        rtcount+=1;
        //cout<<"NUM"<<theOne<<endl;
    }
    return rtcount;
}

int main() {
    int one,two,max;
    while(cin>>one){
        cin>>two;
        max = 0;
        for(int i=one;i<=two;i++){
            if(max<count(i)) max = count(i);
        }
        cout<<max<<endl;
    }
}