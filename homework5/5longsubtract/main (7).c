#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[81], b[81],c[81];
int carry[81];

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

void subtract(char a[], char b[], int n_a, int n_b)
{
    int i,m;

    if (n_a==n_b)
    {
        for (i=0;i<n_a;i++)
        {
            m=a[i]-b[i]-carry[i];
            if (m>=0&&i<n_a-1)
                c[i]=m+'0';
            else if (m>=0&&i==n_a-1)
            {
                c[i]=m+'0';
                c[i+1]='\0';
            }
            else if (i<n_a-1) //m<0,i<n_a-1
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

    else if (n_a>n_b)
    {
        b[n_b]='0';
        for (i=0;i<n_a;i++)
        {
            m=a[i]-b[i]-carry[i];
            if (m>=0&&i<n_a-1)
                c[i]=m+'0';
            else if (m>=0&&i==n_a-1)
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
    int n_a,n_b;
    int i,t=0;
    for (i=0;i<81;i++)
        a[i]=b[i]='0';

    gets(a);
    gets(b);
    n_a=strlen(a);
    n_b=strlen(b);
    reverse(a);
    reverse(b);

    if (n_a>n_b)
        subtract(a,b,n_a,n_b);
    else if (n_a<n_b)
    {
        t=n_a;
        n_a=n_b;
        n_b=t;
        subtract(b,a,n_a,n_b);
        putchar('-');
    }
    else
    {
        for (i=n_a-1;i>=0;i--)
        {
            if (a[i]>b[i])
            {
                subtract(a,b,n_a,n_b);
                break;
            }
            else if (b[i]>a[i])
            {
                subtract(b,a,n_a,n_b);
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

