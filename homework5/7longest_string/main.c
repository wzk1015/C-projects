#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[10001],b[10001];
int a[10001];    //c[10001] a为b子串中元素在s中的位置 c[i]标志s[i]是否已用
int max_len=0,n;

void find(int index, int m)  //遍历1~n的所有含有n个元素的子集，等价于遍历s的所有子串
{                               //index:当前下标 n:在剩下的数中取出n个
    int i,j;

    if (m==1)
    {                           //要在剩下数种取出1个
        for (i=index; i<strlen(s); i++)
        {
            if (s[i]>=s[i-1])
            {
                a[i]=1;
                for (i=0,j=0; i<strlen(s); i++)
                    if (a[i]==1)
                        b[j++]=s[i];
                b[j]='\0';
                max_len=(strlen(b)>max_len?strlen(b):max_len);
                a[i]=0;
            }
        }
    }
    else {                      //当要在剩下数中取出2个及以上时用递归
        for (i=index; i<strlen(s); i++)
        {
            if (m==n)
            {
                a[i]=1;
                find(i+1,m-1);
                a[i]=0;
            }
            else if (s[i]>=s[i-1])
            {
                a[i]=1;
                find(i+1,m-1);
                a[i]=0;
            }
        }
    }
}


int main()
{
    gets(s);
    for (n=1;n<=strlen(s);n++)
        find(0,n);

    printf("%d\n",max_len);
    return 0;
}
/*void longstr()
{
    int i,j;

    for (i=0;s[i+1]!='\0';i++) //遍历子串的首个字符
    {
        m=0;
        b[m++]=s[i];
        for (j=i+1;s[j]!='\0';j++)
        {
            if (s[j]>=b[m-1])
            {
                b[m++]=s[j];
            }
        }
        b[m]='\0';
        if (m>max_len)
            max_len=strlen(b);
    }
}*/



/*void FindLongstr(char s[],int a[],int c[],int n,int max_len)//n为当前子串要找的第n个数
{
    int i,j;

    if (n)
    for (i=a[n-1];i<strlen(s);i++)
    {
        if (s[i]>b[n-1])
        {
            c[i]=1;
            FindLongstr(s,a,c,n+1,max_len);
            c[i]=0;
        }
    }
}*/


