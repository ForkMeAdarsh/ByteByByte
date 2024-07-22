#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Self Referencing Struture
};

// LinkedList Traversal Function Starts 
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// LinkedList Traversal Function Ends

int main()
{
    // Allocate memory for nodes of the LinkedList in Heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking first node with the second node                                                
    head->data = 7;      //(*head).data = 7;
    head->next = second; //(*head).next = second;

    // Linking second node with the third node
    second->data = 11;    //(*second).data = 11;
    second->next = third; //(*second).next = third;

    // Linking third node with the fourth node
    third->data = 66;   //(*third).data = 66;
    third->next = fourth; //(*third).next = NULL;

    // Terminating the fourth node by pointing it to NULL
    fourth->data = 53;
    fourth->next = NULL;

    // Finally traversing the array with the help of LinkedListTraversal Function
    LinkedListTraversal(head);

    return 0;
}