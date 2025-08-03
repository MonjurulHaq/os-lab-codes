#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numberOfProcess;
    cout << "Enter the number of process: ";
    cin >> numberOfProcess;
    int brustTime[numberOfProcess + 1], waitingTime[numberOfProcess + 1], turnAroundTime[numberOfProcess + 1];
    double totalWaitingTime, averageWaitingTime;

    for (int i = 0; i < numberOfProcess; i++)
    {
        cout << "p[" << i + 1 << "]: ";
        cin >> brustTime[i];
    }

    waitingTime[0] = 0;

    for (int i = 1; i < numberOfProcess; i++)
    {
        waitingTime[i] = 0;
        for (int j = 0; j < i; j++)
        {
            waitingTime[i] += brustTime[j];
        }
    }

    cout << "Process      Turnaround      Waitingtime" << endl;
    for (int i = 0; i < numberOfProcess; i++)
    {
        turnAroundTime[i] = waitingTime[i] + brustTime[i];
        totalWaitingTime += waitingTime[i];
        averageWaitingTime = totalWaitingTime / numberOfProcess;
        cout << "P[" << i + 1 << "]" << "\t\t" << turnAroundTime[i] << "\t\t" << waitingTime[i] << endl;
    }
    cout << "Average waiting time: " << setprecision(4) << averageWaitingTime;
    return 0;
}