#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q)
{
    int *t;
    t=p;
    p=q;
    q=t;
}

void func(char *q)
{
           char a[]="hello";
           q=a;
}

void sub(int x,int y,int *z)
{
       *z=y-x;
}

findmin(int *s, int t, int *k)
{
    int p;
    for(p = 0;p<t;p++)
    {
        if(s[p]<s[*k])
        *k=p;
    }
}

main()
{
    int a[10]={0,8,3,7,6,4,5,2,1},i,*k=&i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    i=0;
    findmin(a, 10,k);
    printf("%d, %d", *k,a[*k]);
}
//void main()
    //{
    //char s[5] = {"ABCDE"};
    //char *s;
    //scanf("%s",&s);
    //char *s;
    //s = "ABCDE";
    //char s[5] = {'A', 'B', 'C', 'D', 'E'};

    /*int x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, *p1;
    p1 = x + 3;
    printf("%d ",*p1++);
    p1 = x + 2;
    printf("%d ",*(p1++));
    p1 = x + 2;
    printf("%d ",*++p1);*/

          //int a,b,c;
          //sub(10,5,&a);
          //sub(7,a,&b);
          //sub(a,b,&c);
          //printf("%d,%d,%d\n",a,b,c);
    //}
/*
int main()
{
    int a[4] = {1,2,3,4};
    int *p;
    p=&a[2];
    printf("%d ",++*p);
    printf("%d\n",*--p);


    char *p;
    func(p);
    printf("%s\n",p);
    //int a=10,b=20;
    //swap(&a,&b);
    //printf("a=%d,b=%d\n",a,b);
    return 0;
}*/
