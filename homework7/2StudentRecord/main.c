#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
    int id;
    char name[10];
    int age;
}temp,list[60];

void output(struct stu list[],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        printf("%3d",list[i].id);
        for ( j=1; j<=6-strlen(list[i].name); j++)
            printf(" ");
        printf("%s",list[i].name);
        printf("%3d\n",list[i].age);
    }
}


void NameRank(struct stu list[], int n)
{
    int i,j,min;

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

    output(list,n);

}

void AgeRank(struct stu list[], int n)
{
    int i,j,min;

    for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if( list[min].age>list[j].age || (list[min].age==list[j].age && strcmp(list[min].name,list[j].name)==1 ) )
				min=j;

		if(min!=i)
		{
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}

    output(list,n);
}

int main()
{
    int num_stu,i;
    scanf("%d",&num_stu);

    for (i=0;i<num_stu;i++)
        scanf("%d %s %d", &list[i].id, list[i].name, &list[i].age);
    NameRank(list,num_stu);
    printf("\n");
    AgeRank(list,num_stu);

    return 0;
}


