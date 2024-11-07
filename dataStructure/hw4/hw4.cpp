//Author: 陳展皝 B123245006
//Date: Oct. 1, 2024
//Purpose: 

#include <iostream>
#include <iomanip>
using namespace std;

int directions[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};   //set directions

class knight{
    private:
        int location[2];        //current location
        int n;                  //the size of board
    public:
        knight(int border){     //constructor
            location[0]=0;      //initialie location to be 0,0
            location[1]=0;
            n=border;           //set n to boarder;
        }

        bool push(int** board,int step,int d = 0){
            int newLocation[2] = {location[0]+directions[d][0],location[1]+directions[d][1]};
            //set the new location based on direction
            if (step > n*n){
                return true;
            }
            //if exceed max return true
            if (d == 8){
                return false;
            }
            //if exceed 7 step return false
            if (newLocation[0]<n && newLocation[0]>=0 && newLocation[1]<n && newLocation[1]>=0 && board[newLocation[0]][newLocation[1]] == 0){
            //check if the new location is empty
                board[newLocation[0]][newLocation[1]]=step; //set the new location to step count
                location[0] = newLocation[0];               //set location to new location
                location[1] = newLocation[1];
                if (push(board,step+1)){                    //try next step, if true return true
                    return true;
                }
                board[newLocation[0]][newLocation[1]]=0;    //else clean the new location and return to the last one
                location[0] = newLocation[0]-directions[d][0];
                location[1] = newLocation[1]-directions[d][1];
            }
            return push(board,step,d+1);                    //try another direction
        }
};

void printBoard(int** board, int n){    //output the board
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<board[i][j];
        }
        cout<<endl;
    }
}

int main(){
    for(int n=1;n<=6;n++){          //try all 6
        cout<<n<<":"<<endl;
        knight player(n);           //initialize with boarder
        
        int** board = new int*[n];  //create board
        for(int i=0;i<n;i++){
            board[i] = new int[n]();
        }
        
        board[0][0] = 1;            //set 0,0 to 1

        if (player.push(board, 2)) {    //try from step 2
            printBoard(board, n);       //if possible print board
        }
        else {
            cout << "no solution" << endl;  //else print no solution
        }

        for (int i = 0; i < n; i++) {   //clear memory after use
            delete[] board[i];
        }
        delete[] board;
    }
}
