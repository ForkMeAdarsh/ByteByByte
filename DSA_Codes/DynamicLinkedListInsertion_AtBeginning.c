#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int newdata)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newdata;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int numElements, data;
    struct Node *head = NULL;

    printf("Enter number of elements you want the LinkedList: ");
    scanf("%d", &numElements);

    printf("Enter %d elements\n", numElements);
    for (int i = 0; i < numElements; i++)
    {
        printf("Enter elemets %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printList(head);

    // Deallocate memory used by the LinkedList
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) 
    {
        next = current->next; // Store the next node
        free(current); // Deallocate memory for the current node
        current = next; // Move to the next node
    }
    
    return 0;
}
