
#include<bits/stdc++.h>
using namespace std;


int main()
{

    int numberOfProcess;
    cout << "Number of processes: " << endl;
    cin >> numberOfProcess;
    int burstTime[numberOfProcess + 1], arrivalTime[numberOfProcess + 1], temp[numberOfProcess + 1];

    cout << "Enter Arrival Time & Burst Time: " << endl;
    for(int i = 0; i < numberOfProcess; i++)
    {
        cin >> arrivalTime[i] >> burstTime[i];
        temp[i] = burstTime[i];
    }

    int timeQuantum;
    cout << "TimeQuantum: " << endl;
    cin >> timeQuantum;

    int remain = numberOfProcess;
    int count = 0;
    double waitingTime = 0.0;
    double turnaroundTime = 0.0;

    cout << "Process\t\tWaiting Time\t\tTurnaround Time" << endl;
    for(int total = 0, i = 0; remain != 0;)
    {
        if(temp[i] <= timeQuantum && temp[i] > 0)
        {
            total += temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] -= timeQuantum;
            total += timeQuantum;
        }
        if(temp[i] == 0 && count == 1)
        {
            --remain;
            printf("Process[%d]\t\t%d\t\t%d\n", i + 1, total - arrivalTime[i] - burstTime[i], total - arrivalTime[i]);
            waitingTime = waitingTime + total - arrivalTime[i] - burstTime[i];
            turnaroundTime = turnaroundTime + total - arrivalTime[i];
            count = 0;
        }
        if(i == numberOfProcess - 1)
        {
            i = 0;
        }
        else if(arrivalTime[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    cout << "Total waiting time: " << float(waitingTime) << endl;
    cout << "Average waiting time: " << setprecision(4) << waitingTime * 1.0  / numberOfProcess << endl;



    return 0;
}

/*

Process: 4
Arrival & Burst Time:
0 4
1 7
2 5
3 6
Time Quantum: 3

*/
