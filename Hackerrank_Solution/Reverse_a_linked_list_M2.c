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

struct SinglyLinkedListNode *reverse(struct SinglyLinkedListNode *llist)
{
    if (llist->next == NULL)  // base case to end the recursion 
    {                         
        return llist;         // this base case condition to return the address last node
    }
    struct SinglyLinkedListNode *newHead = reverse(llist->next); // pointer to store the address of last node
    struct SinglyLinkedListNode *q = llist->next; // we can just simply do "llist->next->next = llist;" in place of this line and the line below // pointer variable to point/store the address of node present next to llist pointer variable
    q->next = llist; // to link the current node to previous node
    llist->next = NULL; // to set the previous node to NULL
    return newHead; // will return the address of last node
}

int main()
{
    struct SinglyLinkedListNode *head = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *second = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *third = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fourth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    struct SinglyLinkedListNode *fifth = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    printf("\nTraversing the linkedlist before the reversal\n");
    printLinkedList(head);
    printf("\n");
    printf("Traversing the linkedlist after the reversal\n");
    head = reverse(head);
    printLinkedList(head);
    printf("\n");

    return 0;
}