#include<iostream>
#include<fstream>
using namespace std;

class players{
    private:
        string name;
        int score;
    public:
        void setName(string x){
            name=x;
        }
        void setScore(int x){
            score=x;
        }
        string outName(){
            return name;
        }
        int outScore(){
            return score;
        }
};

void getHighestScore(players playerArr[]){
    players temp;

    for(int i=0;i<4;i++){
        for(int j=0;j<4-i;j++){
            if(playerArr[j].outScore()<playerArr[j+1].outScore()){
                temp=playerArr[j];
                playerArr[j]=playerArr[j+1];
                playerArr[j+1]=temp;
            }
        }
    }
}

int main(){
    ifstream in;
    in.open("score.txt");
    players playerArr[5];
    string name;
    int score;
    int i=0;
    while(in>>name>>score){
        playerArr[i].setName(name);
        playerArr[i].setScore(score);
        i+=1;
    }
    getHighestScore(playerArr);
    for(i=0;i<5;i++){
        cout<<playerArr[i].outName()<<playerArr[i].outScore()<<endl;
    }
}
