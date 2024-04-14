#include<iostream>
using namespace std;

void generate(int table[][4]){
    int horizontal,vertical;
    for(int i=1;i<=8;i++){
        for(int j=0;j<2;j++){
            while(1){
                horizontal=rand()%4;
                vertical=rand()%4;
                if(table[horizontal][vertical]==0){
                    table[horizontal][vertical]=i;
                    break;
                }
            }
        }
    }
}

void render(int table[][4],int show[][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(show[j][i]) cout<<table[j][i]<<" ";
            else cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl<<endl;
}

void onePlay(int table[][4],int show[][4]){
    int x1,y1,x2,y2;
    cin>>x1>>y1;
    x1-=1;
    y1-=1;
    while(show[x1][y1]==1){
        cin>>x1>>y1;
        x1-=1;
        y1-=1;
    }
    show[x1][y1]=1;
    render(table,show);
    cin>>x2>>y2;
    x2-=1;
    y2-=1;
    while(show[x2][y2]==1){
        cin>>x2>>y2;
        x2-=1;
        y2-=1;
    }
    show[x2][y2]=1;
    render(table,show);
    if(table[x1][y1]!=table[x2][y2]){
        show[x1][y1]=0;
        show[x2][y2]=0;
    }
    else{
        cout<<"Nice"<<endl;
    }
}

bool gameOver(int show[][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(show[i][j]==0) return false;
        }
    }
    return true;
}

int main(){
    srand(time(0));
    int table[4][4]={{0}};
    int show[4][4]={{0}};
    int peak[4][4]={{0}};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            peak[i][j]=1;
        }
    }
    generate(table);
    render(table,peak);
    render(table,show);
    while(!gameOver(show)){
        onePlay(table,show);
    }
    cout<<"WIN!"<<endl;
}
