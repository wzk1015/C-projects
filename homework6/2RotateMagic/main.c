#include <stdio.h>
#include <stdlib.h>

void MakeMagic(int (*a)[9],int n,int N,int k)
{
    int i;
    if  (n==0)
        return;
    for (i=0;i<2*n-N;i++,k++)
        a[N-n][N-n+i]=k;
    for (i=1;i<2*n-N;i++,k++)
        a[N-n+i][n-1]=k;
    for (i=1;i<2*n-N;i++,k++)
        a[n-1][n-1-i]=k;
    for (i=1;i<2*n-N-1;i++,k++)
        a[n-1-i][N-n]=k;
    MakeMagic(a,n-1,N,k);

}

int main()
{
    int N,i,j;
    int a[9][9];
    FILE *out;
    out=fopen("file.out","w");

    scanf("%d",&N);
    MakeMagic(a,N,N,1);

    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
            fprintf(out,"%5d",a[i][j]);
        fprintf(out,"\n");
    }
    return 0;
}
