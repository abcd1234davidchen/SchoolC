#include<iostream>
using namespace std;
//3min 4mph add4min 2mph

double burnt(int speed,int weight, int duration){
    double output=0.0175*weight*duration*10/6*speed;
    cout<<"err"<<output<<endl;
    return output;
}

int main(){
    int speed=4,weight,duration=15;
    double calories;
    cin>>weight;
    calories=burnt(speed,weight,3);
    duration-=3;

    while (duration>0)
    {
        duration-=4;
        speed+=2;
        calories+=burnt(speed,weight,4);
    }
    cout<<calories;
}
