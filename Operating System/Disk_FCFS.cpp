#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, head, i, j, diff, maxH;
    int seek = 0;

    cout << "Number of heads : ";
    cin >> maxH;

    cout << "Number of cylinder requests : ";
    cin >> n;

    int arr[n+1];

    cout << "Cylinder requests : ";
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    cout << "Current head position : ";
    cin >> head;

    arr[0] = head;
    cout << endl;

    cout << "Cylinder serving order : "<< arr[0] ;
    for(j=0; j<=n-1; j++)
    {
        diff = abs(arr[j+1]-arr[j]);
        seek += diff;
        cout <<" -> "<<arr[j+1];
    }

    cout << endl;
    cout <<endl <<"Total cylinder movement : " <<seek << endl;
}

// 98 183 37 122 14 124 65 67
