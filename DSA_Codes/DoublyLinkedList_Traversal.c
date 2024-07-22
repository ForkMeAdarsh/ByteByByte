#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void DoublyLinkedListTraversal_Frwrd(struct Node *ptr)
{
    printf("\nPrinting in forward direction.....\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void DoublyLinkedListTraversal_Bkwrd(struct Node *ptr)
{
    printf("\nPrinting in backward direction.....\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 11;
    second->prev = head;
    second->next = third;

    third->data = 66;
    third->prev = second;
    third->next = fourth;

    fourth->data = 200;
    fourth->prev = third;
    fourth->next = NULL;

    DoublyLinkedListTraversal_Frwrd(head);
    DoublyLinkedListTraversal_Bkwrd(fourth);

    return 0;
}