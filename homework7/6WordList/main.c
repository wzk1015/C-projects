#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wzk {
    int line;
    int colm;
    char word[30];
}wzk;
wzk a[300];

int Input(FILE *in)
{
    int i=1,j=0,k=0;
    char ch;
    a[0].line=1;
    a[0].colm=1;
    while ( (ch=fgetc(in)) != EOF )
    {
        if (ch!=' ' && ch!='.' && ch!='\n' && ch!=',')
            (a[k].word)[j++]=ch;
        else if (ch==' '|| ch==',')
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

void Rank (int num_words)
{
    int i,j,min;
    wzk temp;

    for(i=0;i<num_words;i++)
	{
		min=i;
		for(j=i+1;j<num_words;j++)
			if( strcmp(a[min].word,a[j].word) > 0 || (strcmp(a[min].word,a[j].word)==0 && a[min].line> a[j].line) || (strcmp(a[min].word,a[j].word)==0 && a[min].line== a[j].line && a[min].colm> a[j].colm))
				min=j;

		if(min!=i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

int isword (char s[])
{
    int i;
    if (s[0]=='-'||s[0]=='\0')
        return 0;
    for (i=0;s[i]!='\0';i++)
    {
        if (s[i]=='-')
            continue;
        if (s[i]<'A'||s[i]>'z'|| (s[i]>'Z' && s[i]<'a') )
            return 0;
    }
    return 1;
}

void Output (FILE *out, int num_words)
{
    int i;
    for (i=0;i<num_words;i++)
    {
        if (strcmp(a[i].word,"a")==0||strcmp(a[i].word,"an")==0||strcmp(a[i].word,"the")==0||strcmp(a[i].word,"and")==0)
            continue;
        if ( isword(a[i].word)==0 )
            continue;
        fprintf(out,"%s:(%d,%d)",a[i].word, a[i].line, a[i].colm);
        while (strcmp(a[i+1].word, a[i].word) == 0)
        {
            fprintf(out,",(%d,%d)",a[i+1].line, a[i+1].colm);
            i++;
        }
        fputc('\n',out);
    }
}

int main()
{
    FILE *in,*out;
    int num_words;

    in = fopen("crossin.txt","r");
    out = fopen("crossout.txt","w");

    num_words=Input(in);
    Rank(num_words);
    Output(out,num_words);
    return 0;
}

