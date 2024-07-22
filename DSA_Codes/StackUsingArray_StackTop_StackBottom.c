#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
} *s;

int StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int StackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 100;
    s->top++;
    s->arr[1] = 200;
    s->top++;
    s->arr[2] = 50;
    s->top++;
    s->arr[3] = 23;
    s->top++;
    s->arr[4] = 90;
    s->top++;
    printf("\nTop element of the Stack is %d\n", StackTop(s));
    printf("\nBottom element of the Stack is %d\n", StackBottom(s));
    printf("\n");
    
    return 0;
}