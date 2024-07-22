#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void DoublyLinkedListTraversalFrwrd(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void DoublyLinkedListTraversalBkwrd(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

void InserAtFirst(struct Node **head, int data)
{
    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    newHead->data = data;
    newHead->prev = NULL;
    newHead->next = *head;
    (*head)->prev = newHead;
    *head = newHead;
}

void InsertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    q->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
}

void InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->prev = p;
    ptr->next = p->next;
    p->next = ptr;
}

void InsertAfteNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = prevNode;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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

    printf("Traversing the linkedlist before insertion....!!\n");
    DoublyLinkedListTraversalFrwrd(head);
    printf("\n");
    printf("Traversing the linkedlist after insertion....!!\n");
    // DoublyLinkedListTraversalBkwrd(fourth);

    // InserAtFirst(&head, 121);
    // DoublyLinkedListTraversalFrwrd(head);
    // printf("\n");

    // InsertInBetween(head, 129, 2);
    // DoublyLinkedListTraversalFrwrd(head);
    // printf("\n");

    // InsertAtEnd(head, 151);
    // DoublyLinkedListTraversalFrwrd(head);
    // printf("\n");

    InsertAfteNode(head, third, 201);
    DoublyLinkedListTraversalFrwrd(head);
    printf("\n");

    return 0;
}