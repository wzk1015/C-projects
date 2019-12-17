#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c,x,y,z;
    scanf("%c",&b);
    y=(int)b;
    x=b-1;
    z=b+1;
    a=(char)x;
    c=(char)z;
    printf("%c %c %c\n",a,b,c);
    printf("%d %d %d\n",x,y,z);
    return 0;
}
