#include<bits/stdc++.h>
using namespace std;

int main()
{
    int alloc[20][100];
    int max[20][100];
    int avail[100];
    int need[20][100];
    int safe[20];
    int finish[20];

    int i, j, p, r, x, flag, k=0;

    cout<<"Enter no. of process : ";
    cin>>p;

    cout<<"Enter no. of resources : ";
    cin>>r;

    cout<<"\nEnter allocation from resources:\n";
    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
        {
           cin>>alloc[i][j];
        }
    }

    cout<<"\nEnter max from resources:\n";
    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
        {
            cin>>max[i][j];
        }
    }

    cout<<"\nEnter availability from resources:\n";
    for(i=0;i<r;i++)
    {
        cin>>avail[i];
    }

    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
        {
           need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    for(i=0; i<p; i++)
    {
        finish[i] = 0;
    }
    for(x=0; x<p; x++)
    {
        for(i=0; i<p; i++)
        {
            for(j=0; j<r; j++)
            {
                if(finish[i] == 0)
                {
                    if(need[i][j] <= avail[j])
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                finish[i] = 1;
                safe[k++] = i;

                for(j=0; j<r; j++)
                {
                    avail[j] += alloc[i][j];
                }
            }
        }
    }
    if(k==p)
    {
        cout<< "\nThe System is currently in safe state and <";
        for(i=0; i<p-1; i++)
        {
            cout<< "P" << safe[i] <<" ";

        }
        cout<< "P" << safe[i] ;
        cout<< "> is the safe sequence\n";
    }
    else
    {
        cout<< "The System is not in safe state";
    }
}
