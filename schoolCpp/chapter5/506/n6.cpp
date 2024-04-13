#include<iostream>
using namespace std;

int main(){
    int score[3][4],sum;
    double avg[3];
    for(int i=0;i<3;i++){
        sum=0;
        cout<<"From judge"<<i+1<<endl;
        for(int j=0;j<4;j++){
            cin>>score[i][j];
            if(score[i][j]>10){
                j-=1;
                continue;
            }
            sum+=score[i][j];
        }
        avg[i]=sum*1.0/4;
    }
    for(int i=0;i<3;i++){
        cout<<"Judge "<<i+1<<" "<<avg[i]<<endl;
    }
}
