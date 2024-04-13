#include<iostream>
using namespace std;

int input(int taken[]){
    int num;
    cin>>num;
    while(1){
        if(taken[num-1]==0&&num>0&&num<=9) return num;
        else{
            cout<<"invalid"<<endl;
            cin>>num;
        }
    }
}

void draw(char ttt[],char ox,int taken[]){
    int num=input(taken);
    taken[num-1]+=1;    
    ttt[num-1]=ox;
}

void render(char ttt[]){
    for(int i=0;i<9;i++){
        cout<<ttt[i]<<" ";
        if(i%3==2) cout<<endl;
    }
}

int gameOver(char ttt[],char ox,int taken[]){
    for(int row=0;row<3;row++){
        if(ttt[row]==ox&&ttt[row+3]==ox&&ttt[row+6]==ox) return 1;
    }
    for(int column=0;column<7;column+=3){
        if(ttt[column]==ox&&ttt[column+1]==ox&&ttt[column+2]==ox) return 1;
    }
    if(ttt[0]==ox&&ttt[4]==ox&&ttt[8]==ox){
        return 1;
    }
    if(ttt[2]==ox&&ttt[4]==ox&&ttt[6]==ox){
        return 1;
    }
    for(int i=0;i<9;i++){
        if(taken[i]==0){
            return 0;
        }
    }
    return 2;
}

int main(){
    char ttt[9]={'1','2','3','4','5','6','7','8','9'};
    int taken[9]={0};
    render(ttt);
    while(1){
        draw(ttt,'o',taken);
        render(ttt);
        if(gameOver(ttt,'o',taken)){
            if(gameOver(ttt,'o',taken)==2){
                cout<<"DRAW"<<endl;
            }
            else{
                cout<<"o wins"<<endl;
            }
            break;
        }
        draw(ttt,'x',taken);
        render(ttt);
        if(gameOver(ttt,'x',taken)){
            cout<<"x wins"<<endl;
            break;
        }
    }
}
