#include<stdio.h>

int a[50];

void counting(int n,int k)
{
    int c[50],b[50];
    int i;

    for(i=0;i<=k;i++)
    {

      c[i]=0;

    }

    for(i=0;i<n;i++)
    {

      c[a[i]]++;

    }

    for(i=1;i<=k;i++)
    {

      c[i]=c[i]+c[i-1];

    }

    for(i=0;i<n;i++)
    {

        b[c[a[i]]-1]=a[i];
        --c[a[i]];

    }

    for(i=0;i<n;i++)
    {

        printf("%d ",b[i]);

    }

    printf("\n");


}

int main()
{

  int n,k=0;
  printf("Enter n : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {

      scanf("%d",&a[i]);

      if(a[i]>k)
        k=a[i];

  }

  printf("After counting sort : ");

  counting(n,k);

}
