#include <stdio.h>
#define MAX 11
int Mark[MAX] = {0}; /*������飬�������ĳ�������Ƿ��ѱ�ʹ�ó�Ϊ*/
char Stack[MAX]; /*ȫ�������ִ�*/
void rank(int m, int n); /* m��¼��һ��Ҫ���ɵ�ȫ��������Ӧ����Stack�е�λ�ã�n��ʾ��ʣ����������Ҫ
								����*/
int N;
int main ()
{
	  scanf ("%d", &N);
           rank(0,N);
           return 0;
}
void rank(int m, int n)
{
	int i;

	if( n == 0){
		Stack[m] = '\0';
		puts(Stack);	/* ���ȫ�������ִ�*/
		return;
	}
	for(i=1; i<=N; i++)
		if(Mark[i] == 0 ){
			Mark[i] = 1; 	/* ��Ǹ������ѱ�ʹ��*/
			Stack[m] = '0'+i;  	/*����ǰ���ּӵ�ȫ�������ִ���*/
			rank(m+1,n-1); 	/* ����ȫ��������һ������ */
			Mark[i] = 0;	/*�ͷŸ�����*/
		}

}
