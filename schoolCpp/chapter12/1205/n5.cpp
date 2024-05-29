#include<iostream>
#include<fstream>
using namespace std;

int main(){
    srand(time(0));

    ofstream out;
    out.open("test.txt");
    for(int i=0;i<rand()%100;i++){
        out<<3+i*4<<" ";
        if(rand()%5==0){
            out<<rand()%100<<" ";
        }
    }
    out.close();

    ifstream in;
    in.open("test.txt");
    out.open("mod.txt");
    int i=0,num;
    while(in>>num){
        if(num==3+i*4){
            out<<num<<" ";
            i++;
        }
        else break;
    }
}