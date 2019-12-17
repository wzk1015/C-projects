#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

//int x1=30,x2=40;

int fun2(int a,int b)
{
    int c;
    c=a*b%3;
    return c;
}
int fun1(int a,int b)
{
    int c;
    a+=a;
    b+=b;
    c=fun2(a,b);
    return  c*c;
}

main()
{
    int a[]={1,2};

    //int x=11,y=19;
    //printf("%d\n", fun1(x,y));


    /*int x3 = 10, x4 = 20;
    sub(x3, x4);
    sub(x2, x1);
    printf("%d,%d,%d,%d", x3, x4, x1, x2);*/


    /*int i=0;
    while(i<3)
        for(; i<4;i++)
        {
            printf("%d",i++);
            if(i<3)
                continue;
            else
                break;
            printf("%d\n",i);
        }*/


    /*int x;
    for(x=100;x<=105;x++)
    {
    if(x%3==0)
        continue;
    printf("%d,",x);
    }*/

    /*int x=8;
    increment();
    x++;
    increment();
    x++;
    increment();*/




}


/*void increment()
    {
        int x=0;
        x++;
        printf("%d,",x);
    }*/

/*void sub(int x, int y)
{
    x1 = x;
    x = y;
    y = x1;
}*/


