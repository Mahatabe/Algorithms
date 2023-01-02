#include<stdio.h>
#include<math.h>

double fx(double x)
{
    double f;
    f=(x*x)-3*x+2;
    return f;
}
double dfx(double x)
{
    double f;
    f=2*x-3;
    return f;
}
int main()
{
    double a,b,c;
    double fa,dfa;
    double er=0.000000;
    printf("Enter the initial guess : ");
    scanf("%lf",&a);
    fa=fx(a);
    dfa=dfx(a);
    b=a-(fa/dfa);
    //printf("%lf",b);
    if(fx(b)==0)
        printf("The root is : %lf",b);
    else
    {
        do
        {
            a=b;
            fa=fx(a);
            dfa=dfx(a);
            b=a-(fa/dfa);
            if(fx(b)==0)
            {
                printf("The root is : %lf",b);
                break;
            }
        }while(fabs((b-a)/b)>er);
    }
    //printf("The root is : %lf",b);
    return 0;
}
