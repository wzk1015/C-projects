#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*int wordcmp(char p1[], char p2[])
{
    int i;
    for (i=0; p1[i]!='\0' && p2[i]!='\0' ;i++)
    {
        if ( p1[i] < p2[i] )
            return 1;               //1代表第一个字符串小于第二个字符串
        else if ( p1[i] > p2[i] )
            return 0;
    }
    if ( p1[i] == '\0' && p2[i] != '\0')
        return 1;
    else if ( p1[i] != '\0' && p2[i] == '\0')
        return 0;
    else        //两个相等
        p1[0]='\0';

    return -1;
}*/

void output(char a[][50], FILE *out, int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;a[j]!='\0';j++)
        {
            fputc(a[i][j],out);
        }
        fputc(' ',out);
    }
}

int read(char a[][50], FILE *in)
{
    int i=0,j=0;
    while ( (a[i][j] = fgetc(in)) != EOF)
    {
        if (a[i][j]==' '|| a[i][j]=='\n')
        {
            a[i][j]='\0';
            j=0;
            i++;
        }
        else
            j++;
    }
    return i;
}

void rank (char s1[][50], int n)
{
    int i,j;
    char t[50];
    for (i=1;i<n;i++)
    {
        strcpy(t,s1[i]);
        //t[ strlen(s1[i]) ] ='\0';
        j=i-1;
        while ( j>0 && (wordcmp(t,s1[j])==1) )
        {
            strcpy(s1[j+1],s1[j]);
            j--;
        }

        strcpy(s1[j+1],t);
        //s1[j+1][strlen(t)]='\0';
    }
}

int main(int argc, char *argv[])
{
    int n;
    FILE *in, *out;
    char s1[50][50];

    in = fopen (argv[1],"r");
    out = fopen (argv[2],"w");

    n=read(s1,in);
    rank(s1,n);
    output(s1,out,n);
    fclose(out);
    fclose(in);
    return 0;
}
