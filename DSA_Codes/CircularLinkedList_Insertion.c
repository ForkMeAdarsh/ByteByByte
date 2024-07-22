#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;                                   // struct Node *ptr = head;
    do                                                         // printf("Element: %d\n", ptr->data);   ||      while (ptr->next != NULL)
    {                                                          // ptr = ptr->next;                              {
        printf("Element: %d\n", ptr->data);                    // while (ptr != head)                               printf("Element: %d\n", ptr->data);
        ptr = ptr->next;                                       // {                                                 ptr = ptr->next;
    } while (ptr != head);                                     //     printf("Element: %d\n", ptr->data);       }
}                                                              //     ptr = ptr->next;                          printf("Element: %d", ptr->data);                                                             // }

struct Node *InserAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = ptr;
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void InsertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

void InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = ptr;
    ptr->data = data;
    ptr->next = head;
}

void InsertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    fourth->next = head;

    printf("CircularLinkedList Traversal before insertion....\n");
    CircularLinkedListTraversal(head);
    printf("\n");
    printf("CircularLinkedList Taversal after insetion....\n");
    // head = InserAtFirst(head, 140);
    // CircularLinkedListTraversal(head);
    // printf("\n");

    // InsertInBetween(head, 121, 2);
    // CircularLinkedListTraversal(head);
    // printf("\n");

    // InsertAtEnd(head, 25);
    // CircularLinkedListTraversal(head);
    // printf("\n");

    InsertAfterNode(head, fourth, 149);
    CircularLinkedListTraversal(head);
    printf("\n");

    return 0;
}