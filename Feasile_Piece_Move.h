#ifndef FEASIBLE_PIECE_MOVE_H_INCLUDED
#define FEASIBLE_PIECE_MOVE_H_INCLUDED


//Check_Piece_Move
/*These Functions return 1 if we can move from a given initial position to the given final position
Else they return 0
*/



int Inspect_Rook_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8]);
int Inspect_Knight_Move(char from_row, char from_column, char to_row, char to_column);
int Inspect_Bishop_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8]);
int Inspect_Queen_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8]);
int Inspect_King_Move(char from_row, char from_column, char to_row, char to_column, char board[8][8]);
int Inspect_Pawn_Move(char from_row, char from_column, char to_row, char to_column, int counter , char board[8][8]);



#endif // CHECK_MOVE_H_INCLUDED
