#include<stdio.h>

void insertion(int a[], int n)
{
    int i,j,temp;
    for(j=1; j<n; j++)
    {
        temp = a[j];
        i = j-1;
        while(i>=0 && a[i]>temp)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = temp;
    }
}

int main()
{
    int a[] = {6, 8, 1, 9, 3};
    insertion(a,5);
    for(int i=0; i<5; i++)
    {
        printf(" %d ", a[i]);
    }
}

