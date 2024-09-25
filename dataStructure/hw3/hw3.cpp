#include <iostream>
#include<iomanip>
using namespace std;

int directions[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

struct node{
    int location[3];
    node* next;
};

class knight{
    private:
        node* top;
    public:
        knight(){
            top = new node;
            top->location[0]=0;
            top->location[1]=0;
            top->location[2]=0;
            top->next = nullptr;
        }

        bool push(int **board,int d,int step){
            int newI = top->location[0]+directions[d][0];
            int newJ = top->location[1]+directions[d][1];
            if (newI>=5 || newI <0 || newJ>=5 || newJ <0){
                return false;
            }
            if(board[newI][newJ] == 0){
                
                board[newI][newJ] = step;
                node* newNode = new node;
                newNode->location[0] = newI;
                newNode->location[1] = newJ;
                newNode->location[2] = d;
                newNode->next = top;
                top = newNode;
                cout<<"I"<<newI<<"J"<<newJ<<endl;
                return true;
            }
            else{
                //cout<<"NOT OK"<<endl;
                return false;
            }
        }

        int pop(int **board){
            board[top->location[0]][top->location[1]] = 0;
            int rt = top->location[2];
            top = top->next;
            return rt;
        }
};

void printBoard(int** board){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<setw(3)<<board[i][j];
        }
        cout<<endl;
    }
}

int main(){
    knight player;
    
    int** board = new int*[5];
    for(int i=0;i<5;i++){
        board[i] = new int[5]();
    }
    
    board[0][0] = 1;

    int time = 2;
    int pop = 0;
    while(time<=25){
        bool flag = false;
        for(int j=pop;j<8;j++){
            if(player.push(board,j,time)){
                cout<<"PUSH"<<time<<endl;
                flag = true;
                pop = 0;
                break;
            }
        }
        if(!flag){
            time -= 1;
            cout<<"POP"<<time<<endl;
            if(time==1){
                cout<<"FAIL";
                break;
            }
            pop = player.pop(board)+1;
        }
        else time+=1;
    }

    printBoard(board);
    for (int i = 0; i < 5; i++) {
        delete[] board[i];
    }
    delete[] board;
}
