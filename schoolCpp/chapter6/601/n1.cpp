#include<iostream>
using namespace std;

struct employees{
    int C;
    int P;
    int I;
    double score;
    int rate;
};

void totalScore(employees& guy){
    guy.score=guy.C*1.0*0.5+guy.P*1.0*0.3+guy.I*1.0*0.2;
}

void rate(employees& guy){
    if(guy.score>=80){
        guy.rate=1;
    }
    else if(guy.score>=60){
        guy.rate=2;
    }
    else if(guy.score>=50){
        guy.rate=3;
    }
    else{
        guy.rate=4;
    }
    cout<<guy.rate;
}

int main(){
    employees guy;
    cin>>guy.C>>guy.P>>guy.I;
    totalScore(guy);
    rate(guy);
}
