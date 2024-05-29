#include<iostream>
#include<fstream>

using namespace std;

int main(){
    srand(time(0));

    ofstream out;
    out.open("test.txt");
    for(int i=0;i<100;i++){
        out<<(rand()%500)*1.0/(rand()%500)<<endl;
    }

    ifstream in;
    in.open("test.txt");
    double num,total=0,amount=0;
    while(in>>num){
        total+=num;
        amount++;
    }
    cout<<"Average: "<<total*1.0/amount<<endl;
}
