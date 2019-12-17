#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d1,d2;
    char op;
    scanf("%d %d %c",&d1,&d2,&op);
    if (op=='+'){
    printf("%d\n",d1+d2);
    }
     if (op=='-'){
    printf("%d\n",d1-d2);
    }
     if (op=='*'){
    printf("%d\n",d1*d2);
    }
    if (op=='/'){
            if (d1%d2==0)
            printf("%d\n",d1/d2);
            else
            printf("%.2f\n",(double)d1/d2);
    }
    return 0;
}
