#include<iostream>
using namespace std;

void tableOutput(int speed[],int theory[],int real[],int size){
    for(int i=0;i<size;i++){
        cout<<"At Speed "<<speed[i]<<" Drained "<<real[i]<<" In theory should be "<<theory[i];
        if(real[i]<theory[i]) cout<<" better than expected"<<endl;
        else cout<<" worse than expected"<<endl;
    }
}

void graphOutput(int speed[],int theory[],int real[],int size){
    for(int i=0;i<size;i++){
        cout<<"At speed "<<speed[i]<<endl<<"Theory/Real"<<endl;
        for(int j=0;j<theory[i];j++){
            cout<<"*";
        }
        cout<<endl;
        for(int j=0;j<real[i];j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int speed[10]={10,20,30,40,50,60,70,80,90,100};
    int theory[10]={1,2,3,4,5,6,7,8,9,10};
    int real[10]={2,1,4,3,6,5,8,7,10,9};

    tableOutput(speed,theory,real,10);
    graphOutput(speed,theory,real,10);
}
