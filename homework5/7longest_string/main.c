#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[10001],b[10001];
int a[10001];    //c[10001] aΪb�Ӵ���Ԫ����s�е�λ�� c[i]��־s[i]�Ƿ�����
int max_len=0,n;

void find(int index, int m)  //����1~n�����к���n��Ԫ�ص��Ӽ����ȼ��ڱ���s�������Ӵ�
{                               //index:��ǰ�±� n:��ʣ�µ�����ȡ��n��
    int i,j;

    if (m==1)
    {                           //Ҫ��ʣ������ȡ��1��
        for (i=index; i<strlen(s); i++)
        {
            if (s[i]>=s[i-1])
            {
                a[i]=1;
                for (i=0,j=0; i<strlen(s); i++)
                    if (a[i]==1)
                        b[j++]=s[i];
                b[j]='\0';
                max_len=(strlen(b)>max_len?strlen(b):max_len);
                a[i]=0;
            }
        }
    }
    else {                      //��Ҫ��ʣ������ȡ��2��������ʱ�õݹ�
        for (i=index; i<strlen(s); i++)
        {
            if (m==n)
            {
                a[i]=1;
                find(i+1,m-1);
                a[i]=0;
            }
            else if (s[i]>=s[i-1])
            {
                a[i]=1;
                find(i+1,m-1);
                a[i]=0;
            }
        }
    }
}


int main()
{
    gets(s);
    for (n=1;n<=strlen(s);n++)
        find(0,n);

    printf("%d\n",max_len);
    return 0;
}
/*void longstr()
{
    int i,j;

    for (i=0;s[i+1]!='\0';i++) //�����Ӵ����׸��ַ�
    {
        m=0;
        b[m++]=s[i];
        for (j=i+1;s[j]!='\0';j++)
        {
            if (s[j]>=b[m-1])
            {
                b[m++]=s[j];
            }
        }
        b[m]='\0';
        if (m>max_len)
            max_len=strlen(b);
    }
}*/



/*void FindLongstr(char s[],int a[],int c[],int n,int max_len)//nΪ��ǰ�Ӵ�Ҫ�ҵĵ�n����
{
    int i,j;

    if (n)
    for (i=a[n-1];i<strlen(s);i++)
    {
        if (s[i]>b[n-1])
        {
            c[i]=1;
            FindLongstr(s,a,c,n+1,max_len);
            c[i]=0;
        }
    }
}*/


