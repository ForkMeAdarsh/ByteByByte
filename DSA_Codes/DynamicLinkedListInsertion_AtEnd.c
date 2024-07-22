#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the LinkedList
struct Node 
{
    int data; // Data stored in the node
    struct Node* next; // Pointer to the next node
};

// Function to insert a new node at the end of the list
void insert(struct Node** head, int newData)       // struct Node *insert(struct Node *head, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = newData; // Set the data for the new node
    newNode->next = NULL; // Make the new node point to NULL since it will be the last node

    if (*head == NULL) // If the list is empty, make the new node the head
    {
        *head = newNode;
    }
    else // If the list is not empty, traverse to the last node and add the new node there
    {
        struct Node *lastNode = *head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    // return head;  // Will return head if the function was of type struct Node*
}

// Function to print all the elements of the LinkedList
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("Element: %d\n", head->data); // Print the data of current node
        head = head->next; // Move to the next node
    }
    printf("\n");
}

int main() 
{
    int numElements, data;
    struct Node* head = NULL; // Initialize an empty LinkedList

    printf("Enter number of elements you want in the LinkedList: ");
    scanf("%d", &numElements);

    // Create the LinkedList with user-defined number of elements
    printf("Enter %d elements\n", numElements);
    for (int i = 0; i < numElements; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);   //Can be like this also head = insert(head, data) if insert function was of struct Node* data type
    }

    // Print the linked list
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
