#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y,m,d,days;
    scanf("%d %d %d",&y,&m,&d);

    if (((y%4==0)&&(y%100!=0))||(y%400==0)){
        switch (m){
        case 1:
            days=d;
            break;
        case 2:
            days=31+d;
            break;
        case 3:
            days=60+d;
            break;
        case 4:
            days=91+d;
            break;
        case 5:
            days=121+d;
            break;
        case 6:
            days=152+d;
            break;
        case 7:
            days=182+d;
            break;
        case 8:
            days=213+d;
            break;
        case 9:
            days=244+d;
            break;
        case 10:
            days=274+d;
            break;
        case 11:
            days=305+d;
            break;
        case 12:
            days=335+d;
            break;
        }



    }


    else{
        switch (m){
        case 1:
            days=d;
            break;
        case 2:
            days=31+d;
            break;
        case 3:
            days=59+d;
            break;
        case 4:
            days=90+d;
            break;
        case 5:
            days=120+d;
            break;
        case 6:
            days=151+d;
            break;
        case 7:
            days=181+d;
            break;
        case 8:
            days=212+d;
            break;
        case 9:
            days=243+d;
            break;
        case 10:
            days=273+d;
            break;
        case 11:
            days=304+d;
            break;
        case 12:
            days=334+d;
            break;
        }
    }

    printf("%d\n",days);
    return 0;
}
