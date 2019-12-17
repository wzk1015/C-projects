#include<stdio.h>
#define Max(x,y) (x>y?x:y)
int main ()
{
	int max,d[10000],i,j;
	char a[10000];
	gets(a);
	d[0]=1;
	for(i=1;a[i]!='\0';i++)
	{
		d[i]=1;
		for(j=0;j<i;j++)
		{
			if(a[i]>=a[j])
			{
				if(d[i]<d[j]+1)
				{
					d[i]=d[j]+1;
				}
			}
		}
	 } 
	 max=d[0];
	for(i=1;a[i]!='\0';i++)
	{
		max=Max(max,d[i]);
		
	} 
	printf("%d\n",max);
	
	return 0;
 } 

