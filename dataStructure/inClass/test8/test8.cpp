#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <chrono>
#include <sys/resource.h>

using namespace std;

void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cout << "Memory usage: " << usage.ru_maxrss << " KB" << endl;
}

int direction[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};


class pos{
    private:
        pos *child;
        pos *parent;
        vector<int*> nextmoves;

        int k;
        int posx;
        int posy;

        int maxsize;
        vector< vector <int> > board;
    public:
        pos(int num, int x, int y, pos *p, int s, const vector< vector <int> >& b)
            : k(num), posx(x), posy(y), parent(p), maxsize(s), board(b) {
            possiblemove();
        }
        ~pos(){
            for(int* move: nextmoves){
                delete[] move;
            }
            nextmoves.clear();

            for(auto& row: board){
                row.clear();
            }
            board.clear();
        }
        
        bool movevalid(int x,int y,int size){
            if(x>=0 && x<size && y>=0 && y<size && board[x][y]==0){
                return true;
            }
            return false;
        }
        void possiblemove(){
            vector<int*> moves;

            for(int i=0;i<8;i++){
                int *move = new int[2];
                move[0] = posx+direction[i][0];
                move[1] = posy+direction[i][1];
                if(movevalid(move[0],move[1],maxsize)){
                    moves.push_back(move);
                }else{
                    delete[] move;
                }
            }
            nextmoves = moves;
        }
        
        void setchild(pos *c){
            child = c;
        }
        int* getnextmove() {
            if (nextmoves.empty()) {
                return nullptr;
            }
            int* nextmove = nextmoves[0];
            nextmoves.erase(nextmoves.begin());
            return nextmove;
        }
        
        pos* getchild(){
            return child;
        }
        pos* getparent(){
            return parent;
        }

        tuple <int, int> getpos(){
            return make_tuple(posx,posy);
        }
};



int main() {
    int size;
    cin >> size;
    auto start = chrono::high_resolution_clock::now();

    vector< vector <int> > mainboard(size,vector<int>(size));

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            mainboard[i][j] = 0;
        }
    }
    mainboard[0][0] = 1;
    pos *root = new pos(1,0,0,nullptr,size,mainboard);
    pos *now = root;
    pos *next = nullptr;

    int *nextpos;
    for(int i=2;i<=size*size;i++){
            if(i<2){
                cout << "No solution" << endl;
                //printMemoryUsage();
                return 0;
            }
            nextpos = now->getnextmove();  // get the next possible move
            if(nextpos == nullptr ){
                int x,y;
                tie(x,y)=now->getpos(); // get the position of the current node
                mainboard[x][y] = 0; // mark the position as unvisited

                pos* temp = now;
                now->setchild(nullptr);  // remove the child node
                now = now->getparent();  // go back to the parent node
                i-=2; // go back 2 steps
                delete temp;
                continue;
            }else{
                //cout << "K=" << i << "  "<< nextpos[0] << " / " << nextpos[1] << endl;   
                next = new pos(i,nextpos[0],nextpos[1],now,size,mainboard); // create a new node
                now->setchild(next); // set the child node
                now = next; // move to the child node
                mainboard[nextpos[0]][nextpos[1]] = i; // mark the position as visited
            }
            
    }

    now->setchild(nullptr);
    cout << "Finish" << endl;
    now = root;


    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << setw(3) <<mainboard[i][j] << " ";
        }
        cout << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Time Usage: " << elapsed.count() << " seconds" << endl;

    printMemoryUsage();
    return 0;
}
