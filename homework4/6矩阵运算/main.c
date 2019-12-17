#include <stdio.h>
#include <stdlib.h>

int a[10][10],b[10][10];
int N;
char op;

/*void input(int a[10][10],int N) //¶ÁÈë¾ØÕó
{
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            scanf ("%d",&a[i][j]);
        }
    }

}
*/


int main()
{
    int i,j;
    scanf("%d",&N);     //ÊäÈë¾ØÕó½×Êı
    //input(a[10][10],N);

    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            scanf ("%d",&a[i][j]);
        }
    }

    while ((op=getchar())!='#')
    {
        if (op=='+')
        {
            for (i=0;i<N;i++)
            {
                for (j=0;j<N;j++)
                {
                    scanf ("%d",&b[i][j]);
                    a[i][j]=a[i][j]+b[i][j];
                }
            }

        }

        else if (op=='-')
        {
            for (i=0;i<N;i++)
            {
                for (j=0;j<N;j++)
                {
                    scanf ("%d",&b[i][j]);
                    a[i][j]=a[i][j]-b[i][j];
                }
            }

        }


    }

    for (i=0;i<N;i++)
            {
                for (j=0;j<N;j++)
                {
                    printf("%5d",a[i][j]);
                }
                printf("\n");
            }
    return 0;
}
