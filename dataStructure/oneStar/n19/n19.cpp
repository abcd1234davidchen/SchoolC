#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int lead,trail;
        cin>>lead>>trail;
        int s=0;
        for(int i=lead;i<=trail;i++){
            if(i%2==1) s+=i;
        }
        cout<<"Case "<<j+1<<": "<<s<<endl;
    }
}
