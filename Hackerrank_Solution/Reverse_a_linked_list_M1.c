#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListNode
{
    int data;
    struct SinglyLinkedListNode *next;
}; // or *head, *second, *third, *fourth, *fifth; // we can set our pointers here itself instead of setting it in the main function and it will act as global pointer variable here

// we can use "typedef struct SinglyLinkedListNode SinglyLinkedListNode;" to shorten the name of our data type from struct SinglyLinkedlistNode to just SinglyLinkedListNode
typedef struct SinglyLinkedListNode SinglyLinkedListNode;

SinglyLinkedListNode *head; // here we have made our head pointer global pointer variable just because we want to have its access in reverse function call

void printLinkedList(SinglyLinkedListNode *head)
{
    int i = 0;
    while (head != NULL)
    {
        printf("Element%d: %d\n", i+1, head->data);
        head = head->next;
        i++;
    }
}

void reverse(SinglyLinkedListNode *llist) // function to update head pointer and set it to store the address of last node or make head pointer point to last node
{
    if (llist->next == NULL) // base condition to exit the recursion
    {
        head = llist; // we have used our global variable reference to head pointer and made it assign to last node
        return;
    }
    reverse(llist->next); // calling the function again and again using recursion where we give address of next node as parameter
    SinglyLinkedListNode *q = llist->next; // q pointer variable to store the address of present node
    q->next = llist; // command to store the address of previous node and link a chain
    llist->next = NULL; // command to set the previous node to NULL
}

int main()
{
    head = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode)); // since we have already declared head pointer as global variable above we wil not specify its data type here like for the other ones below
    SinglyLinkedListNode *second = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode *third = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode *fourth = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode *fifth = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));

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
    reverse(head);
    printLinkedList(head);
    printf("\n");

    return 0;
}