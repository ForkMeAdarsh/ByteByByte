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

struct SinglyLinkedListNode *insertNodeAtTail(struct SinglyLinkedListNode *head, int data)
{
    struct SinglyLinkedListNode *newNode = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct SinglyLinkedListNode *newLast = head;
        while (newLast->next != NULL)
        {
            newLast = newLast->next;
        }
        newNode->data = data;
        newNode->next = newLast->next;
        newLast->next = newNode;
    }
    return head;
}

int main()
{
    struct SinglyLinkedListNode *head = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *second = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *third = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fourth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));

    head->data = 3;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 50;
    third->next = fourth;

    fourth->data = 41;
    fourth->next = NULL;

    printf("\nTraversing the linkedlist before insertion\n");
    printLinkedList(head);
    printf("\n");
    head = insertNodeAtTail(head, 60);
    printf("Traversing the linkedlist after insertion\n");
    printLinkedList(head);
    printf("\n");
    return 0;
}