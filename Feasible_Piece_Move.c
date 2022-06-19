#include"Feasile_Piece_Move.h"
#include"conversion.h"
#include<stdlib.h>



/*
Rook moves only in Same Row and Same Column
if its valid then it returns 1 else it returns 0
4 cases => up / down /left /right
*/
int Inspect_Rook_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8])
{
    int f_row , f_column , t_row , t_column ;
    convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );

    //No need to check here , if from square and to squares are valid
    //But Why??
    //Because we come to this function only after , isValid Square Returns 1

    if(f_column == t_column)        //to Square in Same Column
    {
        if(f_row > t_row)
        {
            for(int i=t_row+1 ; i<=f_row-1 ;i++)
            {
                if(!(board[i][f_column]=='0'))  //All Squares in between from Square and To Square must be empty
                {
                    return 0;
                }
            }
            return 1;
        }
        else
        {
            for(int i=f_row+1 ; i<=t_row-1 ;i++)
            {
                 if(!(board[i][f_column]=='0')) //All Squares in between from Square and To Square must be empty
                 {
                    return 0;
                 }
            }
            return 1;
        }
    }
    else if(f_row==t_row)           //to Square in Same row
    {
            if(f_column>t_column)
            {
                for(int i=t_column+1 ; i<=f_column-1 ;i++)
                {
                    if(!(board[f_row][i]=='0'))     //All Squares in between from Square and To Square must be empty
                    {
                        return 0;
                    }
                }
                return 1;
            }
            else
            {
                for(int i=f_column+1 ; i<=t_column-1 ;i++)
                {
                    if(!(board[f_row][i]=='0'))     //All Squares in between from Square and To Square must be empty
                    {
                        return 0;
                    }
                }
                return 1;
            }
    }

    return 0;   //if squares are not in same row or same column return 0
}


/*
4 cases
Diagonally UpRight , Diagonally UpLeft , Diagonally BottomRight , Diagonally BottomLeft
*/
int Inspect_Bishop_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8])
{
    //Converting row ,columns indexes to int
    int f_row , f_column , t_row , t_column ;
    convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );

    /*
    No need to check here , if from square and to squares are valid
    But Why??
    Because we come to this function only after , isValid Square Returns 1
    */

    if((abs(t_row-f_row))==(abs(t_column-f_column)))
    {
        if((f_row > t_row )&&(f_column > t_column))
        {
            int count=1;
            while(t_row + count < f_row)
            {
                if(!(board[t_row+count][t_column+count]=='0'))  //All Squares in between from Square and To Square must be empty
                {
                    return 0;
                }
                count++;
            }
            return 1;
        }
        else if((f_row > t_row)&&(t_column > f_column))
        {
            int count=1;
            while(t_row+count<f_row)
            {
                if(!(board[t_row+count][t_column-count]=='0'))    //All Squares in between from Square and To Square must be empty
                {
                    return 0;
                }
                count++;
            }
            return 1;
        }
        else if((f_row < t_row )&&(f_column < t_column))
        {
            int count=1;
            while(f_row + count < t_row)
            {
                if(!(board[f_row+count][f_column+count]=='0'))     //All Squares in between from Square and To Square must be empty
                {
                    return 0;
                }
                count++;
            }
            return 1;
        }
        else
        {
            int count=1;
            while(f_row+count<t_row)
            {
                if(!(board[f_row+count][f_column-count]=='0'))      //All Squares in between from Square and To Square must be empty
                {
                    return 0;
                }
                count++;
            }
            return 1;
        }
    }

    return 0;
}


//if AnyOne of Rook/Bishop move isValid then Queens Move is Valid
int Inspect_Queen_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8])
{
    if(Inspect_Rook_Move(from_row  ,  from_column  , to_row ,  to_column  ,  board) )
        return 1;

    return Inspect_Bishop_Move(from_row  ,  from_column  ,  to_row  ,  to_column  ,  board);
}


//if its valid then it returns 1 else it returns 0
int Inspect_Knight_Move(char from_row, char from_column, char to_row, char to_column)
{
    //Converting row ,columns indexes to int
    int f_row , f_column , t_row , t_column ;
    convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );


    //No need to check here , if from square and to squares are valid
    //But Why??
    //Because we come to this function only after , isValid Square Returns 1

    if(((abs(f_row-t_row)==2)&&(abs(f_column-t_column)==1))||((abs(f_row-t_row)==1)&&(abs(f_column-t_column)==2)))      //Logic
        return 1;

    return 0;
}


int Inspect_King_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8])
{
    int f_row , f_column , t_row , t_column ;
    convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );

    //No need to check here , if from square and to squares are valid
    //But Why??
    //Because we come to this function only after , isValid Square Returns 1

    if((abs(f_row-t_row)<=1)&&(abs(f_column-t_column)<=1))      //Logic
        return 1;


    return 0;
}


int Inspect_Pawn_Move(char from_row, char from_column, char to_row, char to_column, int counter ,char board[8][8])
{
    int f_row , f_column , t_row , t_column ;
    convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );

    if(counter%2==0)        //Whites Move
    {

        if(board[t_row][t_column]=='0')     //When to square is empty , then it can only move Forward
        {
            if(((f_row-t_row)==1)&&(f_column==t_column))    //Moving one step Forward
                return 1;
            else if((f_row==6)&&(board[f_row-1][f_column]=='0')&&((f_row-t_row)==2)&&(f_column==t_column))      //Moving two step Forward
                return 1;
        }
        else                                //When to square is not empty , then it can only move Diagonally
        {
            if(((f_row - t_row)==1)&&((t_column - f_column)==1))    //Moving 1 step towards its right
                return 1;
            else if(((f_row - t_row)==1)&&((f_column - t_column)==1))   //Moving one step towards its left
                return 1;
        }
        return 0;
    }
    else            //Blacks Move
    {
        if(board[t_row][t_column]=='0')     //When to square is empty , then it can only move Forward
        {
            if(((t_row-f_row)==1)&&(f_column==t_column))        //Moving one step Forward
                return 1;
            else if((f_row==1)&&(board[f_row+1][f_column]=='0')&&((t_row-f_row)==2)&&(f_column==t_column))       //Moving two step Forward
                return 1;
        }
        else         //When to square is not empty , then it can only move Diagonally
        {
            if(((t_row - f_row)==1)&&((t_column - f_column)==1))        //Moving one step towards its left
                return 1;
            else if(((t_row - f_row)==1)&&((f_column - t_column)==1))     //Moving 1 step towards its right
                return 1;
        }
        return 0;
    }
}
