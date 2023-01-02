#include<bits/stdc++.h>
using namespace std;
struct process
{
    int pn,aT,cpuT,ta,wt,rt,status;
};
bool sortAT(process a,process b)
{
    return(a.aT<b.aT) || ((a.aT==b.aT) && a.pn<b.pn);
}
bool sortPn(process a,process b)
{
    return a.pn<b.pn;
}
int mini=INT_MAX,q=3;
void rr(process p[],int n)
{
    int ttt=0,twt=0,c=0,timer=0;
    int crntP,mini;
    float att,awt;
    queue<int> rq;
    sort(p,p+n,sortAT);
    rq.push(0);
    p[0].status=1;
    crntP=0;
    while(c!=n)
    {
        crntP=rq.front();
        rq.pop();
        for(int i=0; i<n; i++)
        {
            if(p[i].status==0 && p[i].aT<=(timer + min(q,p[crntP].rt)))
            {
               rq.push(i);
               p[i].status=1;

            }
        }
        if(timer>=p[0].aT)
        {
             cout<<"--"<<timer<<"--P"<<p[crntP].pn;
        }
        if(p[crntP].rt<=q)
        {
            timer+=p[crntP].rt;
            p[crntP].rt=0;
            c++;
            p[crntP].status=2;
            p[crntP].ta=timer-p[crntP].aT;
            p[crntP].wt=p[crntP].ta-p[crntP].cpuT;
            ttt+=p[crntP].ta;
            twt+=p[crntP].wt;
        }
        else
        {
            timer+=q;
            p[crntP].rt-=q;
            rq.push(crntP);
        }



    }
    awt=(float)twt/n;
    att=(float)ttt/n;
    sort(p,p+n,sortPn);
   cout<<"--"<<timer<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Process "<<p[i].pn<<" : Waiting Time : "<<p[i].wt<<" Turnaround Time : "<<p[i].ta<<endl;
    }
    cout<<"Average Waiting time : "<<awt<<endl;
    cout<<"Average Turnaround time : "<<att<<endl;
}
int main()
{
    process p[50];
    int n;
    cout<<"Enter no. of process: ";
    cin>>n;
    cout<<"Enter cpu times ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].cpuT;
        p[i].rt=p[i].cpuT;
    }
    cout<<"Enter arrival times ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].aT;
        p[i].pn=i+1;
        p[i].status=0;
    }

    rr(p,n);
}



