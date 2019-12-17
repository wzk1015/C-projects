/*#include <stdio.h>

int func(int n)
{
    if(n<=1)
        return 1;
    else
        return (2+n*func(n-1));
}

void main()
{
    int x = 4;
    printf("%d\n",func(x));
}
*/

/*#include <stdio.h>
void inverp(char *a)
{
    if ( *a == '\0' )
        return;
    inverp(a+1);
    printf("%c", *a );
}
void main()
{
    char s[10] = "hello!";
    inverp(s);
}*/

/*Selection 1 :
(A)  *a != '\0'
(B)  *a != NULL
(C)  *a == '\0'
(D)  ! a * == 0

Selection 2 :
(A)  * (a-1)
(B)  *a
(C)  * (a+1)
(D)  * (--a)*/

 /*#define  A 3.5
 #define S(b) A*b*b
 main()
 {
   int x=1,y=2;
   printf("%4.1f\n",S(x+y));
 }*/
#include <stdio.h>

void main(){
int b[]={1,2,3,4},y,*p = b;
y=*p++;
printf("%d",y);}


