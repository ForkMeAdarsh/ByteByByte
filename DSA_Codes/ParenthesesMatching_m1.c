#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

void Push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        printf("The expression is not balanced");
    }
    else
    {
        ptr->top--;
    }
}

int main()
{
    char str[] = {'3','*','(','2','-','(','8','+','1',')',')','\0'};           //char *exp = "3*(2-(8+1))";
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    printf("Expression: ");
    for (int i = 0; i < strlen(str) + 1; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");
    
    for (int i = 0; i < strlen(str) + 1; i++)
    {
        if (str[i] == '(')
        {
            Push(s, str[i]);
        }
        else if (str[i] == ')')
        {
            Pop(s);
        }
    }

    if (isEmpty(s))
    {
        printf("Expression is balanced!!");
    }
    else
    {
        printf("Expression is not balanced!!");
    }
    
    return 0;
}