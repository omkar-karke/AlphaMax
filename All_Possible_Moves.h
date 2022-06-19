#ifndef ALL_POSSIBLE_MOVES_H_INCLUDED
#define ALL_POSSIBLE_MOVES_H_INCLUDED

void All_Rook_Moves(int rook_row , int rook_column , char board[8][8] , int arr[4] , int colour);

void All_Knight_Moves(int knight_row , int knight_column , char board[8][8] , int arr[8] , int colour);

void All_King_Moves(int king_row , int king_column , char board[8][8] , int arr[4] , int colour);

void All_Bishop_Moves(int bishop_row , int bishop_column , char board[8][8] , int arr[4] , int colour);

void All_Queen_Moves(int queen_row , int queen_column , char board[8][8] , int arr[8] , int colour);

void All_Pawn_Moves(int pawn_row , int pawn_column , char board[8][8] , int arr[4] , int colour);

#endif // ALL_POSSIBLE_MOVES_H_INCLUDED
