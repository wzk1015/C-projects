#include <stdio.h>
#include <stdlib.h>

struct stu
{
    int id;
    char name[10];
    int age;
};

int NameCmp(char *p1,char *p2)
{
    while(1)
    {
        if (*p1>*p2)
            return 1;
        if (*p1<*p2)
            return -1;
        p1++;
        p2++;
    }
}

void NameRank(struct stu list[], int n)
{
    int i,j,min;
    struct stu temp;

    for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if( NameCmp(list[min].name,list[j].name) == 1)
				min=j;

		if(min!=i)
		{
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}

    for (i=0;i<n;i++)
        printf("%d %s %d\n",list[i].id, list[i].name, list[i].age);

}

void AgeRank(struct stu list[], int n)
{
    int i,j,min;
    struct stu temp;

    for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if( list[min].age>list[j].age )
				min=j;

		if(min!=i)
		{
			temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
	}

    for (i=0;i<n;i++)
        printf("%d %s %d",list[i].id, list[i].name, list[i].age);
}

void main()
{
    int num_stu,i,k;
    char ch;
    struct stu list[60];
    scanf("%d",&num_stu);

    for (i=0;i<num_stu;i++)
    {
        k=0;
        scanf("%d", &list[i].id);
        getchar();
        while ( ch=getchar() != ' ');
            (list[i].name)[k++]=ch;
        list[i].name[k]='\0';
        scanf("%d", &list[i].age);
    }
    //NameRank(list,num_stu);
    //printf("\n");
     for (i=0;i<num_stu;i++)
     {
        printf("%d ",list[i].id);
        for (k=0;(list[i].name)[k]!='\0';k++)
            putchar((list[i].name)[k]);
        printf(" %d\n",list[i].age);
     }
    //AgeRank(list,num_stu);

}


/*int agecmp(const struct stu *p1, const struct stu *p2)
{
    return (int)( p1->age - p2->age);
}


int namecmp(const struct stu *p1, const struct stu *p2)
{
    char *t1=p1->name;
    char *t2=p2->name;
    while(1)
    {
        if (*t1>*t2)
            return 1;
        if (*t1<*t2)
            return -1;
        t1++;
        t2++;
    }

}*/
