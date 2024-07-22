#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; 
};

void print(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void printRev(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printRev(ptr->next);
    printf("%d ", ptr->data);
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;      
    head->next = second; 

    second->data = 11;    
    second->next = third; 

    third->data = 66;   
    third->next = NULL;

    printf("Printing the elements before reversing\n");
    print(head);
    
    printf("Printing the elements after reversing\n");
    printRev(head);
    printf("\n\n");
    printf("Hi!!!!!");

    return 0;
}