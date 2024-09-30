#include <iostream>
#include <iomanip>
#include <chrono>
#include <sys/resource.h>
using namespace std;

int directions[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};


class knight{
    private:
        int location[2];
        int n;
    public:
        knight(int border){
            location[0]=0;
            location[1]=0;
            n=border;
        }

        bool push(int** board,int step,int d = 0){
            int newLocation[2] = {location[0]+directions[d][0],location[1]+directions[d][1]};

            if (step > n*n){
                return true;
            }
            if (d == 8){
                return false;
            }

            if (newLocation[0]<n && newLocation[0]>=0 && newLocation[1]<n && newLocation[1]>=0 && board[newLocation[0]][newLocation[1]] == 0){
                board[newLocation[0]][newLocation[1]]=step;
                location[0] = newLocation[0];
                location[1] = newLocation[1];
                if (push(board,step+1)){
                    return true;
                }
                board[newLocation[0]][newLocation[1]]=0;
                location[0] = newLocation[0]-directions[d][0];
                location[1] = newLocation[1]-directions[d][1];
            }
            return push(board,step,d+1);
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
    knight player(n);
    
    int** board = new int*[n];
    for(int i=0;i<n;i++){
        board[i] = new int[n]();
    }
    
    board[0][0] = 1;
    auto start = chrono::high_resolution_clock::now();

    if (player.push(board, 2)) {
        printBoard(board, n);
    }
    else {
        cout << "NO" << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;

    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    printMemoryUsage();
}
