#include <stdio.h>
#include <stdlib.h>

int N,a[20];

void output()
{
    int i;
    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void Rank(int k)
{
    int i,j,mark=0;

    for (i=1;i<=N;i++)
    {
        if (k>0)
        {
            for (j=0;j<k;j++)
            {
                if (a[j]==i)
                {
                    mark=1;
                    break;
                }
            }
        }
        else
            a[0]=i;
        if (mark==1)
        {
            mark=0;
            continue;
        }
        a[k]=i;
        if (k<N-1)
            Rank(k+1);
        else
            output();
    }


}

int main()
{
    scanf("%d",&N);
    Rank(0);
    return 0;
}



/*void initialize(int *a,int N)
{
    int i;
    for (i=0;i<N;i++)
        a[i]=i+1;
}*/
