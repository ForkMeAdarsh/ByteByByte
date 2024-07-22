#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *DeleteFirst(struct Node *head)
{
// Deleting the node from the beginning of the LinkedList function starts

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
    
// Deleting the node from the beginning of the LinkedList function stops
}

struct Node *DeleteInBetween(struct Node *head, int index)
{
// Deleting the node in between the LinkedList function starts

    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;

// Deleting the node in between the LinkedList function stops
}

struct Node *DeleteEnd(struct Node *head)
{
// Deleting the node at the last of the LinkedList function starts
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;

// Deleting the node at the last of the LinkedList function stops
}

struct Node *DeleteAtValue(struct Node *head, int value)
{
// Deleting node after a node with a given value(first node with that value) of the LinkedList function starts

    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        return head;
    }
    else
    {
        printf("Element not found so that's why no node is deleted and your LinkedList as supposed to be is shown below\n");
        return head;
    }

// Deleting node after a node with a given value(first node with that value) of the LinkedList function stops
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = fourth;

    fourth->data = 200;
    fourth->next = NULL;

    printf("LinkedList traversal before deletion.........\n");
    LinkedListTraversal(head);
    printf("\n");
    // printf("Deleting node from the beginning of the LinkedList and then traversing.........\n");
    // head = DeleteFirst(head);
    // LinkedListTraversal(head);
    // printf("\n");
    // printf("Deleting node in between of the LinkedList and then traversing.........\n");
    // head = DeleteInBetween(head, 2);   // if DeleteInBetween was a void function then we can do just DeleteInBetween(head, 2) instead of DeleteInBetween(head, 2)
    // LinkedListTraversal(head);                        
    // printf("\n");
    // printf("Deleting node from the last of the LinkedList and then traversing.........\n");
    // head = DeleteEnd(head);
    // LinkedListTraversal(head);
    // printf("\n");
    printf("Deleting node at the given value of the LinkedList and then traversing.........\n");
    head = DeleteAtValue(head, 7);  // Using the DeleteAtValue function we cannot delete the first node of the LinkedList
    LinkedListTraversal(head);
    printf("\n");
        
    return 0;
}