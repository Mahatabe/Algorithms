#include<bits/stdc++.h>


int x[20], count;

int main()

{
int n,j,l;

 void Nqueen(int k,int n);

 printf("Enter number of Queens:");


 scanf("%d",&n);

 Nqueen(1,n);

return 0;
}

void print(int n)

{

 int j,l;


 printf("\n\nSolution %d:\n\n",count++);

 for(j=1;j<=n;j++)

  printf("\t%d",j);

 for(j=1;j<=n;j++)

 {

  printf("\n\n%d",j);

  for(l=1;l<=n;l++)
   {

   if(x[j]==l)

    printf("\tQ");

   else

    printf("\t-");

     }
  }
}


int place(int k,int i)

{

 int j;

 for(j=1;i<=k-1;j++)
    {

       if(x[j]==i)
       {
           return 0;
       }

       else
       {
           if(abs(x[j]-i)==abs(j-k))
           {
               return 0;
           }
           return 1;
       }
    }

}



void Nqueen(int k,int n)
{

 int i;

 for(i=1;i<=n;i++)
     {
        if(place(k,i))
        {
            x[k]=i;
            if(k == n)
            {
                print(n);
            }
            else
            {
                Nqueen(k+1,n);
            }
        }
     }
}
