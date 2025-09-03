#include<bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

int main()
{
    int numberOfProcess;

    cout << "Enter total number of Process" << endl;
    cin >> numberOfProcess;

    Process processes[numberOfProcess];
    double totalWaitingTime = 0, averageWaitingTime = 0;

    // Input arrival time and burst time for each process
    for(int i = 0; i < numberOfProcess; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter arrival time for P[" << i + 1 << "]: ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for P[" << i + 1 << "]: ";
        cin >> processes[i].burstTime;
    }

    // Sort processes by arrival time (FCFS scheduling)
    for(int i = 0; i < numberOfProcess - 1; i++)
    {
        for(int j = 0; j < numberOfProcess - i - 1; j++)
        {
            if(processes[j].arrivalTime > processes[j + 1].arrivalTime)
            {
                swap(processes[j], processes[j + 1]);
            }
        }
    }

    // Calculate waiting time and turnaround time
    int currentTime = 0;
    for(int i = 0; i < numberOfProcess; i++)
    {
        // If process arrives after current time, wait for it
        if(currentTime < processes[i].arrivalTime)
        {
            currentTime = processes[i].arrivalTime;
        }
        
        // Calculate waiting time
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        
        // Calculate turnaround time
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        
        // Update current time
        currentTime += processes[i].burstTime;
        
        // Add to total waiting time
        totalWaitingTime += processes[i].waitingTime;
    }

    // Calculate average waiting time
    averageWaitingTime = totalWaitingTime / numberOfProcess;

    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround" << endl;
    cout << "----------------------------------------" << endl;
    
    // Display results
    for(int i = 0; i < numberOfProcess; i++)
    {
        cout << "P[" << processes[i].id << "]\t" 
             << processes[i].arrivalTime << "\t" 
             << processes[i].burstTime << "\t" 
             << processes[i].waitingTime << "\t" 
             << processes[i].turnaroundTime << endl;
    }

    cout << "\nAverage waiting time: " << fixed << setprecision(2) << averageWaitingTime << endl;


    return 0;
}


