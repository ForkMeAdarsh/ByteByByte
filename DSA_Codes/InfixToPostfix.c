#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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

void Push(struct stack *ptr, char value)
{
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

char Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char val)
{
    if (val == '+' || val == '-' || val == '*' || val == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Precedence(char val)
{
    if (val == '+' || val == '-')
    {
        return 1;
    }
    else if (val == '*' || val == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *InToPo(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc(strlen(infix + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(StackTop(sp)))
            {
                Push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = Pop(sp);           //Here is the main problem
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = Pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "m-n*p+q";
    char *postfix = InToPo(infix);
    printf("Postfix Expression is: %s", postfix);
    
    return 0;
}