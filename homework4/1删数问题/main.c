#include <stdio.h>
#include <stdlib.h>


int main()
{
    char a[240];
    int N,i=0,j=0,n=0,m=0;
    while ((a[i]=getchar())!='\n')
        i++;
    a[i+1]='\0';
    n=i+1;
    scanf("%d",&N);
    while(m<N){
        for(i=0;i<n;i++)
        {
            if(a[i+1]<a[i])
            {
                for(j=i;j<n;j++)
                {
                    a[j]=a[j+1];
                }
                m++;
                break;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if (a[i]!='f'&&a[i]!='\0')
            printf("%c",a[i]);
    }

    return 0;

}
