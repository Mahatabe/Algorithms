#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n, cput[50], wt[50], tt[50], ct[50];

    cout<<"Enter the number of  process : ";
    cin>>n;

    cout<<"Enter the CPU times : ";
    for(int i=0; i<n; i++)
    {
        cin>>cput[i];
    }

    cout<<endl;

    for(int i=0; i<n; i++)
    {
        wt[i] = 0;

        for(int j=0; j<i; j++)
        {
            wt[i] = wt[i] + cput[j];
        }
        ct[i] = wt[i] + cput[i];

        cout<<"|-------Process "<< i+1 << "-------|";
    }

    cout<<endl;

    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
        cout<< wt[i] << "\t\t\t " << ct[i];
        }
        else
        {
        cout<< "\t\t\t " << ct[i];
        }
    }

    cout<<endl;

    for(int i=0; i<n; i++)
    {
        tt[i] = cput[i] + wt[i];

        cout<< "\nProcess " << i+1 <<" :  Waiting Time: " << wt[i] << "\t Turnaround Time: " << tt[i] <<endl;
    }

}
