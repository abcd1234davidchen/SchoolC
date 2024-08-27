#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<81;i++){
        cout<<i/9+1<<'*'<<i%9+1<<'='<<(i%9+1)*(i/9+1)<<' ';
        if(i%3==2){
            cout<<endl;
        }
        if(i%9==8){
            cout<<endl;
        }
    }

    int a=4,b=5;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<b;
}
