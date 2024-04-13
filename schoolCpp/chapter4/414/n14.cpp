#include<iostream>
using namespace std;

int inputTime(){
    int time,minute,hour;
    cin>>time;
    minute=time%100;
    hour=time/100;
    return hour*60+minute;
}

int minuteBetween(int fromTime, int toTime){
    if(fromTime<=toTime) return toTime-fromTime;
    else return toTime-fromTime+1440;
}

int main(){
    int fromTime, toTime;
    cout<<"Input time to start";
    fromTime=inputTime();
    cout<<"Input time to stop";
    toTime=inputTime();
    cout<<"The minute between is "<<minuteBetween(fromTime,toTime);
}
