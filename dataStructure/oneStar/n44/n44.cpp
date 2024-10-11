#include <iostream>
using namespace std;

int main(){
    int r,c,count=0;
    while(cin>>r>>c,r!=0&&c!=0){
        if(count!=0) cout<<endl;
        count+=1;
        cout<<"Field #"<<count<<":"<<endl;
        char** board = new char*[r];
        for(int i=0;i<r;i++){
            board[i]= new char[c];
        }
        char** ans = new char*[r];
        for(int i=0;i<r;i++){
            ans[i]= new char[c];
        }
        for(int i=0;i<r;i++){
            cin>>board[i];
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='*'){
                    ans[i][j]='*';
                    continue;
                }
                else{
                    ans[i][j]='0';
                }
                if(i>0&&j>0&&board[i-1][j-1]=='*') ans[i][j]++;
                if(j>0&&board[i][j-1]=='*') ans[i][j]++;
                if(i<r-1&&j>0&&board[i+1][j-1]=='*') ans[i][j]++;
                if(i>0&&board[i-1][j]=='*') ans[i][j]++;
                if(i<r-1&&board[i+1][j]=='*') ans[i][j]++;
                if(i>0&&j<c-1&&board[i-1][j+1]=='*') ans[i][j]++;
                if(j<c-1&&board[i][j+1]=='*') ans[i][j]++;
                if(i<r-1&&j<c-1&&board[i+1][j+1]=='*') ans[i][j]++;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
        for(int i = 0; i < r; i++){
            delete[] board[i];
            delete[] ans[i];
        }
        delete[] board;
        delete[] ans;
    }
}
