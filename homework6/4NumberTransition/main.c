#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void transform(char *s1, char *s2)
{
    int i,j,intlen,decilen,k;
    char intpart[200],decipart[200];//存放整数部分和小数部分
    for (i=0;i<strlen(s1);i++)
        if (s1[i]=='.')
            break;
    intlen=i;
    decilen=strlen(s1)-intlen-1;
    strncpy(intpart,s1,intlen);     //写入intpart,decipart
    intpart[intlen]='\0';
    strncpy(decipart,s1+intlen+1,decilen);
    decipart[decilen]='\0';

    if (intpart[0]!='0')
    {
        s2[0]=intpart[0];
        s2[1]='.';
        s2[2]='\0';//
        strncat(s2,intpart+1,intlen);//
        strncat(s2,decipart,decilen);
        s2[intlen+decilen+1]='e';
        for (i=0;i<intlen+decilen+2;i++)
            putchar(s2[i]);
        printf("%d",intlen-1);
    }

    else
    {
        for (i=0;decipart[i]=='0';i++);
        s2[0]=decipart[i];
        if (decipart[i+1]!='\0')
        {
            s2[1]='.';
            s2[2]='\0';//
            strncat(s2,decipart+i+1,decilen-i-1);
            k=decilen-i+1;
        }
        else
            k=1;

        s2[k++]='e';
        s2[k++]='-';
        for (j=0;j<k;j++)
            putchar(s2[j]);
        printf("%d",i+1);
    }
}

int main()
{
    char s1[200],s2[200];
    gets(s1);
    transform(s1,s2);
    return 0;
}

/*
    int i=1,len;
    double a,b,c;
    scanf("%lf",&a);
    b=a;
    while(b>10)
    {
        b/=10;
        i++;
    }
    len=i;
    c=a/pow(10,len-1);
    printf("%fe%d",c,len-1);
*/


        /*
        if (intlen-1>=10)
        {
            s2[k++]=(intlen-1)/10+'0';
            s2[k++]=(intlen-1)%10+'0';
        }
        else
            s2[k++]=intlen-1+'0';
        s2[k++]='\0';
        */

        /*
        if (i+1>=10)
        {
            s2[k++]=(i+1)/10+'0';
            s2[k++]=(i+1)%10+'0';
        }
        else
            s2[k++]=i+1+'0';
        s2[k++]='\0';
        */
