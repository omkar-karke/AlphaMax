#ifndef MOVE_GENERATION_H_INCLUDED
#define MOVE_GENERATION_H_INCLUDED

int Make_White_Move(char from_row, char from_column, char to_row, char to_column, int *counter, char board[8][8]);

int Make_Black_Move(char from_row, char from_column, char to_row, char to_column, int *counter, char board[8][8]);

#endif // MOVE_GENERATION_H_INCLUDED
