#include<bits/stdc++.h>

using namespace std;

struct process
{
    int pid, cput, aT, priority, wt, tt, rt, status;
};

void priority_scheduling(process p[],int n)
{
    int proc = 0;
    int cTime = 0;
    int cProcess;

    while(proc != n)
    {
        int maxPriority = 100;

        for(int i=0; i<n; i++)
        {
            if(p[i].priority<maxPriority && p[i].status!=1 && p[i].aT<=cTime)
            {
                maxPriority = p[i].priority;
                cProcess = i;
            }
        }

        for(int i=0; i<n; i++)
        {
            if(p[i].priority==maxPriority && p[i].status!=1 && p[i].aT<=cTime)
            {
                if(p[i].aT < p[cProcess].aT)
                {
                    cProcess = i;
                }
            }
        }

        p[cProcess].rt--;
        cTime++;

        if(p[cProcess].rt == 0)
        {
            proc++;
            p[cProcess].status = 1;
            p[cProcess].tt = cTime - p[cProcess].aT;
            p[cProcess].wt = p[cProcess].tt - p[cProcess].cput;
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<"Process "<<p[i].pid<<" : Waiting Time : "<<p[i].wt<<"\tTurnaround Time : "<<p[i].tt<<endl;
    }

    cout << endl;
}

int main()
{
    process p[100];
    int n;

    cout<<"Enter the number of process : ";
    cin>>n;

    cout << endl;

    cout<<"Enter the cpu times : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].cput;
        p[i].rt=p[i].cput;
    }

    cout<<"Enter the arrival times : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].aT;
        p[i].pid = i+1;
        p[i].status = 0;
    }

    cout<<"Enter the priority values : ";
    for(int i=0;i<n;i++)
    {
        cin>>p[i].priority;
    }

    cout << endl;

    priority_scheduling(p,n);
}
