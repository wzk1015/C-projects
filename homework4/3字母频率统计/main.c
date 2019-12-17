#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,max_c=0;
    char a[26],b[500];      //a[i]为第i+1个字母，b[i]为输入的第i+1个字符
    int c[26];              //c[i]为a[i]出现次数
    for (i=0;i<26;i++)      //初始化a、c
    {
        a[i]=i +'a';
        c[i]=0;
    }

    i=0;
    while ((b[i]=getchar())!=EOF) //输入b
      i++;
    b[i+1]='\0';
    n=i+1;

    for (i=0;i<26;i++)
    {
        for(j=0;j<n;j++)
        {
            if (b[j]=='\n')
                continue;
            if (b[j]==a[i])
                c[i]++;
        }
        if (max_c<c[i])
            max_c=c[i];
    }


    for(i=max_c;i>0;i--)
    {
        for (j=0;j<26;j++)
        {
            if (c[j]<i)
            {
                printf(" ");
                continue;
            }
            if (c[j]>=i)
                printf("*");
        }
        printf("\n");
    }

    printf("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}
