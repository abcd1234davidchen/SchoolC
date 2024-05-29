#include<iostream>
#include<fstream>

using namespace std;

int main(){

    ifstream in;
    in.open("test.txt");
    double num,total=0,amount=0;
    while(in>>num){
        total+=num;
        amount++;
    }
    double avg = total*1.0/amount;
    in.close();

    in.open("test.txt");
    amount = 0;
    while(in>>num){
        amount += (num-avg)*(num-avg);
    }
    cout<<"Standard Deviation: "<<sqrt(amount/100)<<endl;
}
