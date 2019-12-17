#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wzk {
    int times;  //默认初始化为0
    char word;
    int order;
}wzk;
wzk a[1000];

int Input()
{
    int i=0;
    while ( (a[i].word=getchar()) != '\n' )
    {
        a[i].order=i;
        i++;
    }
    return i;
}

void AsciiRank (int num_words)
{
    int i,j,min;
    wzk temp;

    for(i=0;i<num_words;i++)
	{
		min=i;
		for(j=i+1;j<num_words;j++)
			if( a[min].word > a[j].word)
				min=j;

		if(min!=i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

void TimesRank (int num_words)
{
    int i,j,min;
    wzk temp;
    for (i=0;i<num_words;i++)
    {
        a[i].times=1;
        j=i;
        while (a[i+1].word==a[i].word)
        {
            a[j].times++;
            if ( a[i+1].order > a[i].order )
                a[i+1].order=a[i].order;
            else
                a[i].order=a[i+1].order;
            i++;
        }
    }

    for(i=0;i<num_words;i++)
	{
		min=i;
		for(j=i+1;j<num_words;j++)
        {
			if( a[min].times < a[j].times ) //不合并是为了方便调试233
				min=j;
            else if ( a[min].times == a[j].times && a[min].order > a[j].order )
                min=j;
        }

		if(min!=i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

void Output (int num_words)
{
    int i;
    for (i=0;i<num_words;i++)
    {
        if (a[i].times==0)
            break;
        printf("%c-%d",a[i].word,a[i].times);
        if (i%4!=3)
            putchar(' ');
        else
            putchar('\n');
    }
}

int main()
{
    int num_words;
    num_words=Input();
    AsciiRank(num_words);
    TimesRank(num_words);
    Output(num_words);
    return 0;
}

/*
int main()
{
    Input();

}*/
