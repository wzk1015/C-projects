#include <stdio.h>
#include <stdlib.h>

#define A 19

int a[A+1][A+1],b[A+1][A+1];

void w_turn()  //�ð�����
{
    while(1)
    {
        int x,y,c;
        scanf ("%d,%d",&x,&y);
        if (x>=1&&x<=A&&y>=1&&y<=A)
        {
            if (a[x-1][y-1]==1||a[x-1][y-1]==-1){
                printf("Wrong Position. White try Again\n");
                while (getchar()!='\n');
            }
            else
            {
                a[x-1][y-1]=-1;
                break;
            }
        }
        else{
            printf("Wrong Position. White try Again\n");
            while (getchar()!='\n');
        }
    }
    printf("\n");
}

void b_turn()  //�ú�����
{
    while(1)
    {
        int x,y;
        scanf ("%d,%d",&x,&y);
        if (x>=1&&x<=A&&y>=1&&y<=A)
        {
            if (a[x-1][y-1]==1||a[x-1][y-1]==-1){
                printf("Wrong Position. Black try Again\n");
                while (getchar()!='\n');
            }
            else
            {
                a[x-1][y-1]=1;
                break;
            }
        }
        else{
            printf("Wrong Position. Black try Again\n");
            while (getchar()!='\n');
        }
    }
    printf("\n");
}

void showboard()  //��ʾ����
{   int i,j;
    for (i=-1;i<A;i++)
    {
        if (i<=8)       //��ʾ�к�
            printf("%d  ",i+1);
        else
            printf("%d ",i+1);
        for (j=0;j<A;j++)
        {
            if (i==-1)  //��ʾ�к�
            {
                if (j<=8)
                    printf("%d ",j+1);
                else
                    printf("%d",j+1);
                continue;
            }
            if (a[i][j]==0)
                printf(". ");
            else if (a[i][j]==1)
                printf("x ");
            else
                printf("o ");

        }
        printf("\n");
    }
    printf("\n");
}

int judge() //�ж��Ƿ�һ���ѻ�ʤ
{
    int i,j;
    for (i=0;i<A;i++)  //�ж�һ���������������ͬɫ����
    {
        for (j=0;j<A-4;j++)
        {
            if (a[i][j]==1&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1&&a[i][j+4]==1)
            {
                printf("BLACK WIN!\n");
                return 1;
            }
            if (a[i][j]==-1&&a[i][j+1]==-1&&a[i][j+2]==-1&&a[i][j+3]==-1&&a[i][j+4]==-1)
            {
                printf("WHITE WIN!\n");
                return 1;
            }
        }
    }

    for (j=0;j<A;j++)  //�ж�һ���������������ͬɫ����
    {
        for (i=0;i<A-4;i++)
        {
            if (a[i][j]==1&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1&&a[i+4][j]==1)
            {
                printf("BLACK WIN!\n");
                return 1;
            }
            if  (a[i][j]==-1&&a[i+1][j]==-1&&a[i+2][j]==-1&&a[i+3][j]==-1&&a[i+4][j]==-1)
            {
                printf("WHITE WIN!\n");
                return 1;
            }
        }
    }

    for (i=0;i<A-4;i++)  //�ж�����б�����µ����ͬɫ����
    {
        for (j=0;j<A-4;j++)
        {
            if (a[i][j]==1&&a[i+1][j+1]==1&&a[i+2][j+2]==1&&a[i+3][j+3]==1&&a[i+4][j+4]==1)
            {
                printf("BLACK WIN!\n");
                return 1;
            }
            if (a[i][j]==-1&&a[i+1][j+1]==-1&&a[i+2][j+2]==-1&&a[i+3][j+3]==-1&&a[i+4][j+4]==-1)
            {
                printf("WHITE WIN!\n");
                return 1;
            }
        }
    }

    for (i=4;i<A+1;i++)  //�ж�����б�����µ����ͬɫ����
    {
        for (j=0;j<A-4;j++)
        {
            if (a[i][j]==1&&a[i-1][j+1]==1&&a[i-2][j+2]==1&&a[i-3][j+3]==1&&a[i-4][j+4]==1)
            {
                printf("BLACK WIN!\n");
                return 1;
            }
            if (a[i][j]==-1&&a[i-1][j+1]==-1&&a[i-2][j+2]==-1&&a[i-3][j+3]==-1&&a[i-4][j+4]==-1)
            {
                printf("WHITE WIN!\n");
                return 1;
            }
        }
    }

    return 0;

}



int main()
{
    printf("Welcome to WZK's five-in-a-row game!\n\n");
    printf("Here are the instructions:\n");
    printf("Black and White play in turn.\n");
    printf("During each turn, one should input the coordinate of the position of one's expected move.\n");
    printf("e.g. ��2,2�� ��4,5�� (without ����) etc.");
    printf("Then the chessboard will be showed, with ��x�� stands for Black, and ��o�� stands for White.\n");
    printf("The program will automatically tell you whether the game is over and who the winner is.\n");
    printf("Enjoy the game!\n\n");

    showboard();
    while(1)
    {
        printf("Black turn\n");
        b_turn();
        showboard();
        if (judge()==1)
            break;
        printf("White turn\n");
        w_turn();
        showboard();
        if (judge()==1)
            break;
    }

    printf("Thank you for playing!\n");
    printf("Goodbye!\n");
    return 0;
}
