#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;
    double S,s;
    scanf("%d %d %d",&a,&b,&c);
    s=(a+b+c)/2.0;
    S=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("%.3f",S);
    return 0;
}
