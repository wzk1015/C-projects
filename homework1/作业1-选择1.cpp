#include <stdio.h>
int main()
{
	char a='a';
	float b=2.3;
	double c=41;
	int d;
	d = a+b+c;
	int e= sizeof(d);
	printf("e=%d",e);
	return 0;
}