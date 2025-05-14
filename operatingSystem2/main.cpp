#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

struct process{
    int identification;
    int arrival_time;
    int burst_time;
    int priority;
};

bool compareProcessArrival(const process& A,const process& B){
    return A.arrival_time<B.arrival_time;
}

void init(vector<process>& processes){
    for(int i=0;i<10;i++){
        processes.push_back({i,(rand()%3)*5,rand()%23+6,rand()%3+1});
    }
    sort(processes.begin(),processes.end(),compareProcessArrival);
    for(size_t i=0;i<10;i++){
        cout<<processes[i].identification<<" "<<processes[i].arrival_time<<" "
            <<processes[i].burst_time<<" "<<processes[i].priority<<endl;
    }
}

void preSJF(){

}

void npRR(){

}

void multilevelQueue(){

}

void custom(){

}

int main(){
    srand(time(0));
    vector<process> processes;
    init(processes);
}