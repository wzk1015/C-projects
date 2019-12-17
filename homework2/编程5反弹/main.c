#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,m;
    double x,h;
    x=0;
    h=0;
    scanf("%d %d",&n,&m);
    h=(double)n*(pow(0.25,m));
    x=(5*n/3.0-(pow(0.25,m-1))*2.0*n/3.0);
    printf("%.2f\n%.2f\n",x,h);
    return 0;
}
