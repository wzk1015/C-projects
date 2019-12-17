#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[])
{
    char temp;
    int i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }

}

void subtract(char a[], char b[], char c[])
{
    int i,m;
    int carry[81];

    if (strlen(a)==strlen(b))
    {
        for (i=0;i<strlen(a);i++)
        {
            m=a[i]-b[i]-carry[i];
            if (m>=0&&i<strlen(a)-1)
                c[i]=m+'0';
            else if (m>=0&&i==strlen(a)-1)
            {
                c[i]=m+'0';
                c[i+1]='\0';
            }
            else if (i<strlen(a)-1) //m<0,i<n_a-1
            {
                c[i]=10+m+'0';
                carry[i+1]=1;
            }
            else    //m<0,i=n_a-1
            {
                c[i]=-m+'0';
                c[i+1]='-';
                c[i+2]='\0';
            }
        }

    }

    else if (strlen(a)>strlen(b))
    {
        b[strlen(b)]='0';
        for (i=0;i<strlen(a);i++)
        {
            m=a[i]-b[i]-carry[i];
            if (m>=0&&i<strlen(a)-1)
                c[i]=m+'0';
            else if (m>=0&&i==strlen(a)-1)
            {
                c[i]=m+'0';
                c[i+1]='\0';
            }
            else // m<0&&i<n_a-1  因为i=n_a-1时m必定>0
            {
                c[i]=10+m+'0';
                carry[i+1]=1;
            }
        }
    }
    reverse(c);
}

int main()
{
    char a[81], b[81],c[81];
    int i;
    for (i=0;i<81;i++)
        a[i]=b[i]='0';

    gets(a);
    gets(b);
    reverse(a);
    reverse(b);

    if (strlen(a)>strlen(a))
        subtract(a,b,c);
    else if (strlen(a)<strlen(b))
    {
        subtract(b,a,c);
        putchar('-');
    }
    else
    {
        for (i=strlen(a)-1;i>=0;i--)
        {
            if (a[i]>b[i])
            {
                subtract(a,b,c);
                break;
            }
            else if (b[i]>a[i])
            {
                subtract(b,a,c);
                putchar('-');
                break;
            }
        }
    }

    if (i==-1)
        putchar('0');
    else
    {
        i=0;
        while (c[i]=='0')
            i++;
        while (c[i]!='\0')
            putchar(c[i++]);
    }
    return 0;
}
