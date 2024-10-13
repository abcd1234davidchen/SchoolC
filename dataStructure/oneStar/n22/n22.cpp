#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int one,two;
    while(cin>>one>>two,one!=0||two!=0){
        int count = 0;
        for(int i=one;i<=two;i++){
            if(sqrt(i)==int(sqrt(i))) count+=1;
        }
        cout<<count<<endl;
    }
}
