#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,max_c=0;
    char a[26],b[500];      //a[i]Ϊ��i+1����ĸ��b[i]Ϊ����ĵ�i+1���ַ�
    int c[26];              //c[i]Ϊa[i]���ִ���
    for (i=0;i<26;i++)      //��ʼ��a��c
    {
        a[i]=i +'a';
        c[i]=0;
    }

    i=0;
    while ((b[i]=getchar())!=EOF) //����b
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
