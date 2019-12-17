#include <stdio.h>
#define MAX 11
int Mark[MAX] = {0}; /*标记数组，用来标记某个数字是否已被使用成为*/
char Stack[MAX]; /*全排列数字串*/
void rank(int m, int n); /* m记录下一个要生成的全排列数字应放在Stack中的位置，n表示还剩几个数字需要
								生成*/
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
		puts(Stack);	/* 输出全排列数字串*/
		return;
	}
	for(i=1; i<=N; i++)
		if(Mark[i] == 0 ){
			Mark[i] = 1; 	/* 标记该数字已被使用*/
			Stack[m] = '0'+i;  	/*将当前数字加到全排列数字串中*/
			rank(m+1,n-1); 	/* 生成全排列中下一个数字 */
			Mark[i] = 0;	/*释放该数字*/
		}

}
