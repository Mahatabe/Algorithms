#include<bits/stdc++.h>
using namespace std;
char d[50][50];
 int l=0;
void printlcs(char x[],int i,int j)
{
    if(i==0 || j==0)
        return ;
    if(d[i][j]=='d')
    {
        printlcs(x,i-1,j-1);
        printf("%c",x[i-1]);
        l++;
    }
    else if(d[i][j]=='u')
    {
        printlcs(x,i-1,j);
    }
    else
        printlcs(x,i,j-1);
}
int lcs(char x[], char y[])
{
    int m,n,i,j;
    m=strlen(x);
    n=strlen(y);
    int c[m][n];
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                d[i][j]='d';

            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                d[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                d[i][j]='l';
            }
        }
    }

for(i=0;i<=m;i++)
{
    for(j=0;j<=n;j++)
    {
        cout<<c[i][j]<<" ";
    }
    cout<<endl;
}

    cout<<"The lcs is : ";
    printlcs(x,i-1,j-1);
    cout<<endl<<"The length of the lcs: "<<l;


}
int main()
{
    char x[50],y[50];
    cout<<"Enter string x: ";
    gets(x);
    cout<<endl<<"Enter string y: ";
    gets(y);


    lcs(x,y);

}
