#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void del(char *pin, char *pout, char *p1)
{
    int i=0;
    while (i<=strlen(pin))
    {
        if (strncmp(pin+i,p1,strlen(p1))!=0)
        {
            strncat(pout,pin+i,1);
            i++;
        }
        else
            i+=strlen(p1);
    }
}

int main()
{
    char in[500],out[500];
    char s1[500];
    gets(in);
    gets(s1);
    out[0]='\0';

    del(in,out,s1);
    puts(out);
    return 0;
}
