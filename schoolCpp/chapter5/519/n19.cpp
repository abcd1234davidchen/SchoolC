#include<iostream>
#include<cstring>
using namespace std;

int check(char player[],char players[][30],int fill){
    for(int i=0;i<fill;i++){
        if(strcmp(player,players[i])==0) return i;
    }
    return -1;
}

void add(int scores[],char players[][30],int& fill){
    int score;
    char player[30];
    if(fill<10){
        cin>>score>>player;
        scores[fill]=score;
        strncpy(players[fill],player,30);
        fill++;
    }
}

void render(int scores[],char players[][30],int fill){
    for(int i=0;i<fill;i++){
        cout<<scores[i]<<" "<<players[i]<<endl;
    }
}

void remove(int scores[],char players[][30],int& fill){
    char player[30];
    cin>>player;
    int num=check(player,players,fill);
    if(num==-1){
        cout<<"No Such"<<endl;
    }
    else{
        for(int i=num;i<fill;i++){
            scores[i]=scores[i+1];
            strcpy(players[i],players[i+1]);
        }
        fill-=1;
    }
}

void view(int scores[],char players[][30],int fill){
    char player[30];
    cin>>player;
    int num=check(player,players,fill);
    if(num==-1){
        cout<<"No Such"<<endl;
    }
    else{
        cout<<scores[num]<<" "<<players[num]<<endl;
    }
}

int main(){
    int scores[10],fill=0,mode;
    char players[10][30];
    while(1){
        cout<<"add/render/remove/view"<<endl;
        cin>>mode;
        switch(mode){
            case 1:
                add(scores,players,fill);
            break;
            case 2:
                render(scores,players,fill);
            break;
            case 3:
                remove(scores,players,fill);
            break;
            case 4:
                view(scores,players,fill);
            break;
        }
    }
}
