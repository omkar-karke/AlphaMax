#include"All_Possible_Moves.h"

//Modifies the array of size 4
void All_Rook_Moves(int rook_row , int rook_column , char board[8][8] , int arr[4] ,int colour)
{
    /*
    colour =0 => WHITE
    colour=1  => BLACK

    //index_o => row index increases , with column index constant
    //index_1 => row index decreases , with column index constant
    //index_2 => row index constant , with column index increases
    //index_3 => row index constant , with column index decreases
    */

    int count=0;
    //For index 0
    for(int i=rook_row+1 ; i<=7 ; i++)
    {
        if(board[i][rook_column]=='0')
            count++;
        else
        {
            if((colour==0)&&((board[i][rook_column]=='p')||(board[i][rook_column]=='r')||(board[i][rook_column]=='n')||(board[i][rook_column]=='b')||(board[i][rook_column]=='q')||(board[i][rook_column]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[i][rook_column]=='P')||(board[i][rook_column]=='R')||(board[i][rook_column]=='N')||(board[i][rook_column]=='B')||(board[i][rook_column]=='Q')||(board[i][rook_column]=='K')))
            {
                count++;
                break;
            }
            else
                break;
        }
    }
    arr[0]=count;
    count=0;



    //For index 1
    for(int i=rook_row-1 ; i>=0 ; i--)
    {
        if(board[i][rook_column]=='0')
            count++;
        else
        {
            if((colour==0)&&((board[i][rook_column]=='p')||(board[i][rook_column]=='r')||(board[i][rook_column]=='n')||(board[i][rook_column]=='b')||(board[i][rook_column]=='q')||(board[i][rook_column]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[i][rook_column]=='P')||(board[i][rook_column]=='R')||(board[i][rook_column]=='N')||(board[i][rook_column]=='B')||(board[i][rook_column]=='Q')||(board[i][rook_column]=='K')))
            {
                count++;
                break;
            }
            else
                break;
        }
    }
    arr[1]=count;
    count=0;



    //For index 2
    for(int i=rook_column+1 ; i<=7 ; i++)
    {
        if(board[rook_row][i]=='0')
            count++;
        else
        {
            if((colour==0)&&((board[rook_row][i]=='p')||(board[rook_row][i]=='r')||(board[rook_row][i]=='n')||(board[rook_row][i]=='b')||(board[rook_row][i]=='q')||(board[rook_row][i]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[rook_row][i]=='P')||(board[rook_row][i]=='R')||(board[rook_row][i]=='N')||(board[rook_row][i]=='B')||(board[rook_row][i]=='Q')||(board[rook_row][i]=='K')))
            {
                count++;
                break;
            }
            else
                break;
        }
    }
    arr[2]=count;
    count=0;



    //For index 3
    for(int i=rook_column-1 ; i>=0 ; i--)
    {
        if(board[rook_row][i]=='0')
            count++;
        else
        {
            if((colour==0)&&((board[rook_row][i]=='p')||(board[rook_row][i]=='r')||(board[rook_row][i]=='n')||(board[rook_row][i]=='b')||(board[rook_row][i]=='q')||(board[rook_row][i]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[rook_row][i]=='P')||(board[rook_row][i]=='R')||(board[rook_row][i]=='N')||(board[rook_row][i]=='B')||(board[rook_row][i]=='Q')||(board[rook_row][i]=='K')))
            {
                count++;
                break;
            }
            else
                break;
        }
    }
    arr[3]=count;


    return;
}

