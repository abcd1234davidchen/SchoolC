



#include <iostream>
#include <iomanip>
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

        bool push(int **board,int d,int step,int n){
            
            int newI = top->location[0]+directions[d][0];   
            int newJ = top->location[1]+directions[d][1];
            if (newI>=n || newI <0 || newJ>=n || newJ <0){  
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
                return true;                    
            }
            else{
                return false;                   
            }
        }

        int pop(int **board){                   
            board[top->location[0]][top->location[1]] = 0;  
            int rt = top->location[2];          
            node* temp = top;
            top = top->next;
            delete temp;
            return rt;
        }
};

void printBoard(int** board, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<board[i][j];
        }
        cout<<endl;
    }
}

int main(){
    for(int n=8;n<=8;n++){
        knight player;

        int** board = new int*[n];
        for(int i=0;i<n;i++){
            board[i] = new int[n]();
        }
        board[0][0] = 1;

        int time = 2;
        int pop = 0;
        bool work = true;
        while(time<=n*n){
            bool flag = false;
            for(int j=pop;j<8;j++){
                if(player.push(board,j,time,n)){
                    flag = true;
                    pop = 0;
                    break;
                }
            }
            if(!flag){
                time -= 1;
                if(time==1){
                    work = false;
                    break;
                }
                pop = player.pop(board)+1;
            }
            else time+=1;
        }
        cout<<n<<":"<<endl;
        if(work){
            printBoard(board,n);
        }
        else{
            cout<<"no solution"<<endl;
        }
        for (int i = 0; i < n; i++) {
            delete[] board[i];
        }
        delete[] board;
        cout<<endl;
    }
}
