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

    printLinkedList(head);

    return 0;
}