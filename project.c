#include <stdio.h>
#include <stdlib.h>
int arr[24][24];

void interface(void)
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 3;
    arr[23][0] = 3;
    arr[0][23] = 3;
    arr[23][23] = 3;
}


void print_grid(void)
{
    int count = 0;
    printf("\n");
    printf("    A    B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W    X\n");
    for (int i = 0; i < 24; i++)
    {
        if (i == 1 || i == 23)
        {
            printf("        \033[34m―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――\033[0m\n");
        }

        for (int j = 0; j < 24; j++)
        {
            if (i < 23 && i > 0)
            {
                if (j == 1 || j == 23)
                {
                    printf("\033[31m│ \033[0m");
                }
            }
            if(j==0)
            {   
                if(count < 10 )
                {
                    printf("%d   ",count);
                   count ++;
                }
                else
                {
                    printf("%d  ",count);
                    count++;
                }
            }
            if (i == 0 && (j == 0 || j == 23))
            {   
                printf("     ");    
                continue;
            }
            if (i == 23 && (j == 0 || j == 23))
            {
                printf("     ");    
                continue;
            }

            if (arr[i][j] == 0)
            {
                printf("⚫ ");
            }
            else if (arr[i][j] == 1)
            {
                printf("🔴 ");
            }
            else if (arr[i][j] == 2)
            {
                printf("🔵 ");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    printf("To 'START' a new game, enter (A 0)!\n");
    printf("To 'RESIGN' the game, enter (A -1)!\n");
    printf("To 'SHOW' the board, enter (X 23)!\n");

    interface();
    print_grid();

    int chance = 1;
   
    while (1)
    {
        if (chance == 1)
        {
            printf("\033[31mRED'S CHANCE\033[0m\n");
            printf("Enter the input (x y): ");
            int i;
            char a;
            int j;
            scanf(" %c %d", &a, &i);
            j=a-'A';
            if(i>0 && j>=0 && j<24 && i<23 && arr[i][j]!= 0)
            {   
                printf("The circle is already occupied!\n");
                chance = 1;
            }
            else if(i == 0 && j <= 23 && j!=0)
            {
                printf("Input Invalid!\n");
                chance = 1;
            }
            else if(i == 23  && j<23)
            {
                printf("Input Invalid!\n");
                chance = 1;
            }
            else if(i<-1 || j<=-1 || i>23 || j>23 ) 
            {
                printf("Input Invalid!\n");
                chance = 1;
            }
            else if(i==-1 && j==0)
            {
                printf("RED resigns!.\n\033[34mBlue Wins!\033[0m\n");
                break;
            }
            else if(i ==0 && j==0)
            {
                printf("Started a New Game!\n");
                interface();
                print_grid();
            }
            else if(arr[i][j] == 0 && i != 0  && i<23 && j<24)
            { 
                arr[i][j] = 1;
                chance = 2;
                print_grid();
            }
            if(i == 23 && j == 23)
            {
                printf("Printing Board!\n");
                chance=1;
                print_grid();
            }
        }
        else
        {
            int i;
            char a;
            int j;
            printf("\033[34mBLUE'S CHANCE\033[0m\n");
            printf("Enter the input (x y): ");
            scanf(" %c %d", &a, &i);   //gap before %c cause skips spaces'\n, ,\t'
            j=a-'A';
            if(i>=0 && j>0 && j<23 && i<24 && arr[i][j]!= 0)
            {   
                printf("The circle is already occupied!\n");
                chance = 2;
            }
            else if(i<-1 || j<=-1 || i>23 || j>23 )
            {
                printf("Input Invalid!\n");
                chance = 2;
            }
            else if( (j == 0 || j == 23) && i < 23 && i>0)
            {
                printf("Input Invalid!\n");
                chance = 2;
            }
            else if(i == 23 &&  j ==0)
            {
                printf("Input Invalid!\n");
                chance = 2;
            }
            else if(i==-1 && j==0)
            {
                printf("BLUE resigns!\n\033[31mRed Wins!\033[0m\n");
                break;
            }
            else if(i ==0 && j==0)
            {
                printf("Started a New Game!\n");
                interface();
                chance =1 ;
                print_grid();
            }
            else if(arr[i][j] == 0 && (j != 0 && j!=23) && i<24 && j <23 && i>=0 && j>0)
            { 
                arr[i][j] = 2;
                chance = 1;
                print_grid();
            }
            if(i == 23 && j == 23)
            {
                printf("Printing BROAD!\n");
                chance = 2;
                print_grid();
            }
        }
    }
}