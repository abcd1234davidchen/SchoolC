#include <iostream>
using namespace std;

int step(int x, int y){
    int step = (x+y)*(x+y+1)/2;
    step+=x;
    return step;
}

int main(){
    int t,sX,sY,x,y;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>sX>>sY>>x>>y;
        cout<<"Case "<<i+1<<": "<<step(x,y)-step(sX,sY)<<endl;
    }
}