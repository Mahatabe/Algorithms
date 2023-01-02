#include<stdio.h>
#include<math.h>

double fx(double x)
{
    double f;
    f=2-(x*x);
    return f;
}

int main()
{
    double a,b,c;
    double fa,fb,fc;
    double er=0.0001;
    printf("Enter the initial guess : ");
    scanf("%lf",&a);
    b=fx(a);

    if(b==0)
        printf("The root is %lf : ",b);
    else
    {
        while(fabs((b-a)/b)>er)
        {
            a=b;
            b=fx(a);
        }
    }
    printf("The root is : %lf",b);
    return 0;
}


