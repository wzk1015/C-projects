#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length,position;
char s1[100],s2[100];
typedef struct wzk {
    char aux[100];
    int order;
}wzk;
wzk a[100];

void MakeAux()
{
    int i;
    char temp[2];
    strcpy(a[0].aux,s1);
    a[0].order=0;
    for (i=1;i<length;i++)  //¹¹Ôì¸¨Öú×Ö·û´®a[length]
    {
        a[i].order=i;
        strcpy(a[i].aux,a[i-1].aux+1);
        temp[0]=(a[i-1].aux)[0];
        temp[1]='\0';
        strcat(a[i].aux,temp);
    }
    position=1;
}

void Rank (int num_words)
{
    int i,j,min;
    wzk temp;

    for(i=0;i<num_words;i++)
	{
		min=i;
		for(j=i+1;j<num_words;j++)
			if( a[min].aux[0] > a[j].aux[0] || ( a[min].aux[0]==a[j].aux[0] && a[min].order>a[j].order ) )
				min=j;

		if(min!=i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			if (i==position)
                position = min;
            else if (min==position)
                position = i;
		}
	}
}

void MakeS2 (int length)
{
    int i;
    for (i=0;i<length;i++)
        s2[i]=a[i].aux[length-1];
    s2[length]='\0';
}


int main()
{
    FILE *in,*out;
    in = fopen("filezip.in","r");
    out = fopen("filezip.out","w");

    fscanf(in,"%d %s",&length,s1);
    MakeAux();
    Rank(length);
    MakeS2(length);
    fputs(s2,out);
    fprintf(out,"\n%d",position+1);

    return 0;
}


//前面是用结构体做的，后面是二维数组


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length,position;
char s1[100],s2[100];
char a[100][100];

void MakeAux()
{
    int i;
    char temp[2];
    strcpy(a[0],s1);
    for (i=1;i<length;i++)  //¹¹Ôì¸¨Öú×Ö·û´®a[length]
    {
        strcpy(a[i],a[i-1]+1);
        temp[0]=a[i-1][0];
        temp[1]='\0';
        strcat(a[i],temp);
    }
    position=1;
}

void Rank (int num_words)
{
    int i,j,min;
    char temp[100];

    for(i=0;i<num_words;i++)
	{
		min=i;
		for(j=i+1;j<num_words;j++)
			if( a[min][0] > a[j][0] || ( a[min][0]==a[j][0] && min>j ) )
				min=j;

		if(min!=i)
		{
			strcpy(temp,a[i]);
			strcpy(a[i],a[min]);
			strcpy(a[min],temp);
			if (i==position)
                position = min;
            else if (min==position)
                position = i;
		}
	}
}

void MakeS2 (int length)
{
    int i;
    for (i=0;i<length;i++)
        s2[i]=a[i][length-1];
    s2[length]='\0';
}

int main()
{
    FILE *in,*out;
    in = fopen("filezip.in","r");
    out = fopen("filezip.out","w");

    fscanf(in,"%d %s",&length,s1);
    MakeAux();
    Rank(length);
    MakeS2(length);
    fputs(s2,out);
    fprintf(out,"\n%d",position+1);

    return 0;
}
*/






