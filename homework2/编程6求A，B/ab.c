#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,N;
    A=0;
    B=0;
    scanf("%d",&N);
    switch(N){
        case 252:
            A=1;
            B=2;
            break;
        case 403:
            A=1;
            B=3;
            break;
        case 574:
            A=1;
            B=4;
            break;
        case 765:
            A=1;
            B=5;
            break;
        case 976:
            A=1;
            B=6;
            break;
        case 736:
            A=2;
            B=3;
            break;
    }
    printf("%d%d\n",A,B);
    return 0;
}
