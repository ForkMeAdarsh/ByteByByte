#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int size;
    int top;
    char *arr;
} *s;

int isEmpty(struct Node *ptr)
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

int isFull(struct Node *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct Node *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] == val;
    }
}

void Pop(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!!");
        printf("Expression not balanced!!....");
    }
    else
    {
        ptr->top--;
    }
}

int main()
{
    char *exp = "3*(2-(8+1))";
    s = (struct Node *)malloc(sizeof(struct Node));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    printf("Expression: ");
    for (int i = 0; i < strlen(exp) + 1; i++)
    {
        printf("%c ", exp[i]);
    }
    printf("\n");

    for (int i = 0; i < strlen(exp) + 1; i++)
    {
        if (exp[i] == '(')
        {
            Push(s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            Pop(s);
        }
    }
    
    if (isEmpty(s))
    {
        printf("Expression is balanced!!....");
    }
    else
    {
        printf("Expression is not balanced!!....");
    }
    
    return 0;
}