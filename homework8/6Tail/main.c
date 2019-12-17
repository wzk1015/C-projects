#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[100][100];
int n_lines;

void input(FILE *fp)
{
    int i=0,j=0;
    char ch;
    while ( (ch=fgetc(fp)) != EOF )
    {
        if (ch!='\n')
            a[i][j++]=ch;
        else
        {
            a[i][j]='\0';
            i++;
            j=0;
        }
    }
    a[i][j]='\0';
    n_lines=i+1;
}

void output(int num)
{
    int i;
    for (i=n_lines-num-1;i<n_lines;i++)
        puts(a[i]);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    int num;
    if (strlen(argv[1])==1)
        num=10;
    else
        num = atoi(argv[1]+1);
    fp = fopen (argv[2],"r");

    input(fp);
    output(num);
    return 0;
}
