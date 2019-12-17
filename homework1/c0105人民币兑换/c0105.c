#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,a,b,c,d;
    scanf("%d",&x);
    a=x/10;
    b=(x-10*a)/5;
    c=(x-10*a-5*b)/2;
    d=x-10*a-5*b-2*c;
    printf("%d %d %d %d ",a,b,c,d);
    return 0;
}
