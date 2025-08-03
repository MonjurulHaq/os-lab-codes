#include<bits/stdc++.h>
using namespace std;
int main()
{
    int numberOfProcess;

    cout << "Enter number of process:" << endl;
    cin >> numberOfProcess;
    int process[numberOfProcess + 1], burstTime[numberOfProcess + 1], waitingTime[numberOfProcess + 1], turnAroundTime[numberOfProcess + 1];
    
    cout<<"Enter brust time: " << endl;
    for(int i=0; i< numberOfProcess; i++)
    {
        cout << "P[" << i + 1 << "]:";
        cin >> burstTime[i];
        process[i] = i+1;
    }

    int pos;
    for(int i=0; i<numberOfProcess; i++)
    {
        pos = i;
        for(int j=i+1; j<numberOfProcess; j++)
        {
            if(burstTime[j]<burstTime[pos])
            pos = j;
        }
        int temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;

        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    
    }

    waitingTime[0] = 0;
    int totalWaitingTime = 0;

    for(int i=1; i<numberOfProcess; i++)
    {
        waitingTime[i] = 0;
        for(int j = 0; j<i; j++)
        {
            waitingTime[i] += burstTime[j];
        }
        totalWaitingTime += waitingTime[i];
    }

    double averageWaitingTime =(float)totalWaitingTime / numberOfProcess;

    cout << "Process    Waiting Time    Turnaround Time" << endl;
    for(int i=0; i<numberOfProcess; i++)
    {
        turnAroundTime[i]=burstTime[i]+waitingTime[i];
        cout << process[i] << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }
    cout << "Average waiting time: " << setprecision(4) << averageWaitingTime << endl;
    return 0;
}