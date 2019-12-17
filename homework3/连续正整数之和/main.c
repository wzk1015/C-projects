#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k,w=0;
    scanf("%d",&n);
    for(i=1;i<=n/3;i++)
    {
        for(j=i;j<=n;j++)
        {
            if ((i+j)*(j-i+1)/2==n){
                printf("%d=",n);
                for (k=i;k<=j;k++)
                {   if (k==j)
                        printf("%d",j);
                    else
                        printf("%d+",k);

                }
                w=1;
                break;
            }
        }
        if (w==1)
            break;
    }

    if(w==0)
        printf("No Answer");
    return 0;
}
