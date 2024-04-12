#include<iostream>
using namespace std;

void input (int& hour,int& minute){
    cin>>hour>>minute;
}

void convert (int& hour,bool& am){
    if(hour>12){
        hour-=12;
        am=false;
    }
}

void output (int& hour,int& minute, bool&am){
    if(am){
        cout<<hour<<":"<<minute<<"AM";
    }
    else{
        cout<<hour<<":"<<minute<<"PM";
    }
    cout<<endl;
}

int main(){
    int hour,minute;
    bool am;
    while(1){
        input(hour,minute);
        //cout<<hour<<minute;
        am=true;
        convert(hour,am);
        output(hour,minute,am);
    }   
}
