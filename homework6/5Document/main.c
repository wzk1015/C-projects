#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char a[])
{
    int c,i,j;
    for (i=0,j=strlen(a)-1;i<j;i++,j--)
    {
        c=a[i];
        a[i]=a[j];
        a[j]=c;
    }
}

int find(char singleline[])
{
    int j;
    for (j=0;j<strlen(singleline);j++)
            if (singleline[j]==':')
                return j;
    return 0;
}

void output(char s2[][200], int n)
{
    int i;
    for (i=0;i<n;i++)
        puts(s2[i]);
}

int inputlines(char line[][200])
{
    int i=0,j=0;
    while ( (line[i][j]=getchar()) != EOF)
    {
        if (line[i][j]=='\n')
        {
            line[i][j]='\0';
            j=0;
            i++;
        }
        else
            j++;
    }
    return i;
}

void reorganize(char s1[][200], char s2[][200], int n, int new_pos)
{
    int i,j=0,k=0,old_pos[n];
    char space[]="                                                                                                              ";
    //space里面全是空格，用于补齐空格
    for (i=0;i<n;i++)   //找每行原始冒号位置
        old_pos[i]=find(s1[i]);

    for (i=0;i<n;i++)   //整理冒号前空格和tab
    {
        while (s1[i][j]==' '||s1[i][j]=='\t')
        j++;//将第一个单词前的空格和tab去掉
        while (s1[i][j]!=':')
        {
            if (s1[i][j]!='\t')
                s2[i][k++]=s1[i][j];
            else
                s2[i][k++]=' ';
            if (s1[i][j]==' '||s1[i][j]=='\t')
            {
                while((s1[i][j])==' '||(s1[i][j])=='\t')
                    j++;
            }
            else
                j++;
        }
        s2[i][k]='\0';
        j=0,k=0;
    }

    for (i=0;i<n;i++)   //补齐空格
    {
        reverse(s2[i]);
        if (s2[i][0]!=' ')//reverse之后冒号前一项变为第一项
        {
            strncat(s2[i], space, new_pos - strlen(s2[i])-1 );
            s2[i][new_pos-1]='\0';
            reverse(s2[i]);
            s2[i][new_pos-1]=' ';
        }
        else    //冒号前已有一个空格
        {
            strncat(s2[i], space, new_pos - strlen(s2[i]) );
            s2[i][new_pos]='\0';
            reverse(s2[i]);
        }
        s2[i][new_pos]=':';
        s2[i][new_pos+1]=' ';
    }

    for (i=0;i<n;i++)   //整理冒号后空格和tab
    {
        k=new_pos+2;
        j=old_pos[i]+1;
        while (s1[i][j]==' '||s1[i][j]=='\t')
            j++;//将第一个单词前的空格和tab去掉
        while (s1[i][j]!='\0')
        {
            if (s1[i][j]!='\t')
                s2[i][k++]=s1[i][j];
            else
                s2[i][k++]=' ';
            if (s1[i][j]==' '||s1[i][j]=='\t')
            {
                while((s1[i][j])==' '||(s1[i][j])=='\t')
                    j++;
            }
            else
                j++;
        }
        s2[i][k]='\0';
    }

}

int main()
{
    int n,new_pos;         //n为行数
    char s1[100][200],s2[100][200]; //s1读入，s2输出

    scanf("%d ",&new_pos);
    new_pos--;
    n=inputlines(s1);
    reorganize(s1,s2,n,new_pos);

    output(s2,n);
    return 0;
}
