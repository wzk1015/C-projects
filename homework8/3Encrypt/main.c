#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char key1[60],key2[26];
char from[27],to[27];
char buf[10000];
int buflen;

void OperateKey()
{
    int i,k=0;
    for (i=0;key1[i]!='\0';i++)
    {
        if (strchr(key2,key1[i]) == NULL)
        key2[k++]=key1[i];
    }
    key2[k]='\0';
}

void MakePassword()
{
    int i,k=0;
    for (i=0;i<26;i++)
        from[i]=i+'a';
    from[26]='\0';
    strcpy(to,key2);
    for (i=25;i>=0;i--)
    {
        if (strchr(key2,from[i])!=NULL)
            continue;
        to[strlen(key2)+k]='a'+i;
        k++;
    }
    to[26]='\0';
}

void Secure()
{
    int i,j,pos=-1;
    for (i=0;i<buflen;i++)
    {
        for (j=0;j<26;j++)
        {
            if (from[j]==buf[i])
            {
                pos=j;
                break;
            }
        }
        if (pos==-1)
            continue;
        buf[i]=to[j];
        pos=-1;
    }
}

int main()
{
    int i=0;
    FILE *in, *out;
    in = fopen ("encrypt.txt","r");
    out = fopen ("output.txt","w");

    gets(key1);
    OperateKey();
    MakePassword();

    while ( (buf[i++]=fgetc(in)) != EOF);
    buflen=i-1;

    Secure();

    for (i=0;i<buflen;i++)
        fputc(buf[i],out);

    return 0;
}


/*

for (j=0;j<k;j++)
        {
            if (key2[j]==key1[i])
            {
                mark=1;
                break;
            }
        }

        if (mark==1)
        {
            mark=0;
            continue;
        }

*/
