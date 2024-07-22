#include <stdio.h>
#include <stdlib.h>

struct SinglyListNode
{
    int data;
    struct SinglyListNode *next;
};

void printLinkedList(struct SinglyListNode *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element%d: %d\n", i+1, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

int main()
{
    struct SinglyListNode *head = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    struct SinglyListNode *second = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    struct SinglyListNode *third = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));
    struct SinglyListNode *fourth = (struct SinglyListNode *)malloc(sizeof(struct SinglyListNode));

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