#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *tp = NULL;

void StackLinkedListTraversal(struct Node *top)
{
    while (top != NULL)
    {
        printf("Element: %d\n", top->data);
        top = top->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *Push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("\nStack Overflow!\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        // free(n);
        return top;
    }
}

int Pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("\nStack Underflow!\n");
    }
    else
    {
        struct Node *n = top;
        tp = top->next;
        int popped_element = n->data;
        free(n);
        return popped_element;
    }
}

int main()
{
    printf("\nPush operation successfully executed......Below are the results\n\n");
    tp = Push(tp, 32);
    tp = Push(tp, 64);
    tp = Push(tp, 50);
    tp = Push(tp, 100);
    StackLinkedListTraversal(tp);
    printf("\nPop operation successfully executed......Below are the results\n\n");
    int popped_element = Pop(tp);
    StackLinkedListTraversal(tp);
    printf("Popped element using Pop operation is %d", popped_element);

    return 0;
}