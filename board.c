#include<stdio.h>
#include "board.h"


//WHITE => Upper Case
//BLACK => Lower Case
void init_chess_board(char arr[8][8])
{
    //0 indicates empty square on Board , That has neither Black nor White Pieces on it
    for(int i=0 ;i<8 ;i++)  //Initializing Each Square as empty Square
    {
        for(int j=0 ;j<8 ;j++)
        {
            arr[i][j]='0';
        }
    }

    //Initializing all other positions of the board , with appropriate pieces
    for(int j=0 ;j<8 ;j++)
    {
        arr[1][j]='p';
        arr[6][j]='P';


        if((j==0)||(j==7))
        {
            arr[0][j]='r';
            arr[7][j]='R';
        }
        else if((j==1)||(j==6))
        {
            arr[0][j]='n';
            arr[7][j]='N';
        }
        else if((j==2)||(j==5))
        {
            arr[0][j]='b';
            arr[7][j]='B';
        }
        else if(j==3)
        {
            arr[0][j]='q';
            arr[7][j]='Q';
        }
        else
        {
            arr[0][j]='k';
            arr[7][j]='K';
        }
    }
}

//After initializing , The Board would look like This
/*
8  |  r  |  n  |  b  |  q  |  k  |  b  |  n  |  r  |
   --------------------------------------------------
7  |  p  |  p  |  p  |  p  |  p  |  p  |  p  |  p  |
   --------------------------------------------------
6  |     |     |     |     |     |     |     |     |
   --------------------------------------------------
5  |     |     |     |     |     |     |     |     |
   --------------------------------------------------
4  |     |     |     |     |     |     |     |     |
   --------------------------------------------------
3  |     |     |     |     |     |     |     |     |
   --------------------------------------------------
2  |  P  |  P  |  P  |  P  |  P  |  P  |  P  |  P  |
   --------------------------------------------------
1  |  R  |  N  |  B  |  Q  |  K  |  B  |  N  |  R  |
   --------------------------------------------------

       A     B    C     D     E      F     G     H

Standard Board Representation
Ranks Are Rows     ....
Files Are Columns  ....

*/


void print_board( char board[8][8])
{
    printf("\n");

    for (int i=0; i<8; i++){
        printf("%d  ", 8-i);
        for (int j=0; j<8; j++)
        {
            if(board[i][j]!='0')
                printf("|  %c  ", board[i][j]);
            else
                printf("|     ");
        }
        printf("|\n");
        printf("   --------------------------------------------------\n");
    }
    printf("\n");

    printf("       A     B    C     D     E      F     G     H\n\n");
}