//Modifies array of size 4
void All_Bishop_Moves(int bishop_row , int bishop_column , char board[8][8] , int arr[4] , int colour)
{
    /*
    //colour =0 => WHITE
    //colour=1  => BLACK

    //index_o => row index decreases ,  column index increases     (MOVING TOWARDS TOP RIGHT CORNER)
    //index_1 => row index decreases ,  column index decreases       (MOVING TOWARDS TOP LEFT CORNER)
    //index_2 => row index increases ,  column index decreases      (MOVING TOWARDS BOTTOM LEFT CORNER)
    //index_3 => row index increases ,  column index increases      (MOVING TOWARDS BOTTOM RIGHT CORNER)

    */

    int count=0;
    int i=1;
    while(i<=7)     //FOR => index_o => row index decreases ,  column index increases     (MOVING TOWARDS TOP RIGHT CORNER)
    {
        int row=bishop_row - i;
        int column=bishop_column + i;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7))
        {
            if(board[row][column]=='0')
            {
                count++;
            }
            else if((colour==0)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            {
                count++;
                break;
            }
            else
                break;

            i++;
        }
        else
            break;
    }
    arr[0]=count;
    count=0;
    i=1;



    while(i<=7)         //index_1 =>For row index decreases ,  column index decreases       (MOVING TOWARDS TOP LEFT CORNER)
    {
        int row=bishop_row - i;
        int column=bishop_column - i;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7))
        {
            if(board[row][column]=='0')
            {
                count++;
            }
            else if((colour==0)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            {
                count++;
                break;
            }
            else
                break;

            i++;
        }
        else
            break;
    }
    arr[1]=count;
    count=0;
    i=1;


    while(i<=7)         //FOR index_2 => row index increases ,  column index decreases      (MOVING TOWARDS BOTTOM LEFT CORNER)
    {
        int row=bishop_row + i;
        int column=bishop_column - i;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7))
        {
            if(board[row][column]=='0')
            {
                count++;
            }
            else if((colour==0)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            {
                count++;
                break;
            }
            else
                break;

            i++;
        }
        else
            break;
    }
    arr[2]=count;
    count=0;
    i=1;



    while(i<=7)         //FOR index_3 => row index increases ,  column index increases      (MOVING TOWARDS BOTTOM RIGHT CORNER)
    {
        int row=bishop_row + i;
        int column=bishop_column + i;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7))
        {
            if(board[row][column]=='0')
            {
                count++;
            }
            else if((colour==0)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            {
                count++;
                break;
            }
            else if((colour==1)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            {
                count++;
                break;
            }
            else
                break;

            i++;
        }
        else
            break;
    }

    arr[3]=count;

}


//Modifies array of size 8
//Uses All_Bishop_Moves and All_Rook_Moves
void All_Queen_Moves(int queen_row , int queen_column , char board[8][8] , int arr[8] , int colour)
{
    /*
    //index_o => row index increases , with column index constant
    //index_1 => row index decreases , with column index constant
    //index_2 => row index constant , with column index increases
    //index_3 => row index constant , with column index decreases

    //index_4 => row index decreases ,  column index increases     (MOVING TOWARDS TOP RIGHT CORNER)
    //index_5 => row index decreases ,  column index decreases       (MOVING TOWARDS TOP LEFT CORNER)
    //index_6 => row index increases ,  column index decreases      (MOVING TOWARDS BOTTOM LEFT CORNER)
    //index_7 => row index increases ,  column index increases      (MOVING TOWARDS BOTTOM RIGHT CORNER)
    */

    int arr1[4];
    int arr2[4];

    All_Rook_Moves(queen_row , queen_column , board , arr1 , colour);
    All_Bishop_Moves(queen_row , queen_column , board , arr2 , colour);

    for(int i=0 ;i<4 ;i++)
    {
        arr[i]=arr1[i];
    }

    for(int i=0 ;i<4 ;i++)
    {
        arr[4+i]=arr2[i];
    }

}



