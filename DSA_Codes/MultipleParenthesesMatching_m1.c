#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
} *s;

int StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

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
    char exp[] = {'{','7','-','(','3','-','2',')','+','[','8','+','(','9','-','1',')',']','}','\0'};           
    s = (struct stack *)malloc(sizeof(struct stack));
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
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            Push(s, exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (exp[i] == '}' && StackTop(s) == '{')
            {
                Pop(s);
            }
            if (exp[i] == ')' && StackTop(s) == '(')
            {
                Pop(s);
            }
            if (exp[i] == ']' && StackTop(s) == '[')
            {
                Pop(s);
            }
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