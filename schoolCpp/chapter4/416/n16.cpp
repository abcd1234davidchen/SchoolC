#include<iostream>
#include<fstream>
using namespace std;

void getHighestScore(int curScor,string curNam,int& higScor,string& higNam){
    if(curScor>higScor){
        higScor=curScor;
        higNam=curNam;
    }
}

int main(){
    ifstream in;
    in.open("score.txt");
    int highestScore,currentScore;
    string highestName,currentName;
    while(in>>currentName>>currentScore){
        getHighestScore(currentScore,currentName,highestScore,highestName);
    }
    cout<<highestName<<" "<<highestScore;
}
