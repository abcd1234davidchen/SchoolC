#include<iostream>
using namespace std;

int main(){
    int s,d,t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s>>d;
        int one,two;
        one = (s+d)/2;
        two = s-one;
        if((s+d)%2!=0||two<0||one<0){
            cout<<"impossible"<<endl;
        }
        else{
            cout<<one<<" "<<two<<endl;
        }
    }
}
