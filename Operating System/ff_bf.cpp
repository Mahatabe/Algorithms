#include<bits/stdc++.h>
using namespace std;
int arr[50][50],req[50];
int c,r,s,temp,flag,col,extF,sum,val,mini;
void first_fit()
{
    col = 0;
    sum = 0;
    extF = 0;
    for(int i=0; i<c; i++)
    {
        flag = 0;
        for(int j=0; j<r; j++)
        {
            if(req[i] <= arr[j][col])
            {
                temp = arr[j][col] - req[i];
                flag = 1;
                s = j;
                break;
            }
        }
        col++;
        for(int k=0; k<r; k++)
        {
            arr[k][col] = arr[k][col-1];
        }
        arr[s][col] = temp;
        if(flag == 0)
        {
            extF = 1;
            break;
        }
    }
    cout<<"First Fit"<<endl;
    cout<<endl;
    cout<<setw(10)<<"Initially";
    for(int i=0; i<c; i++)
    {
        cout<<setw(10)<<req[i];
    }
    cout<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<setw(10)<<arr[i][j];
        }
        cout<<endl;
    }
    if(extF == 1)
    {
        for(int i=0; i<r; i++)
        {
            sum += arr[i][col];
        }
        cout<<"\n\t\t\t\t\tExternal Fragmentation: "<<sum<<endl;
    }
    else
    {
        cout<<"\n\t\t\t\t\tNo External Fragmentation";
        cout<<endl;
    }
}
void best_fit()
{
    col = 0;
    sum = 0;
    extF = 0;
    for(int i=0; i<c; i++)
    {
        flag = 0;
        mini = INT_MAX;
        for(int j=0; j<r; j++)
        {
            if(req[i] <= arr[j][col])
            {
                temp = arr[j][col] - req[i];
                if(temp < mini)
                {
                    mini = temp;
                    val = temp;
                    s = j;
                }
                flag = 1;
            }
        }
        if(flag == 0)
        {
            extF = 1;
        }
        col++;
        for(int k=0; k<r; k++)
        {
            arr[k][col] = arr[k][col-1];
        }
        arr[s][col] = val;
    }
    cout<<endl;
    cout<<"Best Fit"<<endl;
    cout<<endl;
    cout<<setw(10)<<"Initially";
    for(int i=0; i<c; i++)
    {
        cout<<setw(10)<<req[i];
    }
    cout<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0; j<c+1; j++)
        {
            cout<<setw(10)<<arr[i][j];
        }
        cout<<endl;
    }
    if(extF == 1)
    {
        for(int i=0; i<r; i++)
        {
            sum += arr[i][c+1];
        }
        cout<<"\n\t\t\t\t\tExternal Fragmentation: "<<sum<<endl;
    }
    else
    {
        cout<<"\n\t\t\t\t\tNo External Fragmentation"<<endl;
    }
}
int main()
{
    cout<<"Enter no. of memory holes : ";
    cin>>r;
    cout<<"Memory holes : ";
    for(int i=0; i<r; i++)
    {
        cin>>arr[i][0];
    }
    cout<<endl;
    cout<<"Enter no. of Memory request : ";
    cin>>c;
    cout<<"Memory request : ";
    for(int j=0; j<c; j++)
    {
        cin>>req[j];
    }
    cout<<endl;
    first_fit();
    best_fit();
}

/*
5
50 200 70 115 15
10
100 10 35 15 23 6 25 55 88 40
*/
