#include"Move_Validation.h"
#include"conversion.h"
#include"Feasile_Piece_Move.h"




/*
Square is in Grid
from Square =>Players Piece
to square =>either empty or opponents piece
if its valid then it returns 1 else it returns 0
*/
int is_Valid_Square(char from_row, char from_column, char to_row, char to_column, int counter, char board[8][8])
{
    //Converting row ,columns indexes to int
    int f_row , f_column , t_row , t_column ;
    convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );

    if ( (f_row >=0 && f_row <=7) && (f_column>=0 && f_column<=7) && (t_row >=0 && t_row <=7) && (t_column>=0 && t_column<=7) )//if square is in grid
    {
        if (counter % 2 == 0)//if its Whites Move
        {
            char f_piece = board[f_row][f_column];
            if (!(f_piece == 'P' || f_piece == 'R' || f_piece == 'N' || f_piece == 'B' || f_piece == 'Q' || f_piece == 'K')){//Checking if from square has Players Piece
                return 0;
            }

            char t_piece = board[t_row][t_column];

            if (!(t_piece == 'p' || t_piece == 'r' || t_piece == 'n' || t_piece == 'b' || t_piece == 'q' || t_piece == 'k' || t_piece =='0')){//to square =>either empty or opponents piece

                return 0;
            }
        }
        else{

            char f_piece = board[f_row][f_column];

            if (!(f_piece == 'p' || f_piece == 'r' || f_piece == 'n' || f_piece == 'b' || f_piece == 'q' || f_piece == 'k')){//Checking if from square has Players Piece
                return 0;
            }

            char t_piece = board[t_row][t_column];

            if (!(t_piece == 'P' || t_piece == 'R' || t_piece == 'N' || t_piece == 'B' || t_piece == 'Q' || t_piece == 'K' || t_piece =='0')){//to square =>either empty or opponents piece
                return 0;
            }
        }
        return 1;
    }

    return 0;

}





/*
Once is_Valid_Square returns 1 , then we give call to this Function
If the squares are valid , this function is to check weather the piece can move from , start square to destination square
It checks which piece is at from square and gives call to that piece_function , to check if that move can be made by that piece
If that move can be made ,then it returns 1 , else it returns 0
*/
int is_Piece_Move_Feasible(char from_row, char from_column, char to_row, char to_column, int counter, char board[8][8])
{
    int f_row , f_column , t_row , t_column ;
    convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );

    char piece = board[f_row][f_column];


    if((piece=='r')||(piece=='R'))
    {
        return Inspect_Rook_Move(from_row, from_column, to_row, to_column , board);
    }
    else if((piece=='b')||(piece=='B'))
    {
        return Inspect_Bishop_Move(from_row, from_column, to_row, to_column , board);
    }
    else if((piece=='q')||(piece=='Q'))
    {
        return Inspect_Queen_Move(from_row, from_column, to_row, to_column , board);
    }
    else if((piece=='k')||(piece=='K'))
    {
        return Inspect_King_Move(from_row, from_column, to_row, to_column , board);
    }
    else if((piece=='n')||(piece=='N'))
    {
        return Inspect_Knight_Move(from_row, from_column, to_row, to_column );
    }
    else if((piece=='p')||(piece=='P'))
    {
        return Inspect_Pawn_Move(from_row, from_column, to_row, to_column, counter , board);
    }

    return 0;
}





int Check_Move(char from_row, char from_column, char to_row, char to_column, int counter, char chess_board[8][8])
{
    if(is_Valid_Square(from_row, from_column, to_row, to_column, counter, chess_board)) //Function to check , if from and to squares are valid , if invalid then it would again ask to give input
    {
        if(is_Piece_Move_Feasible(from_row, from_column, to_row, to_column, counter, chess_board))//If the squares are valid , this function is to check weather the piece can move from , start square to destination square
        {
            return 1;
        }
    }

    return 0;
}
