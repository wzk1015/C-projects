#include <stdio.h>
#include <stdlib.h>

int prime(a)
{
    int i;
    for (i=2;i<=a/2+1;i++)
    {
      if (a==2)
        return 1;
      if (a%i==0)
        return 0;
    }
    return 1;

}


int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;;i++){
        if (prime(i)==1)
            continue;
        if (n%i==0){
            printf("%d ",i);
            n/=i;
            if (n%i==0)
                i--;
        }
        if (n==1)
            break;
    }
    return 0;
}
