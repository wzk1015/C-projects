#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double x[100],y[100];

double area(int n1,int n2, int n3)
{
    double s,a,b,c;
    a=sqrt((x[n1]-x[n2])*(x[n1]-x[n2])+(y[n1]-y[n2])*(y[n1]-y[n2]));
    b=sqrt((x[n1]-x[n3])*(x[n1]-x[n3])+(y[n1]-y[n3])*(y[n1]-y[n3]));
    c=sqrt((x[n2]-x[n3])*(x[n2]-x[n3])+(y[n2]-y[n3])*(y[n2]-y[n3]));
    s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    int N,i;
    double S=0;

    scanf("%d",&N);
    for (i=0;i<N;i++)
        scanf("%lf %lf",&x[i],&y[i]);

    for (i=0;i<N-2;i++)
        S+= area(0,i+1,i+2);
    printf("%.2f\n",S);
    return 0;
}
