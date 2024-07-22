#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Print(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

struct Node* revLL(struct Node *head)
{
    struct Node *current, *prev, *next;  //1.current -- to store address where you cuurently are || 2.pre -- to store the address of previous node || 3.next -- to store address of the next node
    current = head;
    prev = NULL;  //making the previous node point to NULL in the starting      NULL<--|1 | second|-->|2 | third|.......
    while (current != NULL)  //                                                             |
    {   //                                                                                 head
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;  //making the head node point to last node of the normal LinkedList so as to reverse the LinkedList
    return head;  //returning the head pointer which will traverse the LinkedList in the reverse order
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    
    // head = NULL;   //Test case in which head points to NULL i.e. it is an empty LinkedList

    // head->data = 1;  //Test case in which there is only one node
    // head->next = NULL;

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

    printf("Printing elements of the LinkedList before reversing the LinkedList\n");
    if (head == NULL)
    {
        printf("Nothing in the LinkedList\n\n");
    }
    else
    {
        Print(head);
    }
    
    printf("Printing elements of the LinkedList after reversing the LinkedList\n");
    head = revLL(head);
    if (head == NULL)
    {
        printf("There was nothing to reverse!!!\n\n");
    }
    else
    {
        Print(head);
    }


    return 0;
}