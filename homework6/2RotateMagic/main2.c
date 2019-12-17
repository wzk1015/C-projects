#include <stdio.h>
#include <stdlib.h>

void MakeMagic(int (*a)[9],int N)
{
    int i,k=1,n=N;
    for (n=N;n>0;n--)
    {
        for (i=0;i<2*n-N;i++,k++)
            a[N-n][N-n+i]=k;
        for (i=1;i<2*n-N;i++,k++)
            a[N-n+i][n-1]=k;
        for (i=1;i<2*n-N;i++,k++)
            a[n-1][n-1-i]=k;
        for (i=1;i<2*n-N-1;i++,k++)
            a[n-1-i][N-n]=k;
    }
}

int main()
{
    int N,i,j;
    int a[9][9];

    scanf("%d",&N);
    MakeMagic(a,N);

    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
    return 0;
}
