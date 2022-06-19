#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

void convert_charactermove_to_board_indices(char from_row, char from_column, char to_row, char to_column, int *f_row, int *f_column, int *t_row, int *t_column);

void convert_board_indices_to_charactermove(char* from_row, char* from_column, char* to_row, char* to_column, int f_row, int f_column, int t_row, int t_column);

#endif // CONVERSION_H_INCLUDED
