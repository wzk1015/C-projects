#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 48680000

typedef struct wzk {
    int value;
    int pow;
} wzk;
wzk a[100],b[100],c[100];
int max_a,max_b,num_a,num_b,m=0;

int GetArray(wzk array[])
{
    int i;
    char ch;
    for (i=0; ;i++)
    {
        scanf("%d%d%c",&(array[i].value),&(array[i].pow),&ch);
        if (ch == '\n')
            break;
    }
    return i+1;
}

void Operate()
{
    int i,j,k,mark=0;
    for (i=num_a-1;i>=0;i--)//遍历a中元素
    {
        if (a[i].value==0)
            continue;
        for (j=num_b-1;j>=0;j--)//遍历b中元素
        {
            for (k=0;k<m;k++)
            {
                if (c[k].pow==a[i].pow+b[j].pow)
                {
                    mark=1;
                    c[k].value += a[i].value * b[j].value;
                    break;
                }
            }
            if (mark==1)
            {
                mark=0;
                continue;
            }
            c[m].pow = a[i].pow + b[j].pow;
            c[m].value = a[i].value * b[j].value;
            m++;
        }
    }
}

void Rank()
{
    int i,j,min;
    wzk temp;
    for(i=0;i<m;i++)
	{
		min=i;
		for(j=i+1;j<m;j++)
			if( c[min].pow>c[j].pow )
				min=j;

		if(min!=i)
		{
			temp = c[i];
			c[i] = c[min];
			c[min] = temp;
		}
	}
}

void PutArray()
{
    int i;
    for (i=m;i>=0;i--)
        if (c[i].value!=0)
            printf("%d %d ",c[i].value,c[i].pow);
}

int main()
{
    num_a=GetArray(a);
    num_b=GetArray(b);

    max_a=a[0].pow;
    max_b=b[0].pow;


    Operate();
    Rank();
    PutArray();
    return 0;
}

/*
int a[MAXLEN+1],b[MAXLEN+1],c[2*MAXLEN+2];  //默认初始化为0
int max_a,max_b;

void GetArray(int array[])
{
    int m,n;
    char ch;
    while (1)
    {
        scanf("%d%d%c",&m,&n,&ch);
        array[n] = m;
        if (ch == '\n')
            break;
    }
}

void Operate(int a[], int b[], int c[])
{
    int i,j;
    for (i=max_a;i>=0;i--)//遍历a中元素
    {
        if (a[i]==0)
            continue;
        for (j=max_b;j>=0;j--)
        {
            c[i+j] += a[i]*b[j];
        }
    }
}

void PutArray(int c[])
{
    int i;
    for (i=max_a+max_b;i>=0;i--)
        if (c[i]!=0)
            printf("%d %d ",c[i],i);
}

int main()
{
    int i;
    GetArray(a);
    GetArray(b);

    for(i=MAXLEN;i>=0;i--)
    {
        if (a[i]!=0)
        {
            max_a=i;
            break;
        }
    }

    for(i=MAXLEN;i>=0;i--)
    {
        if (b[i]!=0)
        {
            max_b=i;
            break;
        }
    }

    Operate(a,b,c);

    PutArray(c);
    return 0;
}
*/
