#ifndef HISTORY_STACK_H_INCLUDED
#define HISTORY_STACK_H_INCLUDED

typedef struct node{

    char from_column;
    char from_row;
    char to_column;
    char to_row;

    char from_piece;
    char to_piece;

    int enpassant;

}node;


typedef struct stack{
    int size;
    int top;
    node* arr;
}stack;


void init(stack* s);
void push(stack* s ,node n);
node pop(stack* s);
int isFull(stack s);
int isEmpty(stack s);
node peek(stack s);
void print_stack(stack s);


#endif // HISTORY_STACK_H_INCLUDED
