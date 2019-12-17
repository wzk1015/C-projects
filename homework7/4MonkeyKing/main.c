#include <stdio.h>
#include <stdlib.h>


int a[1000];    //a[i]作为第i只猴子的指标，其值为所报的数,

void Monkey(int n, int m, int start, int monkeys_left)
{
    int i,k=1,mark;
    if (monkeys_left!=1)
    {
        for (i=start;;i++)
        {
            if (i==n)
                i=0;
            if (a[i]!=m)
                a[i]=k++;
            if (k==m+1)     //已经把m赋给了a[i]
            {
                mark=i;
                break;
            }
        }
        Monkey (n,m,mark+1,monkeys_left-1);
    }

    else
    {
        for (i=start;;i++)
        {
            if (i==n)
                i=0;
            if (a[i]!=m)
            {
                printf("%d",i+1);
                break;
            }
        }
    }
}

int main()
{
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    Monkey(n,m,q-1,n);
    return 0;
}
