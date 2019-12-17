#include <stdio.h>
#include <stdlib.h>

main()
{
    int b[3]={1,4,9};
    printf("b=%d\n", b);
    printf("b+1=%d\n", b+1);
    printf("&b=%d\n", &b);
    printf("&b+1=%d\n", &b+1);
    printf("b[0]=%d\n", b[0]);
    printf("b[0]+1=%d\n", b[0]+1);
    printf("&b[0]=%d\n", &b[0]);
    printf("&b[0]+1=%d\n", &b[0]+1);

    printf("*b=%d\n", *b);
    printf("*b+1=%d\n", *b+1);
    printf("*(b+1)=%d\n", *(b+1));
    printf("*(b+1)+1=%d\n\n\n\n", *(b+1)+1);


    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    printf("a=%d\n", a);
    printf("a+1=%d\n", a+1);
    printf("&a=%d\n", &a);
    printf("&a+1=%d\n", &a+1);
    printf("a[0]=%d\n", a[0]);
    printf("a[0]+1=%d\n", a[0]+1);
    printf("&a[0]=%d\n", &a[0]);
    printf("&a[0]+1=%d\n", &a[0]+1);
    printf("&a[0][0]=%d\n", &a[0][0]);
    printf("&a[0][0]+1=%d\n", &a[0][0]+1);

    printf("*a=%d\n", *a);
    printf("*a+1=%d\n", *a+1);
    printf("*(a+1)=%d\n", *(a+1));
    printf("*(a+1)+1=%d\n", *(a+1)+1);

    int (*p)[3][4] = &a;
    printf("p=%d\n", p);

    int (*q)[4] = a;
    printf("q=%d\n", q);
    printf("q+1=%d\n",q+1);

    int *r = a[0];
    printf("r=%d\n", r);

    //func1(a);


    func2(a, 3, 4);

}

void func1(int b[][4]) {
    printf("b=%d\n", b);
    printf("b+1=%d\n", b+1);


    printf("&b=%d\n", &b);
    //printf("&b+1=%d\n" &b+1;

}

void func2(int **c, int row, int column) {
    printf("c=%d\n", c);
    printf("c+1=%d\n", c+1);

    printf("*c=%d\n", *c);
    printf("*(c+1)=%d\n", *(c+1));

    printf("*(*c+1)+3=%d\n", *(*c+1)+3);
    printf("*(c+7)=%d\n", *(c+7));
}
