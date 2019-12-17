#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wzk {
    int line;
    int colm;
    char word[30];
}wzk;
wzk a[3000];

int Input(FILE *in)
{
    int i=1,j=0,k=0;
    char ch;
    a[0].line=1;
    a[0].colm=1;
    while ( (ch=fgetc(in)) != EOF )
    {
        if (ch!=' ' && ch!='.' && ch!='\n' && ch!=',' && ch!='(' && ch!=';' && ch!=')' && ch!='\t' && ch!= '{')
            (a[k].word)[j++]=ch;
        else if (ch==' '|| ch==',' || ch=='(' || ch==';' || ch==')' || ch == '\t' || ch=='{')
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
            //
            //
            //
        }
    }
    return k+1;
}

int Iskeyword(char s[],int pos)
{
    int i,j,num=0;  //num统计该单词前双引号的数量
    for (i=0;i<pos;i++)
        if (strchr(a[i].word,'"')!=0)
            for(j=0;a[i].word[j]!='\0';j++)
                if (a[i].word[j]=='"')
                    num++;

    if (num%2==1)   //说明该字符在字符串中
        return 0;

    if (strcmp(s,"for")==0 || strcmp(s,"while")==0 || strcmp(s,"if")==0)
        return 1;
    return 0;
}

void Output (int num_words)
{
    int i;
    for (i=0;i<num_words;i++)
    {
        if ( Iskeyword(a[i].word,i)==0 )
            continue;
        printf("%s:%d,%d",a[i].word, a[i].line, a[i].colm);
        putchar('\n');
    }
}

int main()
{
    FILE *in;
    int num_words;

    in = fopen("in.c","r");
    num_words=Input(in);
    Output(num_words);
    return 0;
}

/*
    if (strstr(s,"if(")!=0)
    {
        strcpy(s,"if");
        return 1;
    }
    if (strstr(s,"for(",4)!=0)
    {
        strcpy(s,"for");
        return 1;
    }
    if (strstr(s,"while(",6)==0)
    {
        strcpy(s,"while");
        return 1;
    }
*/
