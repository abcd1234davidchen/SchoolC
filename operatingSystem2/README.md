# OS Assignment: CPU Scheduling Algorithms
In this assignment, the following algorithms are implemented as requested: Preemptive SJF, RR scheduling + nonpreemptive priority, Multilevel feedback queue. An additional algorithm that never appeared in textbook required for this assignment, which I chose CFS, is done also.
## Shared Idea
The code starts from generating a set of processes. The algorithms are sharing a part of code, and are all trying to solve the same set of processes. The processes all have waiting queue and pops the process when done, the metadata of running the algorithm is then passed into a queue and prints out the info and gantt. 
## Preemptive SJF
The algorithm sorts the processes with the burst time and start deducting the burst time of process at the front
## RR + nonpreemptive 
The algorithm sorts the processes with the priority, and pushes the processes in a queue of the highest priority, and solves from the queue.
## Multilevel Feedback Queue
The algorithm stores which level it is right now, and runs according to the level.
## CFS
The algorithm is used by Linux, the idea behind it is to ensure every process gets the same CPU time. For achieving this,`vruntime` stores the CPU runtime, and runs the process with least runtime. Priority could be done by modifying the rule of adding runtime, with higher priority, runtime adds less. Last, to avoid excessive context switch, a minimize runtime is introduced.
### Advantage
The algorithm avoids starvation and prevent processes from waiting a long time until any runtime.