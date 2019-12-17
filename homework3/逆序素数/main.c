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
    int n,m;
    int a,b,c,d,e;
    a=b=c=d=e=0;
    scanf("%d",&n);

    if (prime(n)==0)
        printf("no");
    else
{

    if (n<=9){
        m=n;

    }
    else if (n<=99){
        a=n/10;
        b=n-10*a;
        m=10*b+a;
    }
    else if (n<=999){
        a=n/100;
        b=(n-100*a)/10;
        c=n%10;
        m=100*c+10*b+a;

    }
    else if (n<=9999){
        a=n/1000;
        b=n%1000/100;
        c=n%1000%100/10;
        d=n%10;
        m=1000*d+100*c+10*d+e;

    }
    else{
        a=n/10000;
        b=n%10000/1000;
        c=n%10000%1000/100;
        d=n%10000%1000%100/10;
        e=n%10;
        m=10000*e+1000*d+100*c+10*d+e;
    }

    if (prime(m)==1)
        printf("yes");
    else printf("no");
}

    return 0;
}
