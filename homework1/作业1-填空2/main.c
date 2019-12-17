#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*char x,y;
    double a;
    x='A';
    y='B';
    a=(x='B')||(y='C');
    printf("%c %c",x,y);*/

    //int a=3,w=5,x=4;
    //a=w>x;
    //printf("%d",a);

    //int  k=4,a=3,b=2,c=1;
    //printf("%d",k<a ? k : c<b ?c :a);

    //double a=3.5;
    //printf("%d",a);

    int a,b;
    for(a=1,b=1;a<=100;a++)
    {
        if (b>=20)
            break;
        if(b%3==1)
        {
            b+=3;
            continue;
        }
        b-=5;
    }
    printf("%d,%d\n",a,b);

    return 0;
}
