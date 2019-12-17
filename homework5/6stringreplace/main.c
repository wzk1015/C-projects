#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char t1[500],t2[500],low_t1[500],low_s1[100],s1[100],s2[100];

void replace()
{
    int i=0,k=0;
    while (t1[i]!='\0')
    {
        for (k=0;k<strlen(s1);k++)
        {
            low_t1[k]=tolower(t1[k+i]);
            low_s1[k]=tolower(s1[k]);
        }

        if (strncmp(low_t1,low_s1,strlen(s1))==0)
        {
            strncat(t2,s2,strlen(s2));
            i+=strlen(s1);
        }
        else
        {
            strncat(t2,t1+i,1);
            i++;
        }
    }
}

int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("filein.txt","r");
    fp2=fopen("fileout.txt","w");
    fread(t1,1,500,fp1);

    gets(s1);
    gets(s2);

    replace();
    fputs(t2,fp2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}


/*void replace()
{
    int i,j,k=0,p=0;
    for (i=0;i<strlen(t1);i++)
    {
        for (j=0;j<strlen(s1);j++)
        {
            t3[j]=t1[i+j];
        }
        t3[j]='\0';

        if (strcmp(t3,s1)==0)//t3=s1
        {
            //while(k<i)
            //    t2[k++]=t1[p++];
            while(k<i+strlen(s2))
            {
                t2[k]=s2[k-i];
                k++;
            }
            p+=strlen(s1);
            //i+=strlen(s1);
        }

        else
        {
            while (k<i+j)
                t2[k++]=t1[p++];
        }
    }
    t2[k]='\0';
}*/

    /*while(strstr(t1,s1)!=NULL)
    {
        *b=t1[0];
        a=((int)strstr(t1,s1)-(int)b)/4;
        for (;i<a;i++)
            t2[k++]=t1[j++];
        for(;i<a+strlen(s2);i++) //i=a;
            t2[k++]=s2[m++];
    }

    for(;i<strlen(t1);i++)
        t2[k++]=t1[j++];*/

