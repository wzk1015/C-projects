#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{


    /*int n,length;
    scanf("%d",&n);
    length=strlen(n);
    printf("%d\n",length);
    return 0;*/

    int n;
    int a,b,c,d,e;
    a=b=c=d=e=0;
    scanf("%d",&n);

    if (n<=9){
        printf("1\n%d\n%d\n",n,n);

    }
    else if (n<=99){
        a=n/10;
        b=n-10*a;
        printf("2\n%d%d\n%d%d\n",a,b,b,a);
    }
    else if (n<=999){
        a=n/100;
        b=(n-100*a)/10;
        c=n%10;
        printf("3\n%d%d%d\n%d%d%d\n",a,b,c,c,b,a);

    }
    else if (n<=9999){
        a=n/1000;
        b=n%1000/100;
        c=n%1000%100/10;
        d=n%10;
        printf("4\n%d%d%d%d\n%d%d%d%d\n",a,b,c,d,d,c,b,a);

    }
    else{
        a=n/10000;
        b=n%10000/1000;
        c=n%10000%1000/100;
        d=n%10000%1000%100/10;
        e=n%10;
        printf("5\n%d%d%d%d%d\n%d%d%d%d%d\n",a,b,c,d,e,e,d,c,b,a);
    }
    return 0;
}
