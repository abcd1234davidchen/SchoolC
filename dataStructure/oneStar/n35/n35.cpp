#include <iostream>
using namespace std;

int GCD(int one,int two){
    if(two==0) return one;
    else return GCD(two,one%two);
}

int main(){
    int N;
    while(cin>>N,N!=0){
        int G=0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                G+=GCD(i,j);
            }
        }
        cout<<G<<endl;
    }
}
