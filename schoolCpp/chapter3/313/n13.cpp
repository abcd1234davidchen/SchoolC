#include<iostream>
using namespace std;

int randomNum(){
    return rand()%25+1;
}

int main(){
    srand(time(0));
    int finalists[4];
    bool repeat;
    for(int i=0;i<4;i++){
        finalists[i]=randomNum();
        repeat=false;
        do{
            if(repeat){
                finalists[i]=randomNum();
                repeat=false;
            }
            for(int j=0;j<i;j++){
                if(finalists[i]==finalists[j]){
                    repeat=true;
                }
            }
        }
        while(repeat);
    }
    for(int i=0;i<4;i++){
        cout<<finalists[i]<<endl;
    }
}