//Modifies the array of size 8
void All_Knight_Moves(int knight_row , int knight_column , char board[8][8] , int arr[8] , int colour)
{
    int arr_row[8] = {-2 , -1 , 1 , 2 , 2 ,1 ,-1 ,-2};
    int arr_column[8] = {1 ,2 ,2 ,1 ,-1 ,-2 ,-2 ,-1 };

    for(int i=0 ; i<=7 ;i++)
    {
        int row=knight_row + arr_row[i];
        int column=knight_column + arr_column[i];

        if(!(row>=0 && row<=7 && column>=0 && column <=7))
            arr[i]=0;//if destination square not in grid
        else if(board[row][column]=='0')
            arr[i]=1;
        else if((colour==0)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            arr[i]=1;//if white knight is there , then destination pieces must be black
        else if((colour==1)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            arr[i]=1;//if black knight is there , then destination pieces must be white
        else
            arr[i]=0;

    }
}


//Modifies the array of size 4
void All_King_Moves(int king_row , int king_column , char board[8][8] , int arr[4] , int colour)
{
    int arr_row[8]={-1 ,-1 ,0 ,1 ,1 ,1 ,0 ,-1};
    int arr_column[8]={0 ,1 , 1 , 1 , 0 , -1 ,-1 , -1};

    for(int i=0 ; i<=7 ;i++)
    {
        int row=king_row + arr_row[i];
        int column=king_column + arr_column[i];

        if(!(row>=0 && row<=7 && column>=0 && column <=7))
            arr[i]=0;//if destination square not in grid
        else if(board[row][column]=='0')
            arr[i]=1;
        else if((colour==0)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            arr[i]=1;//if white knight is there , then destination pieces must be black
        else if((colour==1)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            arr[i]=1;//if black knight is there , then destination pieces must be white
        else
            arr[i]=0;
    }
}




//Modifies array of size 4
void All_Pawn_Moves(int pawn_row , int pawn_column , char board[8][8] , int arr[4] , int colour)
{
    if(colour%2==0)
    {
        /*
        //index_0   => 1 step forward =>column same and row decreases by 1
        //index_1   => 2 step forward =>column same and row decreases by 2
        //index_2   => row decreases by 1 , and column decreases by 1   (LEFT DIAGONAL SQUARE)
        //index_3   => row decreases by 1 , and column increases by 1   (RIGHT DIAGONAL SQUARE)
        */

        //index_0   => 1 step forward =>column same and row decreases by 1
        int row = pawn_row-1;
        int column = pawn_column;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7)&&(board[row][column]=='0'))
            arr[0]=1;
        else
            arr[0]=0;


        //index_1   => 2 step forward =?column same and row decreases by 2
        row = pawn_row-2;
        column = pawn_column;

        if((pawn_row==6)&&(column>=0)&&(column<=7)&&(board[row+1][column]=='0')&&(board[row][column]=='0'))
            arr[1]=1;
        else
            arr[1]=0;


        //index_2   => row decreases by 1 , and column decreases by 1   (LEFT DIAGONAL SQUARE)
        row=pawn_row-1;
        column=pawn_column-1;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            arr[2]=1;
        else
            arr[2]=0;


        //index_3   => row decreases by 1 , and column increases by 1   (RIGHT DIAGONAL SQUARE)
        row=pawn_row-1;
        column=pawn_column+1;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7)&&((board[row][column]=='p')||(board[row][column]=='r')||(board[row][column]=='n')||(board[row][column]=='b')||(board[row][column]=='q')||(board[row][column]=='k')))
            arr[3]=1;
        else
            arr[3]=0;
    }
    else
    {
        /*
        //index_0   => 1 step forward =>column same and row increases by 1
        //index_1   => 2 step forward =>column same and row increases by 2
        //index_2   => row increases by 1 , and column increases by 1   (LEFT DIAGONAL SQUARE)
        //index_3   => row increases by 1 , and column decreases by 1   (RIGHT DIAGONAL SQUARE)
        */


        //index_0   => 1 step forward =>column same and row increases by 1
        int row = pawn_row+1;
        int column = pawn_column;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7)&&(board[row][column]=='0'))
            arr[0]=1;
        else
            arr[0]=0;



        //index_1   => 2 step forward =>column same and row increases by 2
        row = pawn_row+2;
        column = pawn_column;

        if((pawn_row==1)&&(column>=0)&&(column<=7)&&(board[row-1][column]=='0')&&(board[row][column]=='0'))
            arr[1]=1;
        else
            arr[1]=0;



        //index_2   => row increases by 1 , and column increases by 1   (LEFT DIAGONAL SQUARE)
        row=pawn_row+1;
        column=pawn_column+1;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            arr[2]=1;
        else
            arr[2]=0;


        //index_3   => row increases by 1 , and column decreases by 1   (RIGHT DIAGONAL SQUARE)
        row=pawn_row+1;
        column=pawn_column-1;

        if((row>=0)&&(row<=7)&&(column>=0)&&(column<=7)&&((board[row][column]=='P')||(board[row][column]=='R')||(board[row][column]=='N')||(board[row][column]=='B')||(board[row][column]=='Q')||(board[row][column]=='K')))
            arr[3]=1;
        else
            arr[3]=0;

    }
}
