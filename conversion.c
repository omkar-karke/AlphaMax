#include "conversion.h"



void convert_charactermove_to_board_indices(char from_row, char from_column, char to_row, char to_column, int *f_row, int *f_column, int *t_row, int *t_column)
{
    //converting user input to chessboard-suitable indices for accesing the pieces
    *f_row = 8-(from_row - '0');
    *f_column = from_column - 'a';
    *t_row = 8-(to_row - '0');
    *t_column = to_column - 'a';

    return;
}

void convert_board_indices_to_charactermove(char* from_row, char* from_column, char* to_row, char* to_column, int f_row, int f_column, int t_row, int t_column)
{

    *from_row = 8 - f_row + '0';
    *from_column = f_column + 'a';
    *to_row = 8 - t_row + '0';
    *to_column = t_column + 'a';

    return;
}
