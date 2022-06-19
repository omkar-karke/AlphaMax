#include<stdio.h>
#include"Move_Generation.h"
#include"Move_Validation.h"
#include"board.h"
#include"conversion.h"
#include"ChecknCheckmate.h"
#include"Feasile_Piece_Move.h"




int Make_White_Move(char from_row, char from_column, char to_row, char to_column, int *counter, char chess_board[8][8])
{
    if(Check_Move(from_row, from_column, to_row, to_column, *counter, chess_board))
    {
        //from row,column  and to row ,column are in characters
        //So must be converted to integers , so that can be used as indexes in 2d array , for accessing that particular element
        int f_row , f_column , t_row , t_column ;
        convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );


        //storing the positions of board before move so as to UNDO it , if move is INVALID due to King_Exposed Issues after Move
        char before_move_from=chess_board[f_row][f_column];
        char before_move_to=chess_board[t_row][t_column];


        //Making the move , as squares are also valid and piece can also move from start square to destination square
        chess_board[t_row][t_column]=chess_board[f_row][f_column];
        chess_board[f_row][f_column]='0';



        //The only issue is , if after move King_is_Exposed to attack , then it would not be  a valid move


        //Check if King is Exposed To Attack After Move
        //If YES => INVALID MOVE
        //else => Its a valid move
        if(white_king_under_check(chess_board))
        {
            printf("Invalid Move : Give another Move ....      \n''''\t\t KING EXPOSED TO ATTACK ''''\n");

            //UNDO THE MOVE
            chess_board[f_row][f_column]=before_move_from;
            chess_board[t_row][t_column]=before_move_to;
        }
        else
        {

            printf("                LATEST MOVE     : ");
            printf("From Position : %c%c    \n",from_column ,from_row);
            printf("To Position : %c%c    \n",to_column ,to_row);
            printf("\n\n\n");
            print_board(chess_board);




            (*counter)++;      //Incrementing Counter indicates , Whites turn over , Hence it will ask Black to make next move

            //Are we Giving Check To the Opposition King !!!
            //We must tell the opposition player that we have given Check ,to your King
            if(black_king_under_check(chess_board))
            {
                printf("\n \t\t Black King is Under Check \n");
                //Check for CheckMate
                if(is_Black_King_Checkmate(chess_board))
                {
                    printf("White WINS");
                    return 0;
                }//GAME ENDS HERE
            }
            else
            {
                //Check if Black is StaleMate
                if(is_Black_King_Checkmate(chess_board))
                {
                    printf("Black is StaleMate");
                    printf("White WINS");
                    return 0;
                }//GAME ENDS HERE
            }
        }
    }
    else
    {
        printf("Invalid Move : Give another Move ....\n");
    }

    return 1;
}


int Make_Black_Move(char from_row, char from_column, char to_row, char to_column, int *counter, char chess_board[8][8])
{
    if(Check_Move(from_row, from_column, to_row, to_column, *counter, chess_board))
    {
        //from row,column  and to row ,column are in characters
        //So must be converted to integers , so that can be used as indexes in 2d array , for accessing that particular element
        int f_row , f_column , t_row , t_column ;
        convert_charactermove_to_board_indices(from_row , from_column , to_row , to_column , &f_row , &f_column , &t_row , &t_column );


        //storing the positions of board before move so as to UNDO it , if move is INVALID due to King_Exposed Issues after Move
        char before_move_from=chess_board[f_row][f_column];
        char before_move_to=chess_board[t_row][t_column];

        //Making the move , as squares are also valid and piece can also move from start square to destination square
        chess_board[t_row][t_column]=chess_board[f_row][f_column];
        chess_board[f_row][f_column]='0';

        //Check if King is Exposed To Attack After Move
        //If YES => INVALID MOVE
        //else => Its a valid move
        if(black_king_under_check(chess_board))
        {
            printf("Invalid Move : Give another Move ....      \n''''\t\t KING EXPOSED TO ATTACK ''''\n");

            //UNDO THE MOVE
            chess_board[f_row][f_column]=before_move_from;
            chess_board[t_row][t_column]=before_move_to;

        }
        else
        {

            printf("LATEST MOVE     :\n");
            printf("From Position : %c%c    \n",from_column , from_row);
            printf("To Position : %c%c    \n",to_column , to_row);


            printf("\n\n\n");
            print_board(chess_board);



            (*counter)++;      //Incrementing Counter indicates , Whites turn over , Hence it will ask Black to make next move


            //Are we Giving Check To the Opposition King !!!
            //We must tell the opposition player that we have given Check ,to your King
            if(white_king_under_check(chess_board))
            {
                printf("\n \t\t White King is Under Check \n");
                //Check for CheckMate
                if(is_White_King_Checkmate(chess_board))
                {
                    printf("BLACK WINS");
                    return 0;
                }//GAME ENDS HERE*/
            }
            else
            {
                //Check if White is StaleMate
                if(is_White_King_Checkmate(chess_board))
                {
                    printf("White King is StaleMate");
                    printf("BLACK WINS");
                    return 0;
                }//GAME ENDS HERE*/

            }
        }

    }
    else         //If move rejected by is_valid_move Function
    {
        printf("Invalid Move : Give another Move ....\n");
    }

    return 1;
}

