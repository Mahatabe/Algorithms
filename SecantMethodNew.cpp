#include<stdio.h>
#include<math.h>

double fx(double x)
{
    double f;
    f=(x*x)-4*x-10;
    return f;
}

int main()
{
    double x1,x2,x3;
    double f1,f2,f3;
    double er=0.0001;
    printf("Enter the initial guess : ");
    scanf("%lf%lf",&x1,&x2);
    f1=fx(x1);
    f2=fx(x2);
    x3=(f2*x1-f1*x2)/(f2-f1);
    //printf("%lf",b);

    while(fabs((x3-x2)/x3)>er)
    {
        x1=x2;
        x2=x3;
        f1=f2;
        f2=fx(x2);
        x3=(f2*x1-f1*x2)/(f2-f1);
    }

    {
        printf("The root is : %lf",x3);
    }
    //printf("The root is : %lf",b);
    return 0;
}


