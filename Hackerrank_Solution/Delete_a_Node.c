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

struct SinglyLinkedListNode *deleteNode(struct SinglyLinkedListNode *llist, int position)
{
    struct SinglyLinkedListNode *p = llist;
    struct SinglyLinkedListNode *q = llist->next;

    if (position == 0)
    {
        llist = llist->next;
        free(p);
    }
    else
    {
        int i = 0;
        while (i != position-1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);
    }
    return llist;
}

int main()
{
    struct SinglyLinkedListNode *head = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *second = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *third = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fourth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fifth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *sixth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *seventh = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *eight = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));

    head->data = 20;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 19;
    fourth->next = fifth;

    fifth->data = 7;
    fifth->next = sixth;

    sixth->data = 4;
    sixth->next = seventh;

    seventh->data = 15;
    seventh->next = eight;

    eight->data = 9;
    eight->next = NULL; 

    printf("\nTraversing the linkedlist before insertion\n");
    printLinkedList(head);
    printf("\n");
    head = deleteNode(head, 3);
    printf("Traversing the linkedlist after insertion\n");
    printLinkedList(head);
    printf("\n");
    return 0;
}