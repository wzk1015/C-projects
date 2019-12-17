#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,num_a,num_b,a[100],b[100];
    for (i=1;;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==-1){
            num_a=i;
            break;
        }
    }

    for (i=1;;i++)
    {
        scanf("%d",&b[i]);
        if (b[i]==-1)
        {
            num_b=i;
            break;
        }

    }

    for (i=1;i<=num_a;i++)
    {
        for(j=1;j<=num_b;j++)
        {
            if (a[i]==b[j])
                break;
            if (j==num_b)
                printf("%d ",a[i]);
        }
    }
    return 0;
}
