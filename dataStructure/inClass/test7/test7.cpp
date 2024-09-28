#include <iostream>
#include <iomanip>
#include <chrono>
#include <sys/resource.h>

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
                //cout<<"I"<<newI<<"J"<<newJ<<endl;
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

void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cout << "Memory usage: " << usage.ru_maxrss << " KB" << endl;
}

int main(){

    int n;
    cin>>n;
    knight player;
    
    int** board = new int*[n];
    for(int i=0;i<n;i++){
        board[i] = new int[n]();
    }
    
    board[0][0] = 1;
    auto start = chrono::high_resolution_clock::now();

    int time = 2;
    int pop = 0;
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
                cout<<"FAIL"<<endl;
                break;
            }
            pop = player.pop(board)+1;
        }
        else time+=1;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    printBoard(board,n);
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }

    delete[] board;

    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    printMemoryUsage();
}
