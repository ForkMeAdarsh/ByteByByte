#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListNode 
{
    int data;
    struct SinglyLinkedListNode* next; 
};

void printLinkedList(struct SinglyLinkedListNode *head)
{
    while (head != NULL)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

void reversePrint(struct SinglyLinkedListNode *llist)
{
    if (llist == NULL)
    {
        return; 
    }
    reversePrint(llist->next);
    printf("Element: %d\n", llist->data);
}

int main()
{
    struct SinglyLinkedListNode *head = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *second = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *third = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fourth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fifth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));

    head->data = 16;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    printf("\nTraversing the linkedlist normally\n");
    printLinkedList(head);
    printf("\n");
    printf("Traversing the reverse linkedlist\n");
    reversePrint(head);
    printf("\n");

    return 0;
}

