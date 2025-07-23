#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

struct process{
    int identification;
    int arrival_time;
    int burst_time;
    int priority;
};

struct algoMetadata{ // The metadata for algorithm to run
    string name;
    int contextSwitch;
    map<int,int> completionTime;
    map<int,int> arrivalCopy;
    map<int,int> burstCopy;
    deque<int> currentProcess;
};

void draw(deque<int> gantt,bool showDigit = true){
    // Draw function for only one process
    cout<<"0 1 2 3 4 5 6 7 8 9"<<endl<<"-------------------"<<endl;
    for(size_t i=0;i<gantt.size();i++){
        for(int j=0;j<gantt[i];j++){
            cout<<"  ";
        }
        cout<<(gantt[i]>=0?(showDigit ? to_string(gantt[i]) : "█"):"")<<endl;
    }
}

deque<deque<int>> gantts; //keep track of all gantts to draw later

void multipleDraw(bool showDigit = true){
    // Draw processes side by side according to number of algorithms
    cout<<"time";
    for(size_t i=0;i<gantts.size();i++){
        cout<<"|0 1 2 3 4 5 6 7 8 9";
    }
    cout<<endl<<"    ";
    for(size_t i=0;i<gantts.size();i++){
        cout<<"|-------------------";
    }
    cout<<endl;
    for(size_t i=0;i<gantts[0].size();i++){
        cout<<right<<setw(4)<<i;
        for(size_t j=0;j<gantts.size();j++){
            for(size_t k=0;k<10;k++){
                cout<<((k==0)?"|":" ")<<((gantts[j][i]!=static_cast<int>(k))?" ":(showDigit ? to_string(gantts[j][i]) : "█"));
            }
        }
        cout<<endl;
    }
}

void algoShare(algoMetadata algo){
    //Take info about algorithm and format the print
    cout<<algo.name<<endl<<"Context Switch Times:"<<algo.contextSwitch<<endl;
    //The waiting time is complete-arrival-burst
    int waitSum = algo.completionTime[0]-algo.arrivalCopy[0]-algo.burstCopy[0];
    cout<<"Waiting Time: ("<<algo.completionTime[0]<<"-"
        <<algo.arrivalCopy[0]<<"-"<<algo.burstCopy[0]<<")";
    for(int i=1;i<static_cast<int>(algo.completionTime.size());i++){
        cout<<"+("<<algo.completionTime[i]<<"-"
            <<algo.arrivalCopy[i]<<"-"<<algo.burstCopy[i]<<")";
        waitSum+=algo.completionTime[i]-algo.arrivalCopy[i]-algo.burstCopy[i];
    }
    cout<<"="<<waitSum<<endl;
    //The turnaround time is complete-arrival
    int turnSum = algo.completionTime[0]-algo.arrivalCopy[0];
    cout<<"Turnaround Time: ("<<algo.completionTime[0]<<"-"<<algo.arrivalCopy[0]<<")";
    for(int i=1;i<static_cast<int>(algo.completionTime.size());i++){
        cout<<"+("<<algo.completionTime[i]<<"-"<<algo.arrivalCopy[i]<<")";
        turnSum+=algo.completionTime[i]-algo.arrivalCopy[i];
    }
    cout<<"="<<turnSum<<endl;
    
    gantts.push_back(algo.currentProcess);
    // draw(algo.currentProcess);
}

bool compareProcessArrival(const process& A,const process& B){
    return A.arrival_time<B.arrival_time;
}

void init(deque<process>& processes){
    for(int i=0;i<10;i++){
        processes.push_back({i,(rand()%3)*5,rand()%23+6,rand()%3+1});
    }
    //The process is sorted with the arrival time
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
    
    //keep track of completion time and keep a copy of arrival and burst time
    map<int,int> completionTime;
    map<int,int> arrivalCopy;
    map<int,int> burstCopy;
    for(size_t i=0;i<processes.size();i++){
        arrivalCopy[processes[i].identification] = processes[i].arrival_time;
        burstCopy[processes[i].identification] = processes[i].burst_time;
    }
    //Quit when all is done
    while(!processes.empty()||!waitingQueue.empty()){
        //Insert when the time has arrived and sort by time left
        while (!processes.empty() && processes.front().arrival_time <= currentSecond) {
            waitingQueue.push_back(processes.front());
            processes.pop_front();
        }
        sort(waitingQueue.begin(),waitingQueue.end(),compareBurstTime);
        //If the queue is not empty, delete process burst time by one
        if(!waitingQueue.empty()){
            int dealingProcess = waitingQueue.front().identification;
            //If it switches add context switch time
            if(!currentProcess.empty()&&currentProcess.back()!=dealingProcess){
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
            //Push back -1 if no process is in queue but not finish
            currentProcess.push_back(-1);
        }
        currentSecond++;
    }

    //Do the share part
    algoShare({"Preemptive SJF",
                contextSwitch,completionTime,
                arrivalCopy,burstCopy,currentProcess});
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
    
    //keep track of completion time and keep a copy of arrival and burst time
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
        //Insert when the time has arrived and sort by priority
        while (!processes.empty() && processes.front().arrival_time <= currentSecond) {
            waitingQueue.push_back(processes.front());
            processes.pop_front();
        }
        sort(waitingQueue.begin(),waitingQueue.end(),comparePriority);

        if(!waitingQueue.empty()){
            //Check the current priority
            if(currentPriority==0){
                currentPriority=waitingQueue.front().priority;
            }
            //Renew if priority is incorrect
            if(currentPriority>waitingQueue.front().priority){
                //Dump back to waiting queue
                for(auto process:priorityQueue){
                    waitingQueue.push_back(process);
                    priorityQueue.pop_front();
                }
                //Add highest priority to priority queue
                for(auto process:waitingQueue){
                    if(process.priority==currentPriority){
                        priorityQueue.push_back(process);
                        waitingQueue.pop_front();
                    }
                }
            }
            //Find if there is new undone process
            else if(currentPriority==waitingQueue.front().priority){
                for(auto process:waitingQueue){
                    if(process.priority==currentPriority){
                        priorityQueue.push_back(process);
                        waitingQueue.pop_front();
                    }
                }
            }
        }
        //If it is not empty
        if(!priorityQueue.empty()){
            int dealingProcess = priorityQueue.front().identification;
            if(!currentProcess.empty()&&currentProcess.back() != dealingProcess){
                contextSwitch++;
            }
            //Deduct burst time of priority queue and add quantum
            currentProcess.push_back(dealingProcess);
            quantum+=1;
            priorityQueue.front().burst_time-=1;
            if(priorityQueue.front().burst_time<=0){
                completionTime[dealingProcess]=1+currentSecond;
                priorityQueue.pop_front();
                quantum=0;
                //Move to next priority if current is done
                if(priorityQueue.empty()) currentPriority=0;
            }
            //If quantum is 5 push to last
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

    algoShare({"RR + Nonpreemptive Priority",
                contextSwitch,completionTime,
                arrivalCopy,burstCopy,currentProcess});
}

void mulFQ(deque<process> processes){
    int currentSecond = 0;
    deque<process> waitingQueue;
    deque<process> rejoinQueue;
    deque<int> currentProcess;
    int contextSwitch=0;
    
    //keep track of completion time and keep a copy of arrival and burst time
    //Also quantum and current queue
    map<int,int> completionTime;
    map<int,int> arrivalCopy;
    map<int,int> burstCopy;
    int quantum=0;
    int currentQueue=1;
    
    for(size_t i=0;i<processes.size();i++){
        arrivalCopy[processes[i].identification] = processes[i].arrival_time;
        burstCopy[processes[i].identification] = processes[i].burst_time;
    }

    while(!processes.empty()||!waitingQueue.empty()||!rejoinQueue.empty()){
        //Push into waiting queue
        while (!processes.empty() && processes.front().arrival_time <= currentSecond) {
            waitingQueue.push_back(processes.front());
            processes.pop_front();
        }

        if(!waitingQueue.empty()){
            int dealingProcess = waitingQueue.front().identification;
            if(!currentProcess.empty()&&currentProcess.back() != dealingProcess){
                contextSwitch++;
            }
            currentProcess.push_back(dealingProcess);
            quantum+=1;
            waitingQueue.front().burst_time-=1;
            //Throw away process when done
            if(waitingQueue.front().burst_time<=0){
                completionTime[dealingProcess]=1+currentSecond;
                waitingQueue.pop_front();
                quantum=0;
            }
            //Move to rejoin queue if undone in a period
            else if((currentQueue==1&&quantum==5)||(currentQueue==2&&quantum==10)){
                rejoinQueue.push_back(waitingQueue.front());
                waitingQueue.pop_front();
                quantum=0;
            }
            //Move from rejoin queue back and move to next queue
            if(waitingQueue.empty()){
                for(auto process:rejoinQueue){
                    waitingQueue.push_back(process);
                    rejoinQueue.pop_front();
                }
                currentQueue+=1;
            }
        }
        else{
            currentProcess.push_back(-1);
        }
        currentSecond++;
    }

    algoShare({"Multilevel feedback queue",
                contextSwitch,completionTime,
                arrivalCopy,burstCopy,currentProcess});
}

void sortWQByVrt(deque<process>& waitingQueue, const map<int, int>& vruntime) {
    //Sort based on vruntime
    vector<process> temp(waitingQueue.begin(), waitingQueue.end());
    sort(temp.begin(), temp.end(), [&](const process& a, const process& b) {
        return vruntime.at(a.identification) < vruntime.at(b.identification);
    });
    waitingQueue = deque<process>(temp.begin(), temp.end());
}

void CFS(deque<process> processes){
    int currentSecond = 0;
    deque<process> waitingQueue;
    deque<int> currentProcess;
    int contextSwitch=0;
    int processRuntime=0;
    int dealingProcess=0;
    
    //Keep track of vruntime additionally
    map<int,int> vruntime;
    map<int,int> completionTime;
    map<int,int> arrivalCopy;
    map<int,int> burstCopy;
    for(size_t i=0;i<processes.size();i++){
        arrivalCopy[processes[i].identification] = processes[i].arrival_time;
        burstCopy[processes[i].identification] = processes[i].burst_time;
    }
    while(!processes.empty()||!waitingQueue.empty()){
        while (!processes.empty() &&
                processes.front().arrival_time <= currentSecond) {
            waitingQueue.push_back(processes.front());
            vruntime[processes.front().identification] = 0;
            processes.pop_front();
        }
        //Do sort only after five quantum
        if(processRuntime==0 || processRuntime>4){
            sortWQByVrt(waitingQueue,vruntime); 
            if(!waitingQueue.empty()&&dealingProcess!=waitingQueue.front().identification){
                contextSwitch+=1;
                processRuntime=0;
                dealingProcess = waitingQueue.front().identification;
            }
        }
        //Add vruntime according to priority
        if(!waitingQueue.empty()){
            vruntime[dealingProcess]+=waitingQueue.front().priority;
            processRuntime+=1;
            currentProcess.push_back(dealingProcess);
            waitingQueue.front().burst_time-=1;
            //move to next if done
            if( waitingQueue.front().burst_time<=0){
                completionTime[dealingProcess]=1+currentSecond;
                waitingQueue.pop_front();
                vruntime.erase(dealingProcess);
                processRuntime=0;
            }
        }
        else{
            currentProcess.push_back(-1);
        }
        currentSecond++;
    }

    algoShare({"CFS",
                contextSwitch,completionTime,
                arrivalCopy,burstCopy,currentProcess});
}

int main(){
    srand(static_cast<unsigned int>(time(0)));
    deque<process> processes;
    init(processes);
    preSJF(processes);
    cout<<endl<<endl;
    npRR(processes);
    cout<<endl<<endl;
    mulFQ(processes);
    cout<<endl<<endl;
    CFS(processes);
    cout<<endl<<endl;
    multipleDraw();
}