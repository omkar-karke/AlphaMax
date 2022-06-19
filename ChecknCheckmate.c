#include"ChecknCheckmate.h"
#include"All_Possible_Moves.h"
#include"Move_Generation.h"
#include"Move_Validation.h"




/*
After Whites Move is Valid , and After we Have Performed the Whites Move
Before Asking Black Player TO Make A  Move , we are just seeing if White has Given CHECK to BLACK KING
*/
int black_king_under_check(char board[8][8])
{
    char from_row , from_column , to_row , to_column;
    int king_row , king_column;

    //Nested loops to iterate through the board and find the position of the Black King
    for(int i=0 ;i<=7 ;i++)
    {
        int flag=0;
        for(int j=0 ; j<=7 ;j++)
        {
            if(board[i][j]=='k')
            {
                king_row=i;
                king_column=j;
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }

    //Converting the integer Based indexes , to character based indexes
    to_row = 8-king_row+'0';
    to_column = 'a' + king_column;

/*travel all the squares on the board , if at any square we get a White piece , check if Black King is OPEN for that White Piece for Attack Or Not*/
    for(int i=0 ;i<=7 ;i++)
    {
        for(int j=0 ; j<=7 ;j++)
        {
            if((board[i][j]=='P')||(board[i][j]=='R')||(board[i][j]=='N')||(board[i][j]=='B')||(board[i][j]=='Q')||(board[i][j]=='K'))//If the piece is a White Piece
            {
                from_row = 8 - i + '0';
                from_column = 'a' + j;

                if(is_Piece_Move_Feasible(from_row, from_column, to_row, to_column, 0 , board))//Can that White Piece , Reach the Blacks King
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}


/*
After Blacks Move is Valid , and After we Have Performed the Blacks Move
Before Asking White Player TO Make A  Move , we are just seeing if Black has Given CHECK to Whites KING
*/
int white_king_under_check(char board[8][8])
{
    char from_row , from_column , to_row , to_column;
    int king_row , king_column;

    //Nested loops to iterate through the board and find the position of the White King
    for(int i=0 ;i<=7 ;i++)
    {
        int flag=0;
        for(int j=0 ; j<=7 ;j++)
        {
            if(board[i][j]=='K')
            {
                king_row=i;
                king_column=j;
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }

    //Converting the integer Based indexes , to character based indexes
    to_row = 8-king_row+'0';
    to_column = 'a' + king_column;

/*travel all the squares on the board , if at any square we get a Black piece , check if Whites King is OPEN for that Black Piece for Attack Or Not*/
    for(int i=0 ;i<=7 ;i++)
    {
        for(int j=0 ; j<=7 ;j++)
        {
            if((board[i][j]=='p')||(board[i][j]=='r')||(board[i][j]=='n')||(board[i][j]=='b')||(board[i][j]=='q')||(board[i][j]=='k'))//If the piece is a Black Piece
            {
                from_row = 8 - i + '0';
                from_column = 'a' + j;

                if(is_Piece_Move_Feasible(from_row, from_column, to_row, to_column, 1 , board))//Can that Black Piece , Reach the Whites King
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}







//Function To Check if Black King is CheckMate
int is_Black_King_Checkmate(char board[8][8])
{
    for(int i=0; i<=7 ;i++)
    {
        for(int j=0; j<=7 ;j++)
        {
            if((board[i][j]=='p')||(board[i][j]=='r')||(board[i][j]=='n')||(board[i][j]=='b')||(board[i][j]=='q')||(board[i][j]=='k'))
            {
                if(board[i][j]=='r')
                {
                    /*
                    // arr[0] => same column no. but row no. increases
                    // arr[1] => same column no. but row no. decreases
                    // arr[2] => same row no. but column no. increases
                    // arr[3] => same row no. but column no. decreses
                    */
                    int arri[4] = {1,-1,0,0};
                    int arrj[4] = {0,0,1,-1};

                    int rook_array[4];
                    All_Rook_Moves(i ,j ,board ,rook_array ,1);

                    for(int type=0; type<=3 ;type++)
                    {

                        int count=rook_array[type];

                        while(count)
                        {

                            int rv = count*arri[type];
                            int cv = count*arrj[type];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];


                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='r';


                            //Check if , is Black King Still Under The Check
                            if(black_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='r';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='r';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }

                            count--;

                        }
                    }
                }


                else if (board[i][j]=='b')
                {

                    // arr[0] => row index decreases but column index increases (Going towards => Top-right corner)
                    // arr[1] => row index decreases but column index decreases (Going towards => Top-left corner)
                    // arr[2] => row index increases but column index decreases (Going towards => bottom-left corner)
                    // arr[3] => row index increases but column index increases (Going towards => bottom-right corner)


                    int arri[4] = {-1, -1, 1, 1};
                    int arrj[4] = {1, -1, -1, 1};


                    int bishop_arr[4];
                    All_Bishop_Moves(i, j, board, bishop_arr, 1);


                    for(int type=0; type<=3 ;type++)
                    {

                        int count=bishop_arr[type];

                        while(count)
                        {

                            int rv = count*arri[type];
                            int cv = count*arrj[type];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];


                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='b';


                            //Check if , is Black King Still Under The Check
                            if(black_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='b';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='b';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }

                            count--;

                        }

                    }

                }

                else if (board[i][j]=='q')
                {


                    int arri[8] = {1,-1,0,0,-1, -1, 1, 1};
                    int arrj[8] = {0,0,1,-1,1, -1, -1, 1};


                    int queen_arr[8];
                    All_Queen_Moves(i, j, board, queen_arr, 1);


                    for(int type=0; type<=7 ;type++)
                    {

                        int count=queen_arr[type];

                        while(count)
                        {

                            int rv = count*arri[type];
                            int cv = count*arrj[type];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];


                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='q';


                            //Check if , is Black King Still Under The Check
                            if(black_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='q';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='q';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }

                            count--;

                        }

                    }

                }

                else if (board[i][j] == 'p')
                {

                    int pawn_arr[4];
                    All_Pawn_Moves(i, j, board, pawn_arr, 1);

                    int row_value[4] = {1, 2, 1, 1};
                    int column_value[4] = {0, 0, 1, -1};

                    for (int km=0; km<4; km++)
                    {
                        if (pawn_arr[km] == 1)
                        {

                            //char before_move_from='n';
                            char before_move_to=board[i+row_value[km]][j+column_value[km]];

                            //move is done;
                            board[i][j]='0';
                            board[i+row_value[km]][j+column_value[km]]='p';


                            //Check if , is Black King Still Under The Check
                            if(black_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='p';
                                board[i+row_value[km]][j+column_value[km]]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='p';
                                board[i+row_value[km]][j+column_value[km]]=before_move_to;

                                return 0;
                            }
                        }
                    }
                }

                else if(board[i][j]=='n')
                {
                    int knight_array[8];
                    All_Knight_Moves(i ,j ,board ,knight_array ,1);

                    int arri[8]={-2 , -1 , +1 , +2 , +2 ,+1 ,-1 , -2};
                    int arrj[8]={+1 , +2 , +2 , +1 , -1 ,-2 ,-2 ,-1 };

                    for(int move_nos=0 ; move_nos <=7 ;move_nos++)
                    {
                        if(knight_array[move_nos]==1)
                        {
                            int rv=arri[move_nos];
                            int cv=arrj[move_nos];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];

                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='n';


                            //Check if , is Black King Still Under The Check
                            if(black_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='n';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='n';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }
                        }
                    }
                }

                else if(board[i][j]=='k')
                {
                    int king_array[8];
                    All_King_Moves(i ,j ,board ,king_array ,1);

                    int arri[8] = {-1 ,-1 ,0 ,1 ,1 ,1 ,0 ,-1};
                    int arrj[8] = {0 ,1 , 1 , 1 , 0 , -1 ,-1 , -1};


                    for(int move_nos=0 ; move_nos <=7 ;move_nos++)
                    {
                        if(king_array[move_nos]==1)
                        {
                            int rv=arri[move_nos];
                            int cv=arrj[move_nos];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];

                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='k';


                            //Check if , is Black King Still Under The Check
                            if(black_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='k';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='k';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }
                        }
                    }
                }

            }
        }
    }
    return 1;
}

//Function To Check if White King is CheckMate
int is_White_King_Checkmate(char board[8][8])
{
    for(int i=0; i<=7 ;i++)
    {
        for(int j=0; j<=7 ;j++)
        {
            if((board[i][j]=='P')||(board[i][j]=='R')||(board[i][j]=='N')||(board[i][j]=='B')||(board[i][j]=='Q')||(board[i][j]=='K'))
            {
                if (board[i][j] == 'P')
                {

                    int pawn_arr[4];
                    All_Pawn_Moves(i, j, board, pawn_arr, 1);

                    int row_value[4] = {-1, -2, -1, -1};
                    int column_value[4] = {0, 0, -1, 1};

                    for (int km=0; km<4; km++)
                    {

                        if (pawn_arr[km] == 1)
                        {

                            //char before_move_from='n';
                            char before_move_to=board[i+row_value[km]][j+column_value[km]];

                            //move is done;
                            board[i][j]='0';
                            board[i+row_value[km]][j+column_value[km]]='P';


                            //Check if , is Black King Still Under The Check
                            if(white_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='P';
                                board[i+row_value[km]][j+column_value[km]]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='P';
                                board[i+row_value[km]][j+column_value[km]]=before_move_to;

                                return 0;
                            }
                        }
                    }
                }

                if(board[i][j]=='N')
                {
                    int knight_array[8];
                    All_Knight_Moves(i ,j ,board ,knight_array ,0);

                    int arri[8]={-2 , -1 , +1 , +2 , +2 ,+1 ,-1 , -2};
                    int arrj[8]={+1 , +2 , +2 , +1 , -1 ,-2 ,-2 ,-1 };

                    for(int move_nos=0 ; move_nos <=7 ;move_nos++)
                    {
                        if(knight_array[move_nos]==1)
                        {
                            int rv=arri[move_nos];
                            int cv=arrj[move_nos];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];

                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='N';


                            //Check if , is White King Still Under The Check
                            if(white_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='N';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='N';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }
                        }
                    }
                }

                if(board[i][j]=='K')
                {
                    int king_array[8];
                    All_King_Moves(i ,j ,board ,king_array ,0);

                    int arri[8] = {-1 ,-1 ,0 ,1 ,1 ,1 ,0 ,-1};
                    int arrj[8] = {0 ,1 , 1 , 1 , 0 , -1 ,-1 , -1};


                    for(int move_nos=0 ; move_nos <=7 ;move_nos++)
                    {
                        if(king_array[move_nos]==1)
                        {
                            int rv=arri[move_nos];
                            int cv=arrj[move_nos];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];

                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='K';


                            //Check if , is Black King Still Under The Check
                            if(white_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='K';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='K';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }
                        }
                    }
                }

                if(board[i][j]=='R')
                {

                    // arr[0] => same column no. but row no. increases
                    // arr[1] => same column no. but row no. decreases
                    // arr[2] => same row no. but column no. increases
                    // arr[3] => same row no. but column no. decreses

                    int arri[4] = {1,-1,0,0};
                    int arrj[4] = {0,0,1,-1};

                    int rook_array[4];
                    All_Rook_Moves(i ,j ,board ,rook_array ,0);

                    for(int type=0; type<=3 ;type++)
                    {

                        int count=rook_array[type];

                        while(count)
                        {

                            int rv = count*arri[type];
                            int cv = count*arrj[type];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];


                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='R';


                            //Check if , is White King Still Under The Check
                            if(white_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='R';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='R';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }

                            count--;

                        }
                    }
                }

                if (board[i][j]=='B')
                {

                    // arr[0] => row index decreases but column index increases (Going towards => Top-right corner)
                    // arr[1] => row index decreases but column index decreases (Going towards => Top-left corner)
                    // arr[2] => row index increases but column index decreases (Going towards => bottom-left corner)
                    // arr[3] => row index increases but column index increases (Going towards => bottom-right corner)


                    int arri[4] = {-1, -1, 1, 1};
                    int arrj[4] = {1, -1, -1, 1};


                    int bishop_arr[4];
                    All_Bishop_Moves(i, j, board, bishop_arr, 0);


                    for(int type=0; type<=3 ;type++)
                    {

                        int count=bishop_arr[type];

                        while(count)
                        {

                            int rv = count*arri[type];
                            int cv = count*arrj[type];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];


                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='B';


                            //Check if , is white King Still Under The Check
                            if(white_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='B';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='B';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }

                            count--;

                        }

                    }

                }

                if (board[i][j]=='Q')
                {


                    int arri[8] = {1,-1,0,0,-1, -1, 1, 1};
                    int arrj[8] = {0,0,1,-1,1, -1, -1, 1};


                    int queen_arr[8];
                    All_Queen_Moves(i, j, board, queen_arr, 0);


                    for(int type=0; type<=7 ;type++)
                    {

                        int count=queen_arr[type];

                        while(count)
                        {

                            int rv = count*arri[type];
                            int cv = count*arrj[type];


                            //char before_move_from=board[i][j];
                            char before_move_to=board[i+rv][j+cv];


                            //Move is made (MAKE_MOVE)
                            board[i][j]='0';
                            board[i+rv][j+cv]='Q';


                            //Check if , is Black King Still Under The Check
                            if(white_king_under_check(board))
                            {
                                //UNDO MOVE
                                board[i][j]='Q';
                                board[i+rv][j+cv]=before_move_to;
                            }
                            else
                            {
                                //UNDO MOVE
                                board[i][j]='Q';
                                board[i+rv][j+cv]=before_move_to;

                                return 0;
                            }

                            count--;

                        }

                    }

                }

            }
        }
    }

    return 1;
}
