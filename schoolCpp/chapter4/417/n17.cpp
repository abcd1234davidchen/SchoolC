#include<iostream>
#include<fstream>
using namespace std;

double avgScore(){
    ifstream avgFile;
    avgFile.open("score.txt");
    int currentScore,amount=0,totalScore=0;
    string currentName;
    while(avgFile>>currentName>>currentScore){
        totalScore+=currentScore;
        amount+=1;
    }
    avgFile.close();
    return totalScore*1.0/amount;
}

void find(){
    string guy;
    cin>>guy;
    ifstream in;
    in.open("score.txt");
    int currentScore;
    string currentName;
    bool found=false;
    while(in>>currentName>>currentScore){
        if (currentName==guy){
            cout<<currentName<<" scores "<<currentScore;
            if((currentScore*1.0)>avgScore()){
                cout<<" higher than average"<<endl;
            }
            else{
                cout<<" lower tha average"<<endl;
            }
            found=true;
        }
    }
    if(!found){
        cout<<"NO SUCH GUY"<<endl;
    }
}

int main(){
    while(1){
        find(); 
    }
}
