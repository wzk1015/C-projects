#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int a[1000];
int n;
int ans=0;

void find(int index, int m)  //����1~n�����к���n��Ԫ�ص��Ӽ�
{                               //index:��ǰ�±� m:��ʣ�µ�����ȡ��m��
    int i,j;
    double sum=0;
    if (m==1)
    {                           //Ҫ��ʣ������ȡ��1��
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
    else {                      //��Ҫ��ʣ������ȡ��2��������ʱ�õݹ�
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
