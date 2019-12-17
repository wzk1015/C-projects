#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,maxtimes=0,maxnum=-1;
    int a[10000],b[10000];
    scanf("%d",&N);

    for (i=0;i<10000;i++)
        b[i]=0;

    for (i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }

    for (i=0;i<10000;i++)
    {
        if (maxtimes < b[i])
        {
            maxtimes = b[i];
            maxnum = i;
        }
    }
    printf("%d",maxnum);

    return 0;
}
