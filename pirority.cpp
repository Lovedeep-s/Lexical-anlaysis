// This code is made by Lovedeep singh
#include <bits/stdc++.h>
class process//delcared a class to group all the data of a process in a object
{
public:
    int arrival;
    int cpu_burst;
    int priority;
    int pid;
    int waiting_time;
};
using namespace std;
int main()
{
    int n;
    cout << "Enter number of processes = ";
    cin >> n;//asked the user to input the number of processes
    process p[n];//accordingly we declared an array of objects of class process
    for (int i = 0; i < n; i++)//asked user to input information like arrival ,cpu burst etc for each process
    {
        cout << "Enter arrival time of process " << i + 1<<" = ";
        cin >> p[i].arrival;
        cout << "Enter cpu burst time of process " << i + 1<<" = ";
        cin >> p[i].cpu_burst;
        cout << "Enter priority of process " << i + 1<<" = ";
        cin >> p[i].priority;
        p[i].pid = i + 1;
        p[i].waiting_time = 0;
    }
    int run = 1;//run used as a control variable for the while loop on line 36
    sort(p, p + n, [](process a, process b) 
         { return a.arrival < b.arrival; });//before entering the loop we sorted the process according to their arrival times

    int k = 0;//the k variable represnt the index of the process which is currently being executed
    int temp;
    while (run)
    {
        for (int i = k + 1; i < n; i++)//this for loop is used to check if any process has arrived and it has pirority higher the the current process
        {
            if (p[i].arrival == 0)
            {
                if (p[i].priority < p[k].priority)
                {
                    temp = p[i].waiting_time;
                    p[i].waiting_time = p[k].waiting_time;
                    p[k].waiting_time = temp;
                    temp = p[i].arrival;
                    p[i].arrival = p[k].arrival;
                    p[k].arrival = temp;
                    temp = p[i].cpu_burst;
                    p[i].cpu_burst = p[k].cpu_burst;
                    p[k].cpu_burst = temp;
                    temp = p[i].priority;
                    p[i].priority = p[k].priority;
                    p[k].priority = temp;
                    temp = p[i].pid;
                    p[i].pid = p[k].pid;
                    p[k].pid = temp;
                }
            }
        }

        p[k].cpu_burst--;//then the cpu burst of the current process is decremented by 1
        for (int i = k; i < n; i++)//the for loop is used to increment the waiting time of the process whill has arrived but are not being executed
        {
            if (p[i].arrival == 0)
            {
                if (k != i)//check the arrived process is not the current process
                {
                    if (p[i].cpu_burst != 0)//and process is not completed 
                    {
                        p[i].waiting_time++;//then increment the waiting time 
                    }
                }
            }
        }
        for (int i = k; i < n; i++)//this loop decrements the arrival time of the processes which are not yet arrived
        {
            if (p[i].arrival > 0)//this condition is used to check if a process is arrived or not
            {
                p[i].arrival--;//then decrements the arrival time
            }
            // else
            // {
            // if (k != i)
            // {
            //     if (p[i].cpu_burst != 0)
            //     {
            //         p[i].waiting_time++;
            //     }
            // }
            // }
        }

        if (p[k].cpu_burst == 0)//this condition is used to check if current process is completed or not
        {
            k++;//if process is completed then the k index will be incremented
            if (k == n)//this condition is used to check if all processes are completed or not
            {
                run = 0;//if all are completed then run varible becomes false and we exit the loop
            }
        }
    }
    for (int i = 0; i < n; i++)//this loop is used to print the waiting time of each process
    {
        cout << "Waiting time of process " << p[i].pid << " is " << p[i].waiting_time << endl;
    }
}