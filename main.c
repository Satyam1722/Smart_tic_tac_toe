#include <stdio.h>
#include <stdlib.h>

int a[3][3]=
{
    {
        '1','2','3'
    },
    {
        '4','5','6'
    },
    {
        '7','8','9'
    }
};
int player=1,moves=0;
int b[3][3]= {0};
void home()
{
    printf("Enter your choice\n");
    printf("1. Want to play with Smart Computer\n");
    printf("2. Want to play with Evil Computer\n");
    printf("3. Want to play with player\n");
    printf("4. Exit\n");
}

void display_C()
{
    printf("******************** Tic Tac Toe *************************\n");
    printf("\nYou --> X\n\n\n");
}

void display_P()
{
    printf("******************** Tic Tac Toe *************************\n");
    printf("\nFirst Player --> X\n");
    printf("Second Player --> O\n\n\n");
}

int check()
{
    for(int i=0; i<3; i++)
        {
            if(a[i][0]==a[i][1] && a[i][1]==a[i][2])
                return 1;
        }

    for(int i=0; i<3; i++)
        {
            if(a[0][i]==a[1][i] && a[1][i]==a[2][i])
                return 1;
        }

    if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
        return 1;
    if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
        return 1;

    return 0;
}

void move(int n)
{

    int i,j;
    moves++;

    i=n/3;
    j=(n%3)-1;

    if(!(i*3+j+49==a[i][j]))
        {
            int n;
            printf("invalid number !!!!!\n");
            printf("\n\nPlayer %d \n",player);
            printf("Select the number : ");
            scanf("%d",&n);
            move(n);
        }


    if(player==1)
        a[i][j]='X';
    else
        a[i][j]='O';
}



void display()
{
    printf("    |    |   \n");
    printf(" %c  | %c  | %c \n",a[0][0],a[0][1],a[0][2]);
    printf("    |    |   \n");
    printf("______________\n");
    printf("    |    |   \n");
    printf(" %c  | %c  | %c \n",a[1][0],a[1][1],a[1][2]);
    printf("    |    |   \n");
    printf("______________\n");
    printf("    |    |   \n");
    printf(" %c  | %c  | %c \n",a[2][0],a[2][1],a[2][2]);
    printf("    |    |   \n");


}

void check_p()
{
    int i,j;
    int flag=0;
    for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
                {
                    if(a[i][j]>='1' && a[i][j]<='9')

                        {
                            a[i][j]='X';
                            if(check()==1)
                                {
                                    flag=1;
                                    b[i][j]=1;
                                }
                            a[i][j]=i*3+j+49;
                        }

                }

        }


    if(flag==0)
        {
            for(i=0; i<3; i++)
                {
                    for(j=0; j<3; j++)
                        {
                            if(a[i][j]>='1' && a[i][j]<='9')
                                {
                                    b[i][j]=1;
                                    flag=1;
                                    break;
                                }
                        }
                    if(flag==1)
                        break;
                }
        }

}
int main()
{
    int n,i,j;
    while(1)
        {
            home();
            scanf("%d",&n);
            if(n==1)
                {
                    while(1)
                        {
                            system("cls");
                            display_C();
                            display();
                            printf("\nYou! : \n");
                            printf("Select the number : ");
                            scanf("%d",&n);
                            move(n);
                            if(check())
                                {
                                    char c;
                                    system("cls");
                                    display_P();
                                    display();
                                    printf("\nplayer %d won\n",player);
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                            if(moves==9)
                                {
                                    char c;
                                    system("cls");
                                    display_P();
                                    display();
                                    printf("\nDraw ! ");
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                            player=player==1?2:1;

                            check_p();

                            for(i=0; i<3; i++)
                                {
                                    int flag=0;
                                    for(j=0; j<3; j++)
                                        {
                                            if(b[i][j]==1)
                                                {
                                                    move(3*i+j+1);
                                                    flag=1;
                                                    break;
                                                }
                                        }
                                        if(flag==1)
                                            break;
                                }

                            player=player==1?2:1;


                            for(i=0; i<3; i++)
                                {
                                    for(j=0; j<3; j++)
                                        {
                                            b[i][j]=0;

                                        }
                                }

                            if(check())
                                {
                                    char c;
                                    system("cls");
                                    display_C();
                                    display();
                                    printf("\nSmart Computer Won\n");
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                            if(moves==9)
                                {
                                    char c;
                                    system("cls");
                                    display_C();
                                    display();
                                    printf("\nDraw ! ");
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                        }

                }
            else if(n==2)
                {
                    while(1)
                        {
                            system("cls");
                            display_C();
                            display();
                            printf("\nYou! : \n");
                            printf("Select the number : ");
                            scanf("%d",&n);
                            move(n);
                            if(check())
                                {
                                    char c;
                                    system("cls");
                                    display_P();
                                    display();
                                    printf("\nplayer %d won\n",player);
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                            if(moves==9)
                                {
                                    char c;
                                    system("cls");
                                    display_P();
                                    display();
                                    printf("\nDraw ! ");
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                            player=player==1?2:1;

                            check_p();

                            for(i=0; i<3; i++)
                                {
                                    int flag=0;
                                    for(j=0; j<3; j++)
                                        {
                                            if(b[i][j]==1)
                                                {
                                                    move(3*i+j+1);

                                                }
                                        }

                                }

                            player=player==1?2:1;


                            for(i=0; i<3; i++)
                                {
                                    for(j=0; j<3; j++)
                                        {
                                            b[i][j]=0;

                                        }
                                }

                            if(check())
                                {
                                    char c;
                                    system("cls");
                                    display_C();
                                    display();
                                    printf("\nEvil Computer Won\n");
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                            if(moves==9)
                                {
                                    char c;
                                    system("cls");
                                    display_C();
                                    display();
                                    printf("\nDraw ! ");
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                        }

                }
            else if(n==3)
                {
                    while(1)
                        {
                            system("cls");
                            display_P();
                            display();
                            printf("\n\nPlayer %d \n",player);
                            printf("Select the number : ");
                            scanf("%d",&n);
                            move(n);
                            if(check())
                                {
                                    char c;
                                    system("cls");
                                    display_P();
                                    display();
                                    printf("\nplayer %d won\n",player);
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }
                            if(moves==9)
                                {
                                    char c;
                                    system("cls");
                                    display_P();
                                    display();
                                    printf("\nDraw ! ");
                                    system("pause");
                                    printf("enter y or Y to play again if not enter anything: ");
                                    fflush(stdin);
                                    scanf("%c",&c);
                                    if(c=='y' || c=='Y')
                                        continue;
                                    exit(0);
                                }

                            player=player==1?2:1;


                        }
                }
            else if(n==4)
                exit(0);
            else
                printf("Invalid Choice\n");
            system("pause");
            continue;
        }

    display();
    return 0;
}
