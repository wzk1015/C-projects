#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N,t;
char s[10],s_up[10];//char s
void reverse(char a[])//char a[]
{
    int c,i,j;
    for (i=0,j=N-1;i<j;i++,j--)
    {
        c=a[i];
        a[i]=a[j];
        a[j]=c;
    }
}

void NumToStr()
{
    int i=0,n=t;
    while (n!=0){
        s[i++]=n%10+'0';    //n%10+'0'
        n/=10;
    }
    s[N]='\0';
    reverse(s);
}

int check()
{
    int i,j,mark=0;
    char m[9]={'1','2','3','4','5','6','7','8','9'};
    char t;
    NumToStr();
    strcpy(s_up,s);
    for(i=1;i<N;i++)
    {
        t=s_up[i];
        j=i-1;
        while(j>=0&&t<s_up[j])
        {
            s_up[j+1]=s_up[j];
            j--;
        }
        s_up[j+1]=t;
    }
    if (strncmp(s_up,m,N)==0)
        return 1;
    return 0;

    /*for (i=0;i<N;i++)  //用此段代码时将s改为char型数组，并看以上注释
    {
        if (s[i]>N+'0'||s[i]=='0')
            return 0;
        for (j=0;j<N;j++)
        {
            if (j==i)
                continue;
            if (s[j]==s[i])
            {
                mark=1;
                break;
            }
        }
        if (mark==1)
            return 0;
    }
    return 1;*/
}


void main()
{
    int i;
    int a[11]={6666666,1,12,123,1234,12345,123456,1234567,12345678,123456789};
    scanf("%d",&N);
    for (t=a[N];t<pow(10,N);t+=9)
    {
        if (check()==1)
        {
            for (i=0;i<N-1;i++)
                printf("%c ",s[i]);
            printf("%c\n",s[N-1]);
        }
    }

}









/*int main()
{
    int N;
    int a[10];
    int b[10];
    scanf("%d",&N);
    switch (N)
    {
        case 1:
        {
            printf("1\n");
            break;
        }
        case 2:
        {
            printf("1 2\n2 1\n");
            break;
        }
        case 3:
        {
            for (a[0]=1;a[0]<=N;a[0]++)
            {
                for (a[1]=1;a[1]<=N;a[1]++)
                {
                    for (a[2]=1;a[2]<=N;a[2]++)
                    {
                        check(a,3);
                    }
                }
            }
            break;
        }
        case 4:
        {

            break;
        }
        case 5:
        {

            break;
        }
        case 6:
        {

            break;
        }
        case 7:
        {

            break;
        }
        case 8:
        {

            break;
        }
        case 9:
        {

            break;
        }
        case 10:
        {

            break;
        }

    }
    return 0;
}*/
