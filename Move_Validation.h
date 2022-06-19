#ifndef MOVE_VALIDATION_H_INCLUDED
#define MOVE_VALIDATION_H_INCLUDED

/*
Initial and Final Square are in Grid
from Square =>Players Piece
to square =>either empty or opponents piece
*/
int is_Valid_Square(char from_row, char from_column, char to_row, char to_column, int counter, char board[8][8]);




/*
This is_Valid_Move
It sees which piece is making a move  ,
And by Using it Gives a Call To One Of The Above Functions And ThereBy Makes A Check If A Move Is Valid
*/
int is_Piece_Move_Feasible(char from_row, char from_column, char to_row, char to_column, int counter, char board[8][8]);




/*
Even if isValidMove returns 1  ,then also a final Condition is remaining that needs to be checked , For a Move To Be Valid
Its The King ExPosed Function
*/
int Check_Move(char from_row, char from_column, char to_row, char to_column, int counter, char board[8][8]);



#endif // MOVE_VALIDATION_H_INCLUDED
