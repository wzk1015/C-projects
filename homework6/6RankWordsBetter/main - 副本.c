#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int num=1;
char word[100][30]={{0}};

void input()
{
    int i=0;
    char ch;
    scanf("%s",word[i++]);
    while( (ch=getchar()) == ' ' || ch == '\n' )
    {
        scanf("%s",word[i++]);
        num++;
    }
}

void rank()
{
    int i,j;
    char temp[20];
    for(i=num-1;i>=0;i--)
        for(j=0;j<i-1;j++)
        {    if(strcmp(word[j],word[j+1])>0)
                {
                    strcpy(temp,word[j]);
                    strcpy(word[j],word[j+1]);
                    strcpy(word[j+1],temp);
                }
       }
}

void output(FILE *fp)
{
    int i;
    fprintf(fp,"%s ",word[0]);
    for(i=1;i<num;i++)
        if( strcmp (word[i],word[i-1]) != 0 )
            fprintf(fp,"%s ",word[i]);
}

int main(int argc, char* argv[])
{

    FILE *fp;
    freopen(argv[1],"r",stdin);
    fp=fopen(argv[2],"w+");

    input(word);
    rank();
    output(fp);
    fclose(fp);
    return 0;
   }

