#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[])
{
    int temp,i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}

void itoh(unsigned n,int b,char s[])
{
    int h,i=0;
    do{
    h=n%b;
    s[i++]=(h<=9)?h+'0':h+'a'-10;
    }while((n/=b)!=0);
    s[i]='\0';
    reverse(s);
}




int main()
{
    int b,n;
    char s[100];
    scanf("%d %d",&n,&b);
    if (n>0)
    {
        itoh(n,b,s);
        puts(s);
    }
    else
    {
        itoh((-1)*n,b,s);
        printf("-");
        puts(s);
    }
    return 0;
}
