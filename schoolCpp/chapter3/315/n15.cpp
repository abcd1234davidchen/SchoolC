#include<iostream>
#include<fstream>
using namespace std;

double survive(){
    return 1.0*rand()/RAND_MAX;
}

int main(){
    srand(time(0));
    ifstream in;
    in.open("input.txt");
    if(in.fail()){
        cout<<"BAD";
    }

    double expect[2][120],die,live;
    int age;

    int currentAge;
    bool alive,male;
    
    cin>>male>>currentAge;
    alive=true;
    while(in>>age>>expect[0][age-1]>>expect[1][age-1]){
        if(age>currentAge){
            if(male) die=expect[0][age-1];
            else die=expect[1][age-1];
            live=survive();
            cout<<"live percent"<<live<<"at age"<<age<<endl;
            if(live>die){
                cout<<"SURVIVE"<<endl;
                continue;
            }
            else{
                alive=false;
                break;
            }
        }
    }
    if(alive){
        cout<<"pass 120";
    }
    else{
        cout<<"Die at age"<<age;
    }
}
