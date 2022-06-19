#include <stdio.h>
#include"board.h"
#include"conversion.h"
#include"Move_Generation.h"
#include"MiniMax.h"
#include<limits.h>
#include<time.h>

void get_input(char* from_column , char* from_row ,char* to_column , char* to_row);

int main()
{
    char chess_board[8][8];

    int mode;
    int counter=0;
    char from_column , from_row , to_column , to_row ;


    printf("+++++++++++++++++++++++++++++++++++Select Mode for Game++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("                    Press 1 for 1 Player Game , to play with bot\n");
    printf("                    Press 2 for 2 Player Game \n");
    scanf("%d",&mode);
    while(getchar()!='\n'); //Clearing the Buffer of getchar function

    while(!(mode==1 || mode==2))
    {
        printf("+++++++++++++++++++++++++++++++++++Select Valid Mode for Game++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("                Press 1 for 1 Player Game , to play with bot\n");
        printf("                Press 2 for 2 Player Game \n");
        scanf("%d",&mode);
        while(getchar()!='\n'); //Clearing the Buffer of getchar function
    }

    init_chess_board(chess_board);
    print_board(chess_board);

    if(mode==1)
    {
        while(1)
        {
            if(counter%2==0)        //If Counter is even it would ask White Player To Make Move
            {
                printf("Its Your Turn : Please Make a Move : \n");

                //To take input for move From User
                get_input(&from_column , &from_row , &to_column , &to_row);


                //if it returns 0 => Check_Mate.....EndGame
                if(!(Make_White_Move(from_row, from_column, to_row, to_column, &counter, chess_board)))
                {
                    break;
                }

            }
            else        //If Counter is Odd it Would ask Black Player To make Move
            {
                printf("Bot will Make a Move Now \n");

                clock_t begin = clock();

                int alpha=INT_MIN;
                int beta= INT_MAX;
                int* arr= minimax( chess_board , counter , 4 , alpha , beta);

                //Make Move Accept Character indices , hence its needed.....
                convert_board_indices_to_charactermove(&from_row , &from_column , &to_row, &to_column, arr[0], arr[1] , arr[2] , arr[3]);

                if(!(Make_Black_Move(from_row, from_column, to_row, to_column, &counter, chess_board)))
                {
                    break;
                }

                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("Time Spent For this Move = %f\n",time_spent);
            }
        }
    }
    else
    {
        while(1)
        {
            if(counter%2==0)        //If Counter is even it would ask White Player To Make Move
            {
                printf("Player 1: Please Make a Move : \n");

                //To take input for move From User
                get_input(&from_column , &from_row , &to_column , &to_row);

                if(!(Make_White_Move(from_row, from_column, to_row, to_column, &counter, chess_board)))
                {
                    break;
                }
            }
            else        //If Counter is Odd it Would ask Black Player To make Move
            {
                printf("Player 2: Please Make a Move : \n");

                //To take input for move From User
                get_input(&from_column , &from_row , &to_column , &to_row);

                if(!(Make_Black_Move(from_row, from_column, to_row, to_column, &counter, chess_board)))
                {
                    break;
                }
            }
        }
    }
    return 0;
}



void get_input(char* from_column , char* from_row ,char* to_column , char* to_row)
{
    printf("From Square :");        //Taking input , piece in which square we want to move
    *from_column=getchar();
    *from_row=getchar();
    while(getchar()!='\n'); //Clearing the Buffer of getchar function

    printf("To Square :");          //Taking input, where we want to move our piece
    *to_column=getchar();
    *to_row=getchar();
    while(getchar()!='\n'); //Clearing the Buffer of getchar function
}
