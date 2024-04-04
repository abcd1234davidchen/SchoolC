#include<iostream>
using namespace std;
int main(){
    int  cel=100;

    while(1){
        if((cel*9/5+32)==cel){
            cout<<cel;
            break;
        }
        cel-=1;
    }

}
