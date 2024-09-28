#include<iostream>
using namespace std;

int main(){
    int starting,days;
    while(cin>>starting>>days){
        int count=0;
        while(count<days){
            count += starting;
            starting+=1;
        }
        cout<<starting-1<<endl;
    }
}