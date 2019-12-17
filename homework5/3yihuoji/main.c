#include <stdio.h>
#include <stdlib.h>

int check(int a[],int b[],int c[],int num_a,int num_b,int k)
{
    int mark=0,i,j;
    for (i=0;i<num_a;i++)
    {
        for (j=0;j<num_b;j++)
        {
            if (a[i]==b[j])
            {
                mark=1;
                break;
            }
        }
        if (mark==0)
        {
            c[k++]=a[i];
        }
        mark=0;
    }
    return k;
}

void rank(int c[],int k)
{
    int i,t,j;
    for(i=1;i<k;i++)
    {
        t=c[i];
        j=i-1;
        while(j>=0&&t>c[j])
        {
            c[j+1]=c[j];
            j--;
        }
            c[j+1]=t;
    }
}

int main()
{
    int a[50],b[50],c[50],i=0,k=0,num_a,num_b;
    char ch;

    do{
        scanf("%d%c",&a[i++],&ch);
    }while(ch!='\n');
    num_a=i;
    i=0;

    do{
        scanf("%d%c",&b[i++],&ch);
    }while(ch!='\n');
    num_b=i;

    k=check(a,b,c,num_a,num_b,k);
    k=check(b,a,c,num_b,num_a,k);

    rank(c,k);

    for (i=0;i<k;i++)
        printf("%d ",c[i]);
    printf("\n");

    return 0;
}
