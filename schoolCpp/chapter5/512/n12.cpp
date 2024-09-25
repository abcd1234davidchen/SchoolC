#include<iostream>
#include<unistd.h>
using namespace std;

const int horizontal = 80;//-
const int vertical = 20;//|

int neighbor(int table[][vertical],int hor,int ver){
    int amount=0;
    if(hor==0){
        if(ver==0){
            amount+=table[hor][ver+1];//5
            amount+=table[hor+1][ver];//7
            amount+=table[hor+1][ver+1];//8
        }
        else if(ver==vertical-1){
            amount+=table[hor][ver-1];//4
            amount+=table[hor+1][ver-1];//6
            amount+=table[hor+1][ver];//7
        }
        else{
            amount+=table[hor][ver-1];//4
            amount+=table[hor][ver+1];//5
            amount+=table[hor+1][ver-1];//6
            amount+=table[hor+1][ver];//7
            amount+=table[hor+1][ver+1];//8
        }
    }
    else if(hor==horizontal-1){
        if(ver==0){
            amount+=table[hor-1][ver];//2
            amount+=table[hor-1][ver+1];//3
            amount+=table[hor][ver+1];//5
        }
        else if(ver==vertical-1){
            amount+=table[hor-1][ver-1];//1
            amount+=table[hor-1][ver];//2
            amount+=table[hor][ver-1];//4
        }
        else{
            amount+=table[hor-1][ver-1];//1
            amount+=table[hor-1][ver];//2
            amount+=table[hor-1][ver+1];//3
            amount+=table[hor][ver-1];//4
            amount+=table[hor][ver+1];//5
        }
    }
    else if(ver==0){
        amount+=table[hor-1][ver];//2
        amount+=table[hor-1][ver+1];//3
        amount+=table[hor][ver+1];//5
        amount+=table[hor+1][ver];//7
        amount+=table[hor+1][ver+1];//8
        }
    else if(ver==vertical-1){
        amount+=table[hor-1][ver-1];//1
        amount+=table[hor-1][ver];//2
        amount+=table[hor][ver-1];//4
        amount+=table[hor+1][ver-1];//6
        amount+=table[hor+1][ver];//7
        }
    else{
        //123
        //4 5
        //678
        amount+=table[hor-1][ver-1];//1
        amount+=table[hor-1][ver];//2
        amount+=table[hor-1][ver+1];//3
        amount+=table[hor][ver-1];//4
        amount+=table[hor][ver+1];//5
        amount+=table[hor+1][ver-1];//6
        amount+=table[hor+1][ver];//7
        amount+=table[hor+1][ver+1];//8
    }
    return amount;
}

void generation(int table[][vertical]){
    int newTable[horizontal][vertical];
    for(int i=0;i<horizontal;i++){
        for(int j=0;j<vertical;j++){
            int nei=neighbor(table,i,j);
            if(nei==3 || (nei==2 && table[i][j]==1)){
                newTable[i][j]=1;
            }
            else{
                newTable[i][j]=0;
            }
        }
    }
    for(int i=0;i<horizontal;i++){
        for(int j=0;j<vertical;j++){
            table[i][j] = newTable[i][j];
        }
    }    
}

void render(int table[][vertical]){
    system("clear");
    for(int i=0;i<vertical;i++){
        for(int j=0;j<horizontal;j++){
            if(table[j][i]) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}

void initalize(int table[][vertical]){
    for(int i=0;i<vertical;i++){
        for(int j=0;j<horizontal;j++){
            table[j][i]=((rand()%5)>2);
        }
    }
}

int main(){
    srand(time(0));
    int table[horizontal][vertical]={{0}};
    initalize(table);
    render(table);
    cout<<"--------"<<endl;
    while(1){
        generation(table);
        render(table);
        usleep(50*1000);
        cout<<"--------"<<endl;
    }
}
