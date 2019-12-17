#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int a[1000];
int n;
int ans=0;

void find(int index, int m)  //遍历1~n的所有含有n个元素的子集
{                               //index:当前下标 m:在剩下的数中取出m个
    int i,j;
    double sum=0;
    if (m==1)
    {                           //要在剩下数种取出1个
        for (i=index; i<N; i++)
        {
                a[i]=1;
                for (j=0;j<N;j++)
                    if (a[j]==1)
                        sum+=(j+1);
                if ( sum== N*(N+1)/4.0 )
                {
                    ans++;
                    for (j=0;j<N;j++)
                        if (a[j]==1)
                            printf("%d ",j+1);
                    printf("\n");
                }
                sum=0;
                a[i]=0;
        }
    }
    else {                      //当要在剩下数中取出2个及以上时用递归
        for (i=index; i<N; i++)
        {
                a[i]=1;
                find(i+1,m-1);
                a[i]=0;
        }
    }
}


int main()
{
    scanf("%d",&N);
    for (n=1;n<=N;n++)
        find(0,n);

    printf("%d\n",ans/2);
    return 0;
}
