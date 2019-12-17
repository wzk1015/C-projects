#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z,sum;
    double avr;
    scanf("%d %d %d",&x,&y,&z);
    sum = x + y + z;
    avr = (double)(x+y+z)/3;
    printf("%d\n%.2f\n",sum,avr);
    return 0;
}
