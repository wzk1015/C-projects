#include <stdio.h>
#include <stdlib.h>

int op(char m,int x,int y)
{
    switch (m)
    {
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
    }
    return 0;
}

int main()
{
    int n1,n2,tmp;
    char op1,op2;

    scanf("%d",&n1);
    while((op1=getchar())==' ');

while ( op1 != '=' )
{
    scanf("%d",&n2);
    if (op1=='*'||op1=='/')
    {
        n1 = op(op1, n1, n2);
        while((op1=getchar())==' ');
    }

    else // (op1=='+'||op1=='-')
    {
        while ( (op2=getchar()) =='*' || op2=='/' || op2==' ')
        {
            if (op2==' ')
                continue;
            scanf("%d",&tmp);
            n2 = op(op2, n2, tmp);
        }
            n1 = op(op1, n1, n2);
        op1 = op2;
    }
}

printf("%d",n1);
    return 0;
}
