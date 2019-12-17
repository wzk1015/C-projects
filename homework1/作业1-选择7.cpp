#include<stdio.h>
int main()
{
	char c1,c2,c3,c4,c5,c6;
    scanf("%c%c%c%c",&c1,&c2,&c3,&c4);
	printf("%d\n",c1);
	c5=getchar();
	c6=getchar();
	putchar(c1);
	putchar(c2);
	printf("%c%c\n",c5,c6);
}