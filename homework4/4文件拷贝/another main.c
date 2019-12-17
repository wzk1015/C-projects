#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpin,*fpout;
    char buf[BUFSIZ],c;
    int i=0,n;

    fpin = fopen ("fcopy.in","r");
    fpout = fopen ("fcopy.out","w");

    while ((c=fgetc(fpin))!=EOF)
    {
        buf[i]=c;
        if (c==' '||c=='\t')
        {
            while((c=fgetc(fpin))==' '||(c=fgetc(fpin))=='\t')
                ;
        }

        i++;
    }

    n=i+2;

    for (i=0;i<n;i++)
        fputc(buf[i],fpout);

    fclose(fpout);

    return 0;
}
