#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("filein.c","r");
    char buf[BUFSIZ];
    int i = 0, j, n1 = 0, n2 = 0, r2;
    double r1;

    while ((buf[i]=fgetc(fp)) != EOF)
        i++;

    n1 = i;

    for (i = 0; i<n1-1; i++)
    {
        if (buf[i] == '/'&& buf[i+1] == '*')
        {
            for (j = i + 2; j<n1-1; j++)
            {
                if (buf[j] == '*'&& buf[j+1] == '/')
                {
                    n2 += j-i-2;
                    break;
                }
            }
        }
    }

    r1 =  n2 / n1;
    r2= 100 * r1;
    printf("%d%%",r2);
    return 0;
}
