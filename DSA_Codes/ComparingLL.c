#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int LengthOfLL(struct Node *ptr)
{
    int length = 0;
    while (ptr != NULL)
    {
        length = length + 1;
        ptr = ptr->next;
    }
    return length;
}

int main()
{
    struct Node *head1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth2 = (struct Node *)malloc(sizeof(struct Node));

    head1->data = 1;
    head1->next = second1;

    second1->data = 2;
    second1->next = third1;

    third1->data = 3;
    third1->next = NULL;
    printf("First LinkedList:-\n");
    LinkedListTraversal(head1);
    printf("\n");

    head2->data = 10;
    head2->next = second2;

    second2->data = 8;
    second2->next = third2;

    third2->data = 5;
    third2->next = NULL;

    // fourth2->data = 4;
    // fourth2->next = NULL;
    printf("Second LinkedList:-\n"); 
    LinkedListTraversal(head2);
    printf("\n");

    // printf("Comparing both the LinkedList and below are the results\n");

    // while (head1 != NULL || head2 != NULL)
    // {
    //     if (head1->data == head2->data)
    //     {
    //         printf("1\n");
    //     }
    //     else
    //     {
    //         printf("0\n");
    //     }
    //     head1 = head1->next;
    //     head2 = head2->next;        
    // }

    printf("Length of First LinkedList is: %d\n", LengthOfLL(head1));
    printf("Length of Second LinkedList is: %d\n", LengthOfLL(head2));

    int tracker;
    if (LengthOfLL(head1) == LengthOfLL(head2))
    {
        for (int i = 0; head1 != NULL || head2 != NULL; i++)
        {
            tracker = (head1 == head2);
        }
    }
    else
    {
        printf("We will not continue\n");
    }
    
    

    return 0;
}