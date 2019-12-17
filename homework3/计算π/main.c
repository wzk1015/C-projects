#include <stdio.h>
#include <stdlib.h>

double f1(int a)
{
    int i;
    double k=1;
    if (a==0)
        return 1;
    for(i=1;i<=a;i++)
    {
        k*=i;
    }
    return k;
}

double f2(int b)
{
    if (b==1)
        return 1;
    int i;
    double k=1;
    for(i=3;i<=2*b-1;i+=2)
    {
        k*=i;
    }
    return k;
}

int main()
{
    int n;
    double pi=0,e;
    scanf("%lf",&e);
    for(n=1;;n++)
    {
        pi+=(f1(n-1)/f2(n))*2;
        if (((f1(n-1)/f2(n)*2)<e)&&(n>=2))
        break;


    }



    printf("%d %.7f\n",n,pi);
    return 0;
}
