#include<iostream>
using namespace std;
int main(){
    bool prime;
    for(int i=3;i<=100;i++){
        prime=true;
        for(int check=2;check<=(i-1);check++){
            if((i%check)==0) prime=false;
        }
        if(prime) cout<<i<<endl;
    }
}