#include<iostream>
using namespace std;

int main(){
    int n,one;
    while(cin>>n){
        vector <int> in;
        vector <int> btw;
        bool jolly = true;
        for(int i=0;i<n;i++){
            cin>>one;
            in.push_back(one);
        }
        for(int i=1;i<n;i++){
            btw.push_back(abs(in[i-1]-in[i]));
        }
        sort(btw.begin(),btw.end());
        for(int i=0;i<n-1;i++){
            if(btw[i]!=i+1){
                jolly = false;
                break;
            }
        }
        cout<<jolly<<endl;
    }  
}