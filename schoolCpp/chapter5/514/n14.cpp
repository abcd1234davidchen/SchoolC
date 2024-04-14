#include<iostream>
using namespace std;

double dist(int expert,int score[][6],int user[]){
    int total=0;
    for(int i=0;i<6;i++){
        if(user[i]!=0){
            total+=(score[expert][i]-user[i])*(score[expert][i]-user[i]);
        }
    }
    return sqrt(1.0*total);
}

int findExpert(int score[][6],int user[]){
    int theOne=0;
    double theOneDistance=100,expertDistance;
    for(int i=0;i<4;i++){
        expertDistance=dist(i,score,user);
        //cout<<"expert "<<i<<"distances"<<expertDistance<<endl;
        if(expertDistance<theOneDistance){
            theOne=i;
            theOneDistance=expertDistance;
        }
    }
    return theOne;
}

void output(int score[][6],int user[]){
    cout<<"Pretiction!";
    int expert;
    expert=findExpert(score,user);
    for(int i=0;i<6;i++){
        if(user[i]==0){
            cout<<100+i<<" get "<<score[expert][i]<<" ";
        }
    }
}

void input(int user[]){
    int score,movie;
    for(int i=0;i<3;i++){
        cin>>score>>movie;
        movie-=100;
        user[movie]=score;
    }
}

int main(){
    while(1){
        int user[6]={0};
        int score[4][6]={{3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{5,1,4,2,4,2}};
        input(user);
        output(score,user);
    }
}
