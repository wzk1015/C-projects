#include <stdio.h>
#include <stdlib.h>
struct n {
    int x;
    char c;
};

struct {
    int x;
    char *y;
} tab[2] = {{1, "ab"}, {2, "cd"}}, *p = tab;

void func(struct n b)
{
    b.x = 20;
    b.c= 'y';
}

struct student
{
    int age;
    int num;
};

void main()
{
    printf("%c", *(++p)->y );
    //struct n a = {10, 'x'};
    //func(a);
    //printf ("%d,%c", a.x,a.c);
}

/*int main()
{

    /*int n = 0, i = 1;
    int put[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    scanf("%d", &n);
    print(put, n);
    while (i != n)
    {
        i = backNum(put, n);
        rev(put, n, i);
        if (i != n)
            print(put, n);
    }
    return 0;
}*/

//1,2,3,3,5,4


/*
int main()
{
    int a[] = {1,2,3,4,5,6};
    int *p;
    p=a;
    printf("%d,",*p);
    printf("%d,",*(++p));
    printf("%d,",*++p);
    printf("%d,",*(p--));
    p+=3;
    printf("%d,%d",*p, *(a+3));*

/*

int backNum(int put[], int n) //计算尾端的倒序排列数字个数
{
    int i = 1;
    int m = n - 1;
    while (m > 0)
    {
        if (put[m - 1] > put[m])
        {
            i = i + 1;
            m = m - 1;
        }
        else
            break;
    }
    return i;
}

int minimum(int put[], int n, int m,
            int mini) // n为n-排列，m为倒序排列的最小下标
{
    int i = n - 1;    //最大下标
    int min = 11;     //大于倒数n+1位的最小的数
    int minimumi = 0; // min的下标
    while (i >= m)
    {
        if (put[i] < min && put[i] > mini)
        {
            min = put[i];
            minimumi = i;
        }
        i = i - 1;
    }
    return minimumi;
}

void rev(int put[], int n, int i) //进行交换操作
{
    int m = n - 1;   //最大下标
    int min = n - i; //倒序排列中的最小下标
    int minimumi = 0;
    int temp = 0;
    int j = 0;
    minimumi = minimum(put, n, min, put[min - 1]);
    temp = put[minimumi];
    put[minimumi] = put[min - 1];
    put[min - 1] = temp;
    j = min;
    while (j < n)
    {
        minimumi = j;
        while (minimumi < n - 1)
        {
            if (put[minimumi] > put[minimumi + 1])
            {
                temp = put[minimumi];
                put[minimumi] = put[minimumi + 1];
                put[minimumi + 1] = temp;
            }
            minimumi = minimumi + 1;
        }
        j = j + 1;
    }
}

void print(int put[], int n)
{
    int i = 0;
    printf("%d", put[i]);
    i = i + 1;
    while (i < n)
    {
        printf(" %d", put[i]);
        i = i + 1;
    }
    printf("\n");
}*/

