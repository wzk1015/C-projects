#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct telsort
{
    char name[11];
    char tel[11];
}telsort;

telsort list[60];

void Input (telsort list[],int n)
{
    char temp[100];
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%s",temp);
            strncpy(list[i].name,temp,10);
        list[i].name[10]='\0';
        scanf("%s",temp);
            strncpy(list[i].tel,temp,10);
        list[i].tel[10]='\0';
    }
}

void Output(telsort list[],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for ( j=1; j<=12-strlen(list[i].name); j++)
            printf(" ");
        printf("%s",list[i].name);
        for ( j=1; j<=12-strlen(list[i].tel); j++)
            printf(" ");
        printf("%s\n",list[i].tel);
    }
}


void Rank(telsort list[], int n)
{
    int i,j,min;
    telsort temp;

    for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if( strcmp(list[min].name,list[j].name) > 0)
				min=j;

		if(min!=i)
		{
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}
}

int main()
{
    int num;
    scanf("%d",&num);
    Input(list,num);
    Rank(list,num);
    Output(list,num);
    return 0;
}

