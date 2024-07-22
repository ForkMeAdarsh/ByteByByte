#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int Peek(struct Node *top, int pos)
{
    struct Node *ptr = top;
    for (int i = 1; i < pos && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int StackTop(struct Node *top)
{
    return top->data;
}

int StackBottom(struct Node *top)
{
    struct Node *n = top;
    while (n->next != NULL)
    {
        n = n->next;
    }
    return n->data;
}

int main()
{
    struct Node *top = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    top->data = 7;
    top->next = second;

    second->data = 15;
    second->next = third;

    third->data = 18;
    third->next = fourth;

    fourth->data = 28;
    fourth->next = NULL;

    printf("The element which is at the demanded position of the Stack using Peek operation is %d\n", Peek(top, 4));
    printf("The element at the top of the Stack is %d\n", StackTop(top));
    printf("The element at the bottom of the Stack is %d\n", StackBottom(top));

    return 0;
}