#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wzk {
    int line;
    int colm;
    char word[30];
}wzk;
wzk a[300];
char intlist[15][25];
int num_intlist;

int Input(FILE *in)
{
    int i=1,j=0,k=0;
    char ch;
    a[0].line=1;
    a[0].colm=1;
    while ( (ch=fgetc(in)) != EOF )
    {
        if (ch!=' ' && ch!='\n' && ch!='\t')
            (a[k].word)[j++]=ch;
        else if (ch==' '|| ch=='\t')
        {
            (a[k].word)[j]='\0';
            j=0;
            k++;
            a[k].line=i;
            a[k].colm = a[k-1].colm + strlen(a[k-1].word) +1;
        }
        else if (ch=='\n')
        {
            (a[k].word)[j]='\0';
            j=0;
            k++,i++;
            a[k].line=i;
            a[k].colm=1;
        }
    }
    return k+1;
}

int isintlist (char s[])
{
    int i;
    for (i=0;i<num_intlist;i++)
        if ( strcmp(s,intlist[i]) == 0 )
            return 1;
    return 0;
}

void Output (FILE *out, int num_words)
{
    int i;
    for (i=0;i<num_words;i++)
    {
        if ( isintlist(a[i].word)==1 )
            continue;
        fprintf(out,"%s",a[i].word);
    }
}

int MakeIntList(int num_words)
{
    int i,j,k=0;
    for (i=0;i<num_words;i++)
    {
        if (strcmp(a[i].word,"int")==0)
        {
            for (j=i+1;strcmp(a[j].word,";")!=0;j++)
            {
                if (strcmp(a[j].word,",")==0)
                    continue;
                strcpy(intlist[k++],a[j].word);
            }
        }
    }
    return k;
}

int main()
{
    FILE *in,*out;
    int num_words;

    in = fopen("input.c","r");    //别忘了把这里的.txt改成.c
    out = fopen("output.c","w");

    num_words=Input(in);
    num_intlist=MakeIntList(num_words);
    Output(out,num_words);
    return 0;
}

