#include<iostream>
#include<fstream>

using namespace std;

int main(){
    srand(time(0));

    ofstream out;
    out.open("test.txt");
    for(int i=0;i<100;i++){
        out<<rand()%500<<endl;
    }

    ifstream in;
    in.open("test.txt");
    int num;
    while(in>>num){
        bool isPrime=true;
        if(num<2){
            isPrime=false;
        }
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                isPrime=false;
            }
        }
        if(isPrime){
            cout<<num<<endl;
        }
    }
}
