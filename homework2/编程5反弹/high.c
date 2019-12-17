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
    h=n*(pow(0.25,m));
    x=(5/3.0-(pow(0.25,m))*2/3.0)*n;
    printf("%.2f\n%.2f\n",x,h);
    return 0;
}
