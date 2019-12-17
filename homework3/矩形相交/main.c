#include <stdio.h>
#include <stdlib.h>

int max(a,b)
{
    if (a>b)
        return a;
    return b;
}

int min(a,b)
{
    if (a<b)
        return a;
    return b;
}

int main()
{
    int ax1,ax2,ay1,ay2,bx1,bx2,by1,by2;
    int length,width,S;
    scanf("%d %d %d %d %d %d %d %d",&ax1,&ay1,&ax2,&ay2,&bx1,&by1,&bx2,&by2);
    length=min(max(ax1,ax2),max(bx1,bx2))-max(min(ax1,ax2),min(bx1,bx2));
    width=min(max(ay1,ay2),max(by1,by2))-max(min(ay1,ay2),min(by1,by2));
    S=width*length;
    if(width>0&&length>0)
        printf("%d",S);
    else
        printf("0");
    return 0;
}
