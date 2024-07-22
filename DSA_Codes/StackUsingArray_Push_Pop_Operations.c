#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
} *s;    //Here we have 's' a Global Variable

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

void StackArrayTraversal(struct stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf("Element%d: %d\n", i + 1, ptr->arr[i]);
    }
}

void Push(struct stack *ptr, int value)
{
    printf("\n*****Push operation successfully completed*****\n");
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value; 
    }
}

int Pop(struct stack *ptr)
{
    printf("\n*****Pop operation successfully completed*****\n");
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing an element manually
    s->arr[0] = 100;
    s->top++;
    s->arr[1] = 200;
    s->top++;
    s->arr[2] = 50;
    s->top++;
    s->arr[3] = 23;
    s->top++;
    // s->arr[4] = 90;
    // s->top++;

    // Checking wheather the stack is empty or not
    // if (isEmpty(s))
    // {
    //     printf("The stack is empty\n");
    // }
    // else
    // {
    //     printf("The stack is not empty\n");
    // }

    // Check wheather the stack is full or not
    // if (isFull(s))
    // {
    //     printf("The stack is full\n");
    // }
    // else
    // {
    //     printf("The stack is not full\n");
    // }
    printf("\nStack Traversal before the Push operation execution.....\n");
    StackArrayTraversal(s);
    Push(s, 114);
    printf("\nStack Traversal after the Push operation execution.....\n");
    StackArrayTraversal(s);
    printf("\nStack Traversal before the Pop operation execution.....\n");
    StackArrayTraversal(s);
    int popped_Value = Pop(s);
    printf("\nStack Traversal after the Pop operation execution.....\n");
    StackArrayTraversal(s);
    printf("The value popped from the stack is %d", popped_Value);

    return 0;
}