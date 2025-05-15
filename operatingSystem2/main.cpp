#include <iostream>
#include <deque>
#include <random>
#include <algorithm>
#include <map>
using namespace std;

struct process{
    int identification;
    int arrival_time;
    int burst_time;
    int priority;
};

//TODO: add align option
void draw(deque<int> gantt,bool showDigit = true){
    cout<<"0 1 2 3 4 5 6 7 8 9"<<endl<<"-------------------"<<endl;
    for(size_t i=0;i<gantt.size();i++){
        for(int j=0;j<gantt[i];j++){
            cout<<"  ";
        }
        cout<<(gantt[i]>=0?(showDigit ? to_string(gantt[i]) : "█"):"")<<endl;
    }
}

bool compareProcessArrival(const process& A,const process& B){
    return A.arrival_time<B.arrival_time;
}

void init(deque<process>& processes){
    for(int i=0;i<10;i++){
        processes.push_back({i,(rand()%3)*5,rand()%23+6,rand()%3+1});
    }
    sort(processes.begin(),processes.end(),compareProcessArrival);
    cout<<"Processes: "<<endl;
    for(size_t i=0;i<10;i++){
        cout<<processes[i].identification<<" "<<processes[i].arrival_time<<" "
            <<processes[i].burst_time<<" "<<processes[i].priority<<endl;
    }
    cout<<endl;
}

bool compareBurstTime(const process& A,const process& B){
    return A.burst_time<B.burst_time;
}

void preSJF(deque<process> processes){
    int currentSecond = 0;
    deque<process> waitingQueue;
    deque<int> currentProcess;
    int contextSwitch=0;
    
    map<int,int> completionTime;
    map<int,int> arrivalCopy;
    map<int,int> burstCopy;
    for(size_t i=0;i<processes.size();i++){
        arrivalCopy[processes[i].identification] = processes[i].arrival_time;
        burstCopy[processes[i].identification] = processes[i].burst_time;
    }

    while(!processes.empty()||!waitingQueue.empty()){
        while (!processes.empty() && processes.front().arrival_time <= currentSecond) {
            waitingQueue.push_back(processes.front());
            processes.pop_front();
        }
        sort(waitingQueue.begin(),waitingQueue.end(),compareBurstTime);
        if(!waitingQueue.empty()){
            int dealingProcess = waitingQueue.front().identification;
            if(!currentProcess.empty()&&currentProcess.back() != dealingProcess){
                contextSwitch++;
            }
            currentProcess.push_back(dealingProcess);
            waitingQueue.front().burst_time-=1;
            if( waitingQueue.front().burst_time<=0){
                completionTime[dealingProcess]=1+currentSecond;
                waitingQueue.pop_front();
            }
        }
        else{
            currentProcess.push_back(-1);
        }
        currentSecond++;
    }

    cout<<"Preemptive SJF"<<endl<<"Context Switch Times:"<<contextSwitch<<endl;

    int waitSum = completionTime[0]-arrivalCopy[0]-burstCopy[0];
    cout<<"Waiting Time: ("<<completionTime[0]<<"-"<<arrivalCopy[0]<<"-"<<burstCopy[0]<<")";
    for(int i=1;i<static_cast<int>(completionTime.size());i++){
        cout<<"+("<<completionTime[i]<<"-"<<arrivalCopy[i]<<"-"<<burstCopy[i]<<")";
        waitSum+=completionTime[i]-arrivalCopy[i]-burstCopy[i];
    }
    cout<<"="<<waitSum<<endl;

    int turnSum = completionTime[0]-arrivalCopy[0];
    cout<<"Turnaround Time: ("<<completionTime[0]<<"-"<<arrivalCopy[0]<<")";
    for(int i=1;i<static_cast<int>(completionTime.size());i++){
        cout<<"+("<<completionTime[i]<<"-"<<arrivalCopy[i]<<")";
        turnSum+=completionTime[i]-arrivalCopy[i];
    }
    cout<<"="<<turnSum<<endl;

    draw(currentProcess);
}

bool comparePriority(const process& A,const process& B){
    return A.priority<B.priority;
}

void npRR(deque<process> processes){
    int currentSecond = 0;
    deque<process> waitingQueue;
    deque<process> priorityQueue;
    deque<int> currentProcess;
    int contextSwitch=0;
    
    map<int,int> completionTime;
    map<int,int> arrivalCopy;
    map<int,int> burstCopy;
    int quantum=0;
    int currentPriority=0;
    
    for(size_t i=0;i<processes.size();i++){
        arrivalCopy[processes[i].identification] = processes[i].arrival_time;
        burstCopy[processes[i].identification] = processes[i].burst_time;
    }

    while(!processes.empty()||!waitingQueue.empty()||!priorityQueue.empty()){
        while (!processes.empty() && processes.front().arrival_time <= currentSecond) {
            waitingQueue.push_back(processes.front());
            processes.pop_front();
        }
        sort(waitingQueue.begin(),waitingQueue.end(),comparePriority);

        if(currentPriority==0){
            currentPriority=waitingQueue.front().priority;
        }
        if(currentPriority>waitingQueue.front().priority){
            for(auto process:priorityQueue){
                waitingQueue.push_back(process);
                priorityQueue.pop_front();
            }
            for(auto process:waitingQueue){
                if(process.priority==currentPriority){
                    priorityQueue.push_back(process);
                    waitingQueue.pop_front();
                }
            }
        }
        else if(currentPriority==waitingQueue.front().priority){
            for(auto process:waitingQueue){
                if(process.priority==currentPriority){
                    priorityQueue.push_back(process);
                    waitingQueue.pop_front();
                }
            }
        }

        if(!priorityQueue.empty()){
            int dealingProcess = priorityQueue.front().identification;
            if(!currentProcess.empty()&&currentProcess.back() != dealingProcess){
                contextSwitch++;
            }
            currentProcess.push_back(dealingProcess);
            quantum+=1;
            priorityQueue.front().burst_time-=1;
            if(priorityQueue.front().burst_time<=0){
                completionTime[dealingProcess]=1+currentSecond;
                priorityQueue.pop_front();
                quantum=0;
                if(priorityQueue.empty()) currentPriority=0;
            }
            else if(quantum==5){
                priorityQueue.push_back(priorityQueue.front());
                priorityQueue.pop_front();
                quantum=0;
            }
        }
        else{
            currentProcess.push_back(-1);
        }
        currentSecond++;
    }

    cout<<"RR + Nonpreemptive Priority"<<endl<<"Context Switch Times:"<<contextSwitch<<endl;

    int waitSum = completionTime[0]-arrivalCopy[0]-burstCopy[0];
    cout<<"Waiting Time: ("<<completionTime[0]<<"-"<<arrivalCopy[0]<<"-"<<burstCopy[0]<<")";
    for(int i=1;i<static_cast<int>(completionTime.size());i++){
        cout<<"+("<<completionTime[i]<<"-"<<arrivalCopy[i]<<"-"<<burstCopy[i]<<")";
        waitSum+=completionTime[i]-arrivalCopy[i]-burstCopy[i];
    }
    cout<<"="<<waitSum<<endl;

    int turnSum = completionTime[0]-arrivalCopy[0];
    cout<<"Turnaround Time: ("<<completionTime[0]<<"-"<<arrivalCopy[0]<<")";
    for(int i=1;i<static_cast<int>(completionTime.size());i++){
        cout<<"+("<<completionTime[i]<<"-"<<arrivalCopy[i]<<")";
        turnSum+=completionTime[i]-arrivalCopy[i];
    }
    cout<<"="<<turnSum<<endl;

    draw(currentProcess);
}

void multilevelFeedbackQueue(){

}

void custom(){

}

int main(){
    srand(static_cast<unsigned int>(time(0)));
    deque<process> processes;
    init(processes);
    // preSJF(processes);
    npRR(processes);
}