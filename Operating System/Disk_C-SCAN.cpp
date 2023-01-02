#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[50], arr1[50], arr2[50];
	int seek=0, temp1=0, temp2=0;
	int n, head, i, j, k, maxH, diff, temp;

	cout << "Number of heads : ";
	cin >> maxH;

    cout << "Current head position : ";
    cin >> head;

    cout << "Number of cylinder requests : ";
    cin >> n;

    cout << "Cylinder requests : ";
	for(i=1;i<=n;i++)
	{
		cin >> temp;
		if(temp >= head)
		{
			arr1[temp1] = temp;
			temp1++;
		}
		else
		{
			arr2[temp2]=temp;
			temp2++;
		}
	}
	for(i=0; i<temp1-1; i++)
	{
		for(j=i+1; j<temp1; j++)
		{
			if(arr1[i] > arr1[j])
			{
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
		}
	}
	for(i=0; i<temp2-1; i++)
	{
		for(j=i+1; j<temp2; j++)
		{
			if(arr2[i] > arr2[j])
			{
				temp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = temp;
			}
		}
	}
	for(i=1,j=0; j<temp1; i++,j++)
    {
        arr[i] = arr1[j];
    }

	arr[i] = maxH;
	arr[i+1] = 0;

	for(i=temp1+3,j=0; j<temp2; i++,j++)
    {
        arr[i] = arr2[j];
    }

	arr[0] = head;
	cout << endl;
	cout << "Cylinder serving order : "<< arr[0] ;
	for(j=0; j<=n+1; j++)
	{
		diff = abs(arr[j+1]-arr[j]);
		seek += diff;
		cout <<" -> "<<arr[j+1];
	}

    cout << endl;
    cout <<endl <<"Total cylinder movement : " << seek << endl;
}

// 98 183 37 122 14 124 65 67
