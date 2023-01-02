#include<stdio.h>
#include<stdlib.h>


void tower(int a,char from,char aux,char to)
{
    if(a==1)
    {
        printf("Move Disc 1 From %c to %c \n",from,to);
        return ;
    }
    else
    {
        tower(a-1,from,to,aux);
        printf("Move Disc %d From %c to %c \n",a,from,to);
        tower(a-1,aux,from,to);
    }
}
int main()
{
    int n;
    printf("Enter how many dics : ");
    scanf("%d",&n);
    tower(n,'A','B','C');

    return 0;
}
