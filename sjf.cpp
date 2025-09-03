#include<bits/stdc++.h>

using namespace std;


int main()
{
    int numberOfProcess;

    cout << "Enter number of process:" << endl;
    cin >> numberOfProcess;
    int process[numberOfProcess + 1], burstTime[numberOfProcess + 1], arrivalTime[numberOfProcess + 1], waitingTime[numberOfProcess + 1], turnAroundTime[numberOfProcess + 1];

    cout << "Enter Burst Time and Arrival Time:" << endl;
    for(int i=0; i< numberOfProcess; i++)
    {
        cout << "P[" << i + 1 << "] Burst Time:";
        cin >> burstTime[i];
        cout << "P[" << i + 1 << "] Arrival Time:";
        cin >> arrivalTime[i];
        process[i] = i+1;
    }

    //Sorting by arrival time first, then by burst time (SJF non-preemptive)
    int pos;
    for(int i=0; i< numberOfProcess; i++)
    {
        pos = i;
        for(int j=i+1; j<numberOfProcess; j++)
        {
            // First sort by arrival time, then by burst time
            if(arrivalTime[j] < arrivalTime[pos] || 
               (arrivalTime[j] == arrivalTime[pos] && burstTime[j] < burstTime[pos]))
                pos = j;
        }

        // Swap burst time
        int temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;

        // Swap process number
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;

        // Swap arrival time
        temp = arrivalTime[i];
        arrivalTime[i] = arrivalTime[pos];
        arrivalTime[pos] = temp;
    }


    // Calculate completion time, waiting time, and turnaround time
    int completionTime[numberOfProcess + 1];
    int currentTime = 0;
    int total = 0;

    for(int i=0; i<numberOfProcess; i++)
    {
        // If current time is less than arrival time, wait until process arrives
        if(currentTime < arrivalTime[i])
            currentTime = arrivalTime[i];
        
        // Calculate completion time
        completionTime[i] = currentTime + burstTime[i];
        
        // Calculate waiting time
        waitingTime[i] = currentTime - arrivalTime[i];
        
        // Calculate turnaround time
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        
        // Update current time for next process
        currentTime = completionTime[i];
        
        total += waitingTime[i];
    }

    double averageWaitingTime =(float)total / numberOfProcess;

    cout << "Process    Arrival Time    Burst Time    Waiting Time    Turnaround Time" << endl;
    for(int i=0; i<numberOfProcess; i++)
    {
        cout << process[i] << "\t\t" << arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }
    cout << "Average waiting time: " << setprecision(4) << averageWaitingTime << endl;


    return 0;
}

