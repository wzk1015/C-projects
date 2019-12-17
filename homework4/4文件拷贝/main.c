#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpin,*fpout;
    char buf[BUFSIZ];
    int i=0,n,j,k;

    fpin = fopen ("fcopy.in","r");
    fpout = fopen ("fcopy.out","w");

    while ((buf[i]=fgetc(fpin))!=EOF)
        i++;

    n=i+2;

    for (i=0;i<n;i++)
    {
        if (buf[i]==' '||buf[i]=='\t')
        {
            for (j=i+1;j<n;j++)
            {
                if (buf[j]==' '||buf[j]=='\t')
                {
                    for (k=j;k<n;k++)
                        buf[k] = buf[k+1];
                    j--;
                }

                else
                    break;
            }
            buf[i] = ' ';
        }
    }

    for (i=0;buf[i]!=EOF;i++)
        fputc(buf[i],fpout);

    fclose(fpout);

    return 0;
}
