#include<iostream>
using namespace std;

void makeArray(int graph[]){
    int total=0,one;
    cin>>one;
    while(1){
        total+=one;
        cin>>one;
        if(one==-1){
            break;
        }
    }
    total/=1000;
    for(int i=0;i<total;i++){
        graph[i]=1;
    }

}

void render(int graph[][15]){
    for(int i=0;i<15;i++){
        for(int j=0;j<4;j++){
            if(graph[j][14-i]==0){
                cout<<" ";
            }
            else cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int graph[4][15]={{0}};
    for(int i=0;i<4;i++){
        cout<<"for "<<i+1<<endl;
        makeArray(graph[i]);
    }
    render(graph);
    
}
