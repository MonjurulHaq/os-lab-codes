#include<bits/stdc++.h>
using namespace std;


int main()
{

    int numberOfProcess;


    cout << "Enter number of process:" << endl;
    cin >> numberOfProcess;
    int burstTime[numberOfProcess + 1], process[numberOfProcess + 1], waitingTime[numberOfProcess + 1], turnAroundTime[numberOfProcess + 1], priority[numberOfProcess + 1];

    cout << "Enter Burst Time and Priority:" << endl;
    for(int i=0; i< numberOfProcess; i++)
    {
        cout << "\nP[" << i + 1 << "]:";
        cin >> burstTime[i] >> priority[i];
        process[i] = i+1;
    }

    // Sorting burst time, priority, and process number in ascending order using selection sort
    int pos;
    for(int i=0; i< numberOfProcess; i++)
    {
        pos = i;
        for(int j=i+1; j<numberOfProcess; j++)
        {
            if(priority[j] < priority[pos])
                pos = j;
        }
        //swapping

        int temp = priority[i];
        priority[i]= priority[pos];
        priority[pos]=temp;

        temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;

        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }
    double total = 0.0;
    waitingTime[0] = 0; // waiting time for the first process is 0
    for(int i=1; i<numberOfProcess; i++)
    {
        waitingTime[i] = 0;
        for (int j = 0; j < i; j++)
        {
            waitingTime[i] += burstTime[j];
        }
        total += waitingTime[i];
    }

    cout << "Process\t\tWaiting Time\t\tTurnaround Time" << endl;
    for(int i=0; i<numberOfProcess; i++)
    {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
        cout << process[i] << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }
    cout << "Average waiting time: " << setprecision(4) << total / numberOfProcess << endl;



    return 0;
}



/*

Process: 4
Burst time & Priority:
6 3
2 2
14 1
6 4

*/
