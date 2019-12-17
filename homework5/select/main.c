#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*    index(char s[],char t[])
{
    int i,j,k;
    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0; t[k]!='\0'&&s[j]==t[k];j++,k++)
            ;
        if(t[k]=='\0')
            return (i);
    }
    return (-1);
}*/

/*squeez(char s[],char c)
    {
        int i,j;
        for(i=j=0;s[i]!='\0';i++)
            if(s[i]!=c)
                s[j++]=s[i];
        s[j]='\0';
    }*/

/*void itoh(unsigned n,char s[])
{
    int h,i=0;
    do{
        h=n%16;
        s[i++]=(h<=9)?h+'0':h+'A'-10;
    }while((n/=16)!=0);
    s[i]='\0';
    reverse(s);
}

void reverse(char s[])
{
    int temp,i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}*/

/*long fib(int x)
{
    switch(x)
    {
        case 0: return 0;
        case 1: case 2:  return 1;
    }
    return (fib(x-1)+fib(x-2));
}*/

/*int try(int n)
    {
        if(n>0)
            return ( n*try(n-2));
        else
            return (1);
    }*/

int main()
{
    //int x;
    //x = try(5);
    //printf("%d\n",x);

    /*40231
    44231
    04231
    04431
    00431
    02431*/



    int a[]={4,0,2,3,1},i,j,t;
    for(i=1;i<5;i++)
    {
        t=a[i];j=i-1;
        while(j>=0&&t>a[j])//< >
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    for (i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }

    /*int k=2;
    switch(k)
    {
        case 1:printf("%d",k++);
            break;
        case 2:printf("%d",k++);
        case 3:printf("%d",k++);
            break;
        case 4:printf("%d",k++);
        default:printf("Full!");
    }*/

    //char c[]="\t\v\\\0will\n";
    //    printf("%d",strlen(c));

    /*    Ìî¿Õ1£º
    (A)c[k++]=a[i++];
    (B)c[k++]=a[j++];
    (C)c[k++]=b[i++];
    (D)c[k++]=b[j++];
        Ìî¿Õ2£º
    (A)c[k++]=a[i++];
    (B)c[k++]=a[j++];
    (C)c[k++]=b[i++];
    (D)c[k++]=b[j++];
        Ìî¿Õ3£º
    (A)a[i]=='\0'
    (B)a[i]!='\0'
    (C)b[j]=='\0'
    (D)b[j]!='\0'*/

    /*char a[]="acegikmort";
    char b[]="bdfhjlnpqs";
    char c[80],*p;
    int i=0,j=0,k=0;
    while(a[i]!='\0'&&b[j]!='\0')
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    c[k]='\0';
    if (b[j]!='\0')
        p=b+j;
    else
        p=a+i;
    strcat(c,p);
    puts(c);*/

    /*int x=6;
    printf("%d\n",fib(x));*/

    /*char s[100],c;
    gets(s);
    scanf("%c",&c);
    squeez(s,c);
    puts(s);*/

    /*char s[100];
    int n;
    scanf("%d",&n);
    itoh(n,s);
    puts(s);*/

    /*while(1)
    {
        char s[100],t[100];
        gets(s);
        gets(t);
        printf("%d\n",index(s,t));
    }*/


    return 0;
}
