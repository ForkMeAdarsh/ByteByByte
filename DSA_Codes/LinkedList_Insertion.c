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

void InsertAtFirst(struct Node **head, int data)
{
// Insertion of the new node at the beginning of the LinkedList function starts

    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    newHead->data = data;
    newHead->next = *head;
    *head = newHead;
    // return newHead;
    
// Insertion of the new node at the beginning of the LinkedList function stops
}

void InsertInBetween(struct Node *head, int data, int index)
{
// Insertion of the new node in between the LinkedList function starts

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    // return head;   //If InsertInBetween was of struct Node* data type then we would've returned head pointer

// Insertion of the new node in between the LinkedList function stops
}

void InsertAtEnd(struct Node *head, int data)
{
// Insertion of the new node at the last of the LinkedList function starts

    struct Node *newLast = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newLast;
    newLast->data = data;
    newLast->next = NULL;    
    // return head;   //If InsertAtEnd was of struct Node* data type then we would have returned head pointer    

// Insertion of the new node at the last of the LinkedList function stops
}

void InsertAfterNode(struct Node *head, struct Node *PrevNode, int data)
{
// Insertion of the new node after a node of the LinkedList function starts

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = PrevNode->next;
    PrevNode->next = newNode;
    // return head;  //If InsertAfterNode was of struct Node* data type then we would have returned head pointer

// Insertion of the new node after a node of the LinkedList function stops
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

    printf("LinkedList traversal before insertion.........\n");
    LinkedListTraversal(head);
    printf("\n");
    printf("Inserting new node at the beginning of the LinkedList and then Traversing.........\n");
    // struct Node *newHead = InsertAtFirst(head, 142); 
    InsertAtFirst(&head, 142); 
    LinkedListTraversal(head);
    printf("\n");
    // printf("Inserting new node in between the LinkedList and then Traversing.........\n");
    // InsertInBetween(head, 150, 1); //If InsertInBetween was of struct Node* data type then we can also write head = InsertInBetween(head, 150, 3);
    // LinkedListTraversal(head);
    // printf("\n");
    // printf("Inserting new node at the last of the LinkedList and then Traversing.........\n");
    // InsertAtEnd(head, 125); //If InsetAtEnd was of struct Node* data type then we can also write head = InsertAtEnd(head, 125);
    // LinkedListTraversal(head); 
    // printf("\n");
    // printf("Inserting new node after a node of the LinkedList and then Traversing.........\n");
    // InsertAfterNode(head, second, 1000); //If InsertAfterNode was of struct Node* data type then we can also write head = InsertAfterNode(head, third, 100);
    // LinkedListTraversal(head);
    // printf("\n");

    return 0;
}