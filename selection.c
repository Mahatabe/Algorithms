#include<stdio.h>

void selection(int a[], int n)
{
    int i,j,min,temp;
    for(i=0; i<n-1; i++)
    {
        min = i;
        for(j=1; j<n; j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        if(min != i)
            {
                temp = a[min];
                a[min] = a[i];
                a[i] = temp;
            }
    }
}

int main()
{
    int a[] = {6, 8, 1, 9, 3};
    selection(a,5);
    for(int i=0; i<5; i++)
    {
        printf(" %d ", a[i]);
    }
}
