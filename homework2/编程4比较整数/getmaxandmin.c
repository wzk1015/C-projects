#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,i,max,min;
    max=0;
    min=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(i==0)
        {
            max=a;
            min=a;
        }
        if(a>=max)
            max=a;
        if(a<=min)
            min=a;
    }
    printf("%d %d\n",max,min);

    return 0;
}
