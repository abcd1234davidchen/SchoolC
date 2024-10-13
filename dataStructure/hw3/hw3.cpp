//Author: 陳展皝 B123245006
//Date: Sept. 25, 2024
//Purpose: make the knight chess piece to walk in a n*n board using stack to memorize

#include <iostream>
#include <iomanip>
using namespace std;

int directions[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
//Define directions possible for the knight to move

struct node{            //Define datas for each node to push in stack
    int location[3];    //Each node includes three data: (i,j) and which direction
    node* next;         //Connect to next node
};

class knight{           //stack class
    private:
        node* top;      //The top node which connects to all the nodes
    public:
        knight(){       //Initailize the Knight
            top = new node;         //The top node is set to be new
            top->location[0]=0;     //Set the initalize location to be (0,0)
            top->location[1]=0;
            top->location[2]=-1;     //set direction to be not existed
            top->next = nullptr;    //set next to be null
        }

        bool push(int **board,int d,int step,int n){
            //push funciton that takes four parameters: the board, the direction, step count, and boarder
            top->location[2] = d;                           //make the current node's direction to be setted
            int newI = top->location[0]+directions[d][0];   //make the next move based on directions and current i,j
            int newJ = top->location[1]+directions[d][1];
            if (newI>=n || newI <0 || newJ>=n || newJ <0){  //if it exceeds the boarder return false
                return false;
            }
            if(board[newI][newJ] == 0){         //if the new location has nothing yet
                board[newI][newJ] = step;       //push the current step into board
                node* newNode = new node;       //set a new node that contains current data
                newNode->location[0] = newI;    //including (i,j) and no direction
                newNode->location[1] = newJ;
                newNode->location[2] = -1;
                newNode->next = top;            //set the next node to be current top node
                top = newNode;                  //set top node to be the node just created
                return true;                    //return true meaning it succeed
            }
            else{
                return false;                   //return false if the new location has something already
            }
        }

        int pop(int **board){                   //take in board as parameter
            board[top->location[0]][top->location[1]] = 0;  //set the location of last node to be 0
            node* temp = top;                   //make a temp pointer to node to delete it later
            top = top->next;                    //make the next node to be new top node
            delete temp;
            return top->location[2];            //return the direction of the current node that fail
        }
};

void printBoard(int** board, int n){            //print board function taking board and boarder as parameter
    for(int i=0;i<n;i++){                       //print each number with width of 3
        for(int j=0;j<n;j++){
            cout<<setw(3)<<board[i][j];
        }
        cout<<endl;
    }
}

int main(){
    for(int n=1;n<=6;n++){
        knight player;                  //set a new stack

        int** board = new int*[n];      //set n*n board
        for(int i=0;i<n;i++){
            board[i] = new int[n]();
        }
        board[0][0] = 1;                //set (0,0) to be 1

        int time = 2;                   //set the next number to push in to be 2
        int pop = 0;                    //make it start with direction 0
        bool work = true;               //a bool to identify if n works
        while(time<=n*n){               //make it work through n*n numbers
            bool flag = false;          //flag to remember if any step was taken
            for(int j=pop;j<8;j++){     //go through 8 directions
                if(player.push(board,j,time,n)){    //if any works
                    flag = true;        //set it true as something worked
                    pop = 0;            //pop to zero making the next step start from direction 0
                    break;              //break the loop
                }
            }
            if(!flag){                  //if none of step was taken
                time -= 1;              //work on last step 
                if(time==1){            //if last step is 1
                    work = false;       //the board doesn't work
                    break;              //break the loop
                }
                pop = player.pop(board)+1;  //pop and start the direction to be the original+1
            }
            else time+=1;               //work on next step
        }
        cout<<n<<":"<<endl;             //print n:
        if(work){                       //if works print board
            printBoard(board,n);
        }
        else{                           //else print no solution
            cout<<"no solution"<<endl;
        }
        for (int i = 0; i < n; i++) {   //delete the board after use
            delete[] board[i];
        }
        delete[] board;
        cout<<endl;
    }
}
