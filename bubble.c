#include<stdio.h>

void bubble(int a[], int n)
{
    int i,j,temp;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {6, 8, 1, 9, 3};
    bubble(a,5);
    for(int i=0; i<5; i++)
    {
        printf(" %d ", a[i]);
    }
}
