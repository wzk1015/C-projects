#include <stdio.h>
#include <stdlib.h>

int expand(char a[],int n)
{
    int i,j=0,start=0,end=0;

    for (i=0;i<n;i++)
    {
        if (a[i]!='-')
            printf("%c",a[i]);
        else
        {
            start = a[i-1];
            end = a[i+1];
            if (start<=end)
                for (j=start+1;j<end;j++)
                    printf("%c",j);
            else printf("-");
        }
    }

    return 0;
}
int main()
{
    int i=0,n;
    char a[100];
    while ((a[i]=getchar())!='\n')
        i++;
    a[i+1]='\0';
    n=i+1;
    expand(a,n);
    return 0;
}
