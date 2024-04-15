#include<iostream>
#include<cstring>
using namespace std;

class player{
    public:
        string name;
        int score;
};

int check(string ply,player plyArr[],int fill){
    for(int i=0;i<fill;i++){
        if(ply==plyArr[i].name) return i;
    }
    return -1;
}

void add(player plyArr[],int& fill){
    int score;
    string player[30];
    if(fill<10){
        cin>>plyArr[fill].score>>plyArr[fill].name;
        fill++;
    }
}

void render(player plyArr[],int fill){
    for(int i=0;i<fill;i++){
        cout<<plyArr[i].score<<" "<<plyArr[i].name<<endl;
    }
}

void remove(player plyArr[],int& fill){
    string ply;
    cin>>ply;
    int num=check(ply,plyArr,fill);
    if(num==-1){
        cout<<"No Such"<<endl;
    }
    else{
        for(int i=num;i<fill;i++){
            plyArr[i]=plyArr[i+1];
        }
        fill-=1;
    }
}

void view(player plyArr[],int fill){
    string ply;
    cin>>ply;
    int num=check(ply,plyArr,fill);
    if(num==-1){
        cout<<"No Such"<<endl;
    }
    else{
        cout<<plyArr[num].score<<" "<<plyArr[num].name<<endl;
    }
}

int main(){
    int fill=0,mode;
    player plyArr[10];
    while(1){
        cout<<"add/render/remove/view"<<endl;
        cin>>mode;
        switch(mode){
            case 1:
                add(plyArr,fill);
            break;
            case 2:
                render(plyArr,fill);
            break;
            case 3:
                remove(plyArr,fill);
            break;
            case 4:
                view(plyArr,fill);
            break;
        }
    }
}
