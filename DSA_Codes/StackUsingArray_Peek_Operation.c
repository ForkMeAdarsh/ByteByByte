#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
} *s;

int Peek(struct stack *ptr, int i)
{
    int arrInd = ptr->top - i + 1;
    if (arrInd < 0)
    {
        printf("Not a valid position in the stack and hence for the peek operation also\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrInd];
    }
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
    printf("\nPeek operation executing.....\n\n");
    for (int j = 1; j < s->size + 1; j++)
    {
        printf("The element at position %d of the stack is %d\n", j, Peek(s, j));
    }
    
    return 0;
}