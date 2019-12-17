#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int num=1;
char word[100][30]={{0}};

void input()
{
    int i=0,num=1;
    char ch;
    scanf("%s",word[i++]);
    while( (ch=getchar()) == ' ' || ch == '\n' )
    {
        scanf("%s",word[i++]);
        num++;
    }
}


int judge(char a[],char b[])
{
    int i,j,m1,m2;
    m1 = strlen(a);
    m2 = strlen(b);
    j= m1 > m2 ? m2 : m1;
    for(i=0;i<j;i++)
    {
        if(a[i]>b[i])
            return 1;
        if(a[i]<b[i])
            return -1;
    }
    if(m1==m2)
        return 0;
    else return m1-m2;
}


void rank()
{
    int i,j;
    char temp[20];
    for(i=num-1;i>=0;i--)
        for(j=0;j<i-1;j++)
        {    if(judge(word[j],word[j+1])>0)
                {
                    strcpy(temp,word[j]);
                    strcpy(word[j],word[j+1]);
                    strcpy(word[j+1],temp);
                }
       }
}

void output(FILE *fp)
{
    int i,num;
    fprintf(fp,"%s ",word[0]);
    for(i=1;i<num;i++)
        if( judge (word[i],word[i-1]) != 0 )
            fprintf(fp,"%s ",word[i]);
}

int main(/*int argc, char* argv[]*/)
{

    FILE *fp;
    freopen(/*argv[1]*/"sort.in","r",stdin);
    fp=fopen(/*argv[2]*/"sort.out","w+");

    input(word);
    rank();
    output(fp);
    fclose(fp);
    return 0;
   }
