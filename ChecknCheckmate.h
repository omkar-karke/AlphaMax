#ifndef CHECKNCHECKMATE_H_INCLUDED
#define CHECKNCHECKMATE_H_INCLUDED

/*
After Whites Move is Valid , and After we Have Performed the Whites Move
Before Asking Other Player TO Make A  Move , we are just seeing if White has Given CHECK to BLACK KING
*/
int black_king_under_check(char board[8][8]);


/*
After Blacks Move is Valid , and After we Have Performed the Blacks Move .
Before Asking Other Player TO Make A  Move , we are just seeing if Black has Given CHECK to WHITE KING .
*/
int white_king_under_check(char board[8][8]);


int is_Black_King_Checkmate(char board[8][8]);
int is_White_King_Checkmate(char board[8][8]);

#endif // CHECKMATE_H_INCLUDED
