#include<iostream>
#include<fstream>
using namespace std;

void getHighestScore(int scores[],char names[][20]){
    int tempInt;
    char tempStr[20];

    for(int i=0;i<4;i++){
        for(int j=0;j<4-i;j++){
            if(scores[j]<scores[j+1]){
                tempInt=scores[j];
                scores[j]=scores[j+1];
                scores[j+1]=tempInt;
                for(int k=0;k<20;k++){
                    tempStr[k]=names[j][k];
                    names[j][k]=names[j+1][k];
                    names[j+1][k]=tempStr[k];
                }
            }
        }
    }
}

int main(){
    ifstream in;
    in.open("score.txt");
    int scores[5],currentScore,i=0;
    char names[5][20],currentName[20];
    while(in>>currentName>>currentScore){
        scores[i]=currentScore;
        for(int j=0;j<20;j++){
            names[i][j]=currentName[j];
        }
        i+=1;
    }
    getHighestScore(scores,names);
    for(i=0;i<5;i++){
        cout<<names[i]<<scores[i]<<endl;
    }
}
