#include<stdio.h>

int N,a[11];
int count=0;

void output()
{
    int j;
    count++;
        for(j=0;j<N;j++)
            printf("%d ",a[j]);
        printf("\n");
}

void swap(int a,int b)
{
    int *p1=a, *p2=b, *t;
    t=*p1;
    *p1=*p2;
    *p2=t;
}

void Rank(int k)//fun(k)��ʾ��������ȷ��ĳ�����е��еĵ�k����
{
    int j,t;
    if(k==N)
        output();
    else
    {
        for(j=k;j<N;j++)
        {
            t=a[k];a[k]=a[j];a[j]=t;
            Rank(k+1);
            t=a[k];a[k]=a[j];a[j]=t;
        }
    }
}

 int main()
 {
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
       a[i]=i+1;
    Rank(0);
    printf("total:%d\n",count);
    return 0;
}
/*
#include<stdio.h>
int n,a[20];
long count=0;
void fun(int k); //fun(k)��ʾ��������ȷ��ĳ�����е��еĵ�k����
//Ҳ������Ϊfun(k)�����ɵ�k��������n�������������С�
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    fun(0);
    printf("total:%d\n",count);
    return 0;
}
void fun(int k)//fun(k)��ʾ��������ȷ��ĳ�����е��еĵ�k����
{
    int j,t;
    if(k==n)
    {
        count++;
        for(j=0;j<n;j++) printf("%d ",a[j]);
        printf("\n");
        return ;
    }
    else
    {
        for(j=k;j<n;j++)//ע�⣺��������ԭʼ�����ڽ�������ʵ�����У�����j��k��ʼ
        {
            t=a[k];a[k]=a[j];a[j]=t;
            fun(k+1);
            t=a[k];a[k]=a[j];a[j]=t;
        }
    }
}
*/
