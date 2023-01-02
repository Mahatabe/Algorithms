#include<stdio.h>

int partition(int a[],int l, int h)
{

    int pivot,i,j,temp;

    pivot = a[h];
    i=l;

    for(j=l;j<=h-1;j++)
    {
        if(a[j]>=pivot)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i = i+1;
        }
    }
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;


    return i;

}

void Quicksort(int a[], int l, int h)
{

    int p;

    if(l<h)
    {

        p = partition(a, l, h);
        Quicksort(a,l,p-1);
        Quicksort(a,p+1,h);

    }

}


int main()

{
    int n = 6,i;

    int a[6] = {2,5,8,9,2,6};


	Quicksort(a,0,n-1);
	printf("\nArray after sorting: ");

	for(i=0;i<n;i++)
		printf("%d ",a[i]);

}
