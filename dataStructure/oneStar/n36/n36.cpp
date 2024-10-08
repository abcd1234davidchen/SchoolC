#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n,q;
        cin>>m>>n>>q;
        cout<<m<<" "<<n<<" "<<q<<" "<<endl;
        char** arr = new char*[m];
        for(int j=0;j<m;j++){
            arr[j] = new char[n];
        }
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin>>arr[j][k];
            }
        }
        for(int l=0;l<q;l++){
            int r,c;
            cin>>r>>c;
            int boarder = min(min(r, c), min(m-1-r, n-1-c));
            while(boarder>0){
                bool flag = true;
                for(int j=r-boarder;j<r+boarder;j++){
                    for(int k=c-boarder;k<c+boarder;k++){
                        if(arr[j][k]!=arr[r][c]){
                            //cout<<"JK"<<j<<k;
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(flag){
                    break;
                }
                boarder-=1;
            }
            if (boarder < 0) boarder = 0;
            cout<<boarder*2+1<<endl;
        }
        for(int j=0;j<m;j++){
            delete[] arr[j];
        }
        delete[] arr;
    }
}
