#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[100],b[100],c[100];

void strbin(char a[], char b[])
{
    int i,j,k;
    for (i=0,j=0,k=0; a[i]!='\0'&&b[j]!='\0'; )
    {
        if (a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(b[j]!='\0')
    {
            c[k++]=b[j++];
    }
    while(a[i]!='\0')
    {
            c[k++]=a[i++];
    }
    c[k]='\0';
    strcpy(a,c);
    a[k]='\0';
}


int main()
{
    gets(a);
    gets(b);
    strbin(a,b);
    puts(a);
    return 0;
}
