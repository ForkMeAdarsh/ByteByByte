#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListNode
{
    int data;
    struct SinglyLinkedListNode *next;
};

void printLinkedList(struct SinglyLinkedListNode *head)
{
    int i = 0;
    while (head != NULL)
    {
        printf("Element%d: %d\n", i+1, head->data);
        head = head->next;
        i++;
    }
}

struct SinglyLinkedListNode *insertNodeAtPosition(struct SinglyLinkedListNode *llist, int data, int position)
{
    struct SinglyLinkedListNode *newNode = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));

    struct SinglyLinkedListNode *p = llist;
    int i = 0;
    while (i != position-1)
    {
        p = p->next;
        i++;
    }
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    return llist;
}

int main()
{
    struct SinglyLinkedListNode *head = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *second = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *third = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fourth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));

    head->data = 16;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 7;
    third->next = NULL;

    // fourth->data = 41;
    // fourth->next = NULL;

    printf("\nTraversing the linkedlist before insertion\n");
    printLinkedList(head);
    printf("\n");
    head = insertNodeAtPosition(head, 1, 2);
    printf("Traversing the linkedlist after insertion\n");
    printLinkedList(head);
    printf("\n");
    return 0;
}