#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListNode
{
    int data;
    struct SinglyLinkedListNode *next;
};

typedef struct SinglyLinkedListNode SinglyLinkedListNode;

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

void reverse(SinglyLinkedListNode **head_ref) // pointer to pointer is asked in as a parameter because we want to update the head pointer and want it to point to the last node of the linkedlist
{
    if (*head_ref == NULL) // if after traversing we come to the last node of the linkedlist then we will return as it is our base case
    {
        return;
    }

    SinglyLinkedListNode *first = *head_ref; // first pointer variable to point to the node current node
    SinglyLinkedListNode *rest = first->next; // rest pointer variable to point to the next node of the first node

    if (rest == NULL) // if single node then also we will return
    {
        return;
    }

    reverse(&rest); // recursive call
    SinglyLinkedListNode *q = first->next; // q pointer variable for recursive call of the next node i.e. node next to current node
    q->next = first; // this will make next node points to current node i.e. it will reverse the linkedlist
    first->next = NULL; // make current node point to NULL
    *head_ref = rest; // this will make *head_ref set to the last node of the linkedlist
}                    // when any recursive call is made the *head_ref will only be made to point to last node because of the deepest call in our recursion i.e. the fifth call
                    // when there is a recursive call due to our last node our *head_ref will be set on the last node only because in every call there is a recursive in every call itself and in that call we will update our *head_ref to last node and after that our rest will not altered
                   // i mean to say is that in our recursive(&third) and in this there reverse(&fourth) which will set our *head_ref to last node and after the return of this call our rest will not be be according to our current recursive(&third) i.e. our rest will be pointing to fifth node i.e. last node

int main()
{
    SinglyLinkedListNode *head = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
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

    printf("\nPrinting the elements of the linkedlist before reversing it\n");
    printLinkedList(head);
    
    printf("\nPrinting the elements of the linkedlist after reversing it\n");
    reverse(&head); // giving the address of the head node so as to update the head node and make it to point to last node
    printLinkedList(head);
    printf("\n");
    
    return 0;
}