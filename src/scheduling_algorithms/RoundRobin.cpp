#include "RoundRobin.h"
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

bool compareArrival(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

RoundRobin::RoundRobin() {}

void RoundRobin::run() {
    cout << "---------------------------------------Round Robin Algorithm------------------------------------------------" << endl;
    int processCount, timeQuantum;
    cout << "Enter time quantum: ";
    cin >> timeQuantum;
    cout << "Enter total number of processes: ";
    cin >> processCount;

    vector<Process> processes(processCount);
    for (int i = 0; i < processCount; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), compareArrival);

    int timer = 0;
    int arrivalIndex = 0;
    queue<Process*> readyQueue;

    while (true) {
        if (readyQueue.empty()) {
            if (arrivalIndex >= processCount) {
                break;
            } else if (timer >= processes[arrivalIndex].arrivalTime) {
                readyQueue.push(&processes[arrivalIndex]);
                arrivalIndex++;
            } else {
                timer++;
                continue;
            }
        }

        Process* currentProcess = readyQueue.front();
        readyQueue.pop();

        int timeSlice = 0;
        while (timeSlice < timeQuantum && currentProcess->remainingTime > 0) {
            currentProcess->remainingTime--;
            timer++;
            timeSlice++;

            if (arrivalIndex < processCount && timer >= processes[arrivalIndex].arrivalTime) {
                readyQueue.push(&processes[arrivalIndex]);
                arrivalIndex++;
            }
        }

        if (currentProcess->remainingTime > 0) {
            readyQueue.push(currentProcess);
        } else {
            currentProcess->completionTime = timer;
        }
    }

    // Calculate TAT and WT
    for (auto& proc : processes) {
        proc.turnaroundTime = proc.completionTime - proc.arrivalTime;
        proc.waitingTime = proc.turnaroundTime - proc.burstTime;
    }

    // Output the results in a table
    cout << "\nProcess ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    for (const auto& proc : processes) {
        cout << setw(10) << proc.id 
             << setw(14) << proc.arrivalTime 
             << setw(12) << proc.burstTime 
             << setw(16) << proc.completionTime 
             << setw(17) << proc.turnaroundTime 
             << setw(14) << proc.waitingTime 
             << endl;
    }
}
