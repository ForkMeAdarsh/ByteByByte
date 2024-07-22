#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void StackLinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
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
        return top;
    }
}

int Pop(struct Node **top)                                  //struct Node *Pop(struct Node *top)
{                                                           //{
    if (isEmpty(*top))                                      //   if (isEmpty(*top))
    {                                                       //   {
        printf("\nStack Underflow!\n");                     //      printf("\nStack Underflow!\n");
    }                                                       //   }
    else                                                    //   else
    {                                                       //   {
        struct Node *n = *top;                              //     struct Node *n = top;
        *top = (*top)->next;                                //     top = top->next;     
        int popped_element = n->data;                       //     int popped_element = n->data;
        free(n);                                            //     free(n);
        return popped_element;                              //     printf("Popped Element is %d\n", popped_element);
    }                                                       //     return top;
}                                                           //   }
                                                            //}
int main()
{
    struct Node *top = NULL;   //Since 'top' is not a Global Variable so any chances made in Pop Operation will not affect top variable
    printf("\nPush operation successfully executed......Below are the results\n\n");
    top = Push(top, 32);
    top = Push(top, 64);
    top = Push(top, 50);
    top = Push(top, 100);
    StackLinkedListTraversal(top);
    printf("\nPop operation successfully executed......Below are the results\n\n");
    int popped_element = Pop(&top);
    StackLinkedListTraversal(top);
    printf("Popped element using Pop operation is %d", popped_element);

    return 0;
}