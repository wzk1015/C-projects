#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,x;
    scanf("%d",&x);
    if (x>=100&&x<=999){
        a=x/100;
        b=(x-100*a)/10;
        c=(x-100*a-10*b);
        d=100*c+10*b+a;
        printf("%d",d);
    }
    else
        printf("-1");
    return 0;
}
