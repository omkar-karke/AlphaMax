#include"History_stack.h"
#include<stdlib.h>
#include<stdio.h>


void init(stack* s)
{
    s->size=5000;
    s->top=-1;
    s->arr=(node*)malloc(sizeof(node)*(s->size));
}


int isFull(stack s)
{
    if(s.top==s.size-1)
        return 1;

    return 0;
}

int isEmpty(stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}



void push(stack* s ,node n)
{
    if(isFull(*s))
        return;

    s->top++;
    s->arr[s->top]=n;

}


node pop(stack* s)
{
    node temp;
    temp.from_piece='0';

    if(isEmpty(*s))
        return temp;

    temp=s->arr[s->top];
    s->top--;

    return temp;
}


node peek(stack s)
{
    node temp;
    temp.from_piece='0';

    if(isEmpty(s))
        return temp;

    temp=s.arr[s.top];

    return temp;
}





void print_stack(stack s)
{
    int temp=s.top;

    int index=0;

    while(index<=temp)
    {
        node now=s.arr[index];
        printf("From Square  :%c%c : Piece is %c                ",now.from_column , now.from_row ,now.from_piece);
        printf("TO Square  :%c%c : Piece is %c              EnPassant = %d \n",now.to_column , now.to_row ,now.to_piece,now.enpassant);
        index++;
    }
}

