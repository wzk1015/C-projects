#include <stdio.h>
#include <stdlib.h>

/*int op(char m,int x,int y)
{
    switch (m)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
    }
}
*/

int main()
{
    char a[100],c;
    int b[100],n,i,j,result=0;


    for (i=0;i<100;i++)         //���ζ������������������������������õ�b0,a0,b1,a1,b2,a2����
    {
        if (i%2==0)
            scanf("%d",&b[i/2]);
        else
        {
            if ((c=getchar())!=' ')
            {
                a[(i-1)/2]=c;
                //scanf("%c",&a[(i-1)/2]);
                if (a[(i-1)/2]=='=')
                    break;
            }

            else
                i--;
        }
    }

    n=i;                            //��������Ԫ�ظ���

    for (i=0;i<(n-1)/2;i++)         //�Ƚ��г˳�����
    {
        if (a[i]=='*')
        {
            b[i+1]=b[i]*b[i+1];         //�ѽ��������һ����
            b[i]=-233;                  //��ǰһ������Ϊ-233����������ʱ��ɸ��������
        }

        else if (a[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
            b[i]=-233;
        }
    }

    for (i=0;i<(n-1)/2;i++)         //�ٽ��мӼ�����
    {
        if (a[i]=='+')              //�ӷ�����
        {
            for (j=i;j>=0;j--)          //�ӼӺ�ǰ��Ѱ�ҵ�һ����Ч����������Ϊ-233����Ϊ������
            {
                if (b[j]!=-233)
                {
                    b[i]=b[j];          //�ѱ����������Ӻ�ǰ�ĵ�һ����
                    if (i!=j)           //������Ч�����ǼӺ�ǰ������Ҫ����ԭλ�ñ�Ϊ-233��ֹӰ������
                        b[j]=-233;
                    break;
                }
            }

            for (j=i+1;j<=(n-1)/2;j++)
            {
                if (b[j]!=-233)
                {
                    b[i+1]=b[j];        //ͬ��Ѱ�Ҽ����������Ӻú�ĵ�һ����
                    if ((i+1)!=j)
                        b[j]=-233;
                    break;
                }
            }
            b[i+1]=b[i]+b[i+1];
        }

        else if (a[i]=='-')         //ͬ���������
        {
            for (j=i;j>=0;j--)
            {
                if (b[j]!=-233)
                {
                    b[i]=b[j];
                    if (i!=j)
                        b[j]=-233;
                    break;
                }
            }

            for (j=i+1;j<=(n-1)/2;j++)
            {
                if (b[j]!=-233)
                {
                    b[i+1]=b[j];
                    if ((i+1)!=j)
                        b[j]=-233;
                    break;
                }
            }
            b[i+1]=b[i]-b[i+1];

        }
    }


    //������

    for (i=(n-1)/2;i>=0;i--)        //�Ӻ���ǰѰ�ҵ�һ����Ч����Ϊ���
        if (b[i]!=-233)
        {
            result=b[i];
            break;
        }
    printf("%d",result);

    return 0;
}
