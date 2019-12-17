#include <stdio.h>
#include <stdlib.h>

/*int op(char m,int x,int y)
{
    switch (m)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
    }
}
*/

int main()
{
    char a[100],c;
    int b[100],n,i,j,result=0;


    for (i=0;i<100;i++)         //依次读入整数，运算符，整数，运算符，得到b0,a0,b1,a1,b2,a2……
    {
        if (i%2==0)
            scanf("%d",&b[i/2]);
        else
        {
            if ((c=getchar())!=' ')
            {
                a[(i-1)/2]=c;
                //scanf("%c",&a[(i-1)/2]);
                if (a[(i-1)/2]=='=')
                    break;
            }

            else
                i--;
        }
    }

    n=i;                            //计算数组元素个数

    for (i=0;i<(n-1)/2;i++)         //先进行乘除运算
    {
        if (a[i]=='*')
        {
            b[i+1]=b[i]*b[i+1];         //把结果赋给后一个数
            b[i]=-233;                  //把前一个数赋为-233（后续运算时可筛掉该数）
        }

        else if (a[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
            b[i]=-233;
        }
    }

    for (i=0;i<(n-1)/2;i++)         //再进行加减运算
    {
        if (a[i]=='+')              //加法运算
        {
            for (j=i;j>=0;j--)          //从加号前面寻找第一个有效的数（即不为-233）作为被加数
            {
                if (b[j]!=-233)
                {
                    b[i]=b[j];          //把被加数赋给加号前的第一个数
                    if (i!=j)           //若该有效数不是加号前的数，要把其原位置变为-233防止影响运算
                        b[j]=-233;
                    break;
                }
            }

            for (j=i+1;j<=(n-1)/2;j++)
            {
                if (b[j]!=-233)
                {
                    b[i+1]=b[j];        //同理寻找加数，赋给加好后的第一个数
                    if ((i+1)!=j)
                        b[j]=-233;
                    break;
                }
            }
            b[i+1]=b[i]+b[i+1];
        }

        else if (a[i]=='-')         //同理减法运算
        {
            for (j=i;j>=0;j--)
            {
                if (b[j]!=-233)
                {
                    b[i]=b[j];
                    if (i!=j)
                        b[j]=-233;
                    break;
                }
            }

            for (j=i+1;j<=(n-1)/2;j++)
            {
                if (b[j]!=-233)
                {
                    b[i+1]=b[j];
                    if ((i+1)!=j)
                        b[j]=-233;
                    break;
                }
            }
            b[i+1]=b[i]-b[i+1];

        }
    }


    //输出结果

    for (i=(n-1)/2;i>=0;i--)        //从后往前寻找第一个有效数作为结果
        if (b[i]!=-233)
        {
            result=b[i];
            break;
        }
    printf("%d",result);

    return 0;
}
