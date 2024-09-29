#include<iostream>
using namespace std;

int main(){
    int one,two;
    while(cin>>one>>two,one!=0||two!=0){
        int count = 0;
        for(int i=one;i<=two;i++){
            for(int j=0;j*j<=i;j++){
                if (j*j==i){
                    count+=1;
                }
            }
        }
        cout<<count<<endl;
    }
}