#include <bits/stdc++.h>

using namespace std;

struct process
{
    int pid, cput, aT, rt, wt;
};

bool comp(process a, process b)
{
        return a.aT < b.aT;
}

int main()
{
    int n;

    cout << "Enter the number of process : ";
    cin >> n;

    vector<process> vec(n);

    cout << "Enter the cpu time : ";
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].cput;
        vec[i].pid = i + 1;
        vec[i].rt = vec[i].cput;
    }

    cout << "Enter the arrival time : ";
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].aT;
    }

    sort(vec.begin(), vec.end(), comp);
    cout << endl;

    int tot = 0;
    int cProcess = 0;
    int proc = 0;

    while (true)
    {
        proc++;

        if (cProcess == 0)
        {
            vec[cProcess].wt = 0;
            cout<< vec[cProcess].wt ;
        }

        tot += vec[cProcess].cput;
        vec[cProcess].rt = 0;

        cout<<" |-------Process "<< vec[cProcess].pid << "-------| ";
        cout << tot;

        int nextProcess = 100;
        for (int i = 0; i < n; i++)
        {
            if (vec[i].aT<=tot  &&  vec[i].cput<nextProcess  &&  vec[i].rt!=0)
            {
                nextProcess = vec[i].cput;
                cProcess = i;
            }
        }
        if (proc == n)
        {
            break;
        }
    }
    cout<<endl;
}
