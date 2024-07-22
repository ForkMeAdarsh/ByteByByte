#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
} *s;

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    s = (struct stack *)malloc(sizeof(struct stack));       
    s->size = 5;                                             
    s->top = -1;                                                                         
    s->arr = (int *)malloc(s->size * sizeof(int));           

    // Pushing elements manually
    s->arr[0] = 100;
    s->top += 1;
    s->arr[1] = 200;
    s->top += 1;
    s->arr[2] = 50;
    s->top += 1;
    s->arr[3] = 23;
    s->top += 1;
    s->arr[4] = 90;
    s->top += 1;

    // Checking wheather the stack is empty or not
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    // Check wheather the stack is full or not
    if (isFull(s))
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("The stack is not full\n");
    }
    
    return 0;
}