#include <stdlib.h>
#include <limits.h>
#include "minimax.h"
#include "All_Possible_Moves.h"
#include "ChecknCheckmate.h"
#include"Evaluation_Function.h"

// BLACK = MAXIMIZER
// WHITE = MINIMIZER

/*
arr1[0] = From_Row
arr1[1] = From Column
arr1[2] = To Row
arr1[3] = To Column
arr1[4] =  Evaluation Value
*/
//Since we want Our Black to return Maximum value , hence we would pass INT_MAX in alpha => For the Function call that we give
//IF we want Our White to return Minimum value , hence we would pass INT_MIN in alpha => For the Function call that we give
int* minimax(char board[8][8], int counter, int depth , int alpha, int beta)
{
    //DEPTH<=0 => INVALID INPUT
    int *arr = (int*)malloc(sizeof(int)*5);

    if (counter %2 == 1)    //Blacks Move (Maximizer)
    {
        arr[4] = INT_MIN;
    }
    else                    //Whites Move (Minimizer)
    {
        arr[4] = INT_MAX;
    }

    depth--;

    if(counter%2==1)        //Blacks Move       Maximizer
    {
        int flag = 0;
        for(int i = 0 ; i<=7 ; i++)
        {
            for(int j = 0 ; j<=7 ; j++ )
            {
                if(depth==0)        //Blacks Move       Maximizer    and depth is zero (=>Evaluate and return Value)
                {
                    if(board[i][j]=='n')
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
                                    //Move is InValid , As King Is Exposed After The Move
                                    //UNDO MOVE
                                    board[i][j]='n';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int board_value = heuristic(board);


                                    if (board_value > arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;
                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }


                                    if (beta <= alpha)
                                    {
                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='n';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;
                                    }
                                    //UNDO MOVE
                                    board[i][j]='n';
                                    board[i+rv][j+cv]=before_move_to;

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
                                    //Move is InValid , As King Is Exposed After The Move
                                    //UNDO MOVE
                                    board[i][j]='k';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int board_value = heuristic(board);


                                    if (board_value > arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='k';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='k';
                                    board[i+rv][j+cv]=before_move_to;

                                }
                            }
                        }
                    }

                    else if(board[i][j]=='r')
                    {

                        // arr[0] => same column no. but row no. increases
                        // arr[1] => same column no. but row no. decreases
                        // arr[2] => same row no. but column no. increases
                        // arr[3] => same row no. but column no. decreses

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
                                    //After Move King is Exposed , Hence its not a valid Move
                                    //UNDO MOVE
                                    board[i][j]='r';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {
                                    int board_value = heuristic(board);


                                    if (board_value > arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='r';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='r';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;
                            }
                            if(flag==1)
                                break;
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
                                    //After Move Our Own King Under Check , Hence Not A Valid Move
                                    //UNDO MOVE
                                    board[i][j]='b';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {
                                    int board_value = heuristic(board);

                                    if (board_value > arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='b';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='b';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;

                            }
                            if(flag==1)
                                break;
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
                                    //If Our King Under Check After Our Move, Hence Not a Valid Move
                                    //UNDO MOVE
                                    board[i][j]='q';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {
                                    int board_value = heuristic(board);

                                    if (board_value > arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='q';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='q';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;

                            }
                            if(flag==1)
                                break;
                        }
                    }

                    else if (board[i][j] == 'p')
                    {

                        int pawn_arr[4];
                        All_Pawn_Moves(i, j, board, pawn_arr, 1);

                        int arri[4] = {1, 2, 1, 1};
                        int arrj[4] = {0, 0, 1, -1};

                        for (int km=0; km<4; km++)
                        {

                            if (pawn_arr[km] == 1)
                            {

                                int rv = arri[km];
                                int cv = arrj[km];

                                //char before_move_from='n';
                                char before_move_to=board[i+rv][j+cv];

                                //move is done;
                                board[i][j]='0';
                                board[i+rv][j+cv]='p';


                                //Check if , is Black King Still Under The Check
                                if(black_king_under_check(board))
                                {
                                    //UNDO MOVE
                                    board[i][j]='p';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int board_value = heuristic(board);

                                    if (board_value > arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='p';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='p';
                                    board[i+rv][j+cv]=before_move_to;

                                }
                            }
                        }
                    }
                }
                else        //Blacks Move   Maximizer and depth is not equal to zero
                { //=>  1)Make Move      2)Go Down Recursively   3)Check Value with Max When Recursive Function Returns   4)Undo The Move
                    if(board[i][j]=='n')
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
                                    //Move is InValid , As King Is Exposed After The Move
                                    //UNDO MOVE
                                    board[i][j]='n';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {
                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4]>arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];

                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='n';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='n';
                                    board[i+rv][j+cv]=before_move_to;

                                }
                            }
                        }
                    }


                    if(board[i][j]=='k')
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
                                    //Move is InValid , As King Is Exposed After The Move
                                    //UNDO MOVE
                                    board[i][j]='k';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {
                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4]>arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];

                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='k';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='k';
                                    board[i+rv][j+cv]=before_move_to;

                                }
                            }
                        }
                    }


                    if(board[i][j]=='r')
                    {

                        // arr[0] => same column no. but row no. increases
                        // arr[1] => same column no. but row no. decreases
                        // arr[2] => same row no. but column no. increases
                        // arr[3] => same row no. but column no. decreses

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
                                    //After Move King is Exposed , Hence its not a valid Move
                                    //UNDO MOVE
                                    board[i][j]='r';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {
                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4]>arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='r';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='r';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;

                            }
                            if(flag==1)
                                break;
                        }
                    }


                    if (board[i][j]=='b')
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
                                    //After Move Our Own King Under Check , Hence Not A Valid Move
                                    //UNDO MOVE
                                    board[i][j]='b';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4]>arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='b';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='b';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;

                            }
                            if(flag==1)
                                break;

                        }

                    }


                    if (board[i][j]=='q')
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
                                    //If Our King Under Check After Our Move, Hence Not a Valid Move
                                    //UNDO MOVE
                                    board[i][j]='q';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4]>arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];


                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='q';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='q';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;

                            }
                            if(flag==1)
                                break;
                        }
                    }

                    else if (board[i][j] == 'p')
                    {
                        int pawn_arr[4];
                        All_Pawn_Moves(i, j, board, pawn_arr, 1);

                        int arri[4] = {1, 2, 1, 1};
                        int arrj[4] = {0, 0, 1, -1};

                        for (int km=0; km<4; km++)
                        {
                            if (pawn_arr[km] == 1)
                            {

                                int rv = arri[km];
                                int cv = arrj[km];

                                //char before_move_from='n';
                                char before_move_to=board[i+rv][j+cv];

                                //move is done;
                                board[i][j]='0';
                                board[i+rv][j+cv]='p';


                                //Check if , is Black King Still Under The Check
                                if(black_king_under_check(board))
                                {
                                    //UNDO MOVE
                                    board[i][j]='p';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int *arr2 = minimax(board, counter + 1, depth ,alpha ,beta);

                                    if (arr2[4] > arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];


                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='p';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='p';
                                    board[i+rv][j+cv]=before_move_to;

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else        //Whites Move       //Minimizer
    {
        int flag=0;
        for(int i = 0 ; i<=7 ; i++ )
        {
            for(int j = 0 ; j<=7 ; j++ )
            {
                if(depth==0)    //Whites Move       Minimizer    and depth is zero (=>Evaluate and return Value)
                {
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
                                    int board_value = heuristic(board);

                                    if (board_value < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='N';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='N';
                                    board[i+rv][j+cv]=before_move_to;


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

                                    int board_value = heuristic(board);

                                    if (board_value < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;



                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='K';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='K';
                                    board[i+rv][j+cv]=before_move_to;

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

                                    int board_value = heuristic(board);



                                    if (board_value < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='R';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='R';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;

                            }
                            if(flag==1)
                                break;
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
                                    int board_value = heuristic(board);



                                    if (board_value < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='B';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='B';
                                    board[i+rv][j+cv]=before_move_to;


                                }

                                count--;

                            }
                            if(flag==1)
                                break;

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
                                    int board_value = heuristic(board);



                                    if (board_value < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='Q';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='Q';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;
                            }
                            if(flag==1)
                                break;
                        }
                    }

                    if (board[i][j] == 'P')
                    {

                        int pawn_arr[4];
                        All_Pawn_Moves(i, j, board, pawn_arr, 0);

                        int arri[4] = {-1, -2, -1, -1};
                        int arrj[4] = {0, 0, -1, 1};

                        for (int km=0; km<4; km++)
                        {
                            if (pawn_arr[km] == 1)
                            {

                                int rv = arri[km];
                                int cv = arrj[km];

                                //char before_move_from='n';
                                char before_move_to=board[i+rv][j+cv];

                                //move is done;
                                board[i][j]='0';
                                board[i+rv][j+cv]='P';


                                //Check if , is Black King Still Under The Check
                                if(white_king_under_check(board))
                                {
                                    //UNDO MOVE
                                    board[i][j]='P';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int board_value = heuristic(board);



                                    if (board_value < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = board_value;


                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='P';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='P';
                                    board[i+rv][j+cv]=before_move_to;

                                }
                            }
                        }
                    }


                }
                else        //Whites Move   Minimizer and depth is not equal to zero
                {   //=>  1)Make Move      2)Go Down Recursively   3)Check Value with Min When Recursive Function Returns   4)Undo The Move
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

                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4] < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];

                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='N';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='N';
                                    board[i+rv][j+cv]=before_move_to;


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
                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4] < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];



                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='K';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='K';
                                    board[i+rv][j+cv]=before_move_to;

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

                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4] < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];



                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='R';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='R';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;

                            }
                            if(flag==1)
                                break;
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
                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4] < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];



                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='B';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='B';
                                    board[i+rv][j+cv]=before_move_to;


                                }

                                count--;

                            }
                            if(flag==1)
                                break;

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

                                    int *arr2=minimax( board , counter + 1 , depth ,alpha ,beta);

                                    if(arr2[4] < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];



                                    }


                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='Q';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }


                                    //UNDO MOVE
                                    board[i][j]='Q';
                                    board[i+rv][j+cv]=before_move_to;

                                }

                                count--;
                            }
                            if(flag==1)
                                break;
                        }
                    }

                    else if (board[i][j] == 'P')
                    {

                        int pawn_arr[4];
                        All_Pawn_Moves(i, j, board, pawn_arr, 0);

                        int arri[4] = {-1, -2, -1, -1};
                        int arrj[4] = {0, 0, -1, 1};

                        for (int km=0; km<4; km++)
                        {

                            if (pawn_arr[km] == 1)
                            {

                                int rv = arri[km];
                                int cv = arrj[km];


                                char before_move_to=board[i+rv][j+cv];

                                //move is done;
                                board[i][j]='0';
                                board[i+rv][j+cv]='P';


                                //Check if , is Black King Still Under The Check
                                if(white_king_under_check(board))
                                {
                                    //UNDO MOVE
                                    board[i][j]='P';
                                    board[i+rv][j+cv]=before_move_to;
                                }
                                else
                                {

                                    int *arr2 = minimax(board, counter + 1, depth ,alpha ,beta);

                                    if (arr2[4] < arr[4])
                                    {
                                        arr[0] = i;
                                        arr[1] = j;
                                        arr[2] = i+rv;
                                        arr[3] = j+cv;
                                        arr[4] = arr2[4];


                                    }

                                    if (arr[4] > alpha)
                                    {
                                        alpha = arr[4];
                                    }



                                    if (beta <= alpha)
                                    {

                                        flag = 1;
                                        //UNDO MOVE
                                        board[i][j]='P';
                                        board[i+rv][j+cv]=before_move_to;
                                        break;

                                    }

                                    //UNDO MOVE
                                    board[i][j]='P';
                                    board[i+rv][j+cv]=before_move_to;

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return arr;
}





