#include <iostream>
using namespace std;

int main(){
    srand(time(0));
    int guy[4];
    for(int i=0;i<4;i++){
        guy[i]=rand()%10+1;
        bool repeat = true;
        while(repeat){
            repeat=false;
            for(int j=0;j<i;j++){
                if(guy[i]==guy[j]){
                    repeat=true;
                    guy[i]=rand()%10+1;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<guy[i]<<" ";
    }
}