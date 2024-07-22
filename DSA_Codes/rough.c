#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to traverse and print the linked list
void Traverse(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

// Recursive function to move the head pointer to the last node and print it
void moveToLastRecursive(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Base case: empty list or single element
    }

    struct Node *current = *head;
    if (current->next->next == NULL) {
        *head = current->next; // Update head to point to the last node
        printf("Head points to the last node: %d\n", (*head)->data); // Print last node's data
        return;
    }

    moveToLastRecursive(&(current->next));
}

int main() {
    // Creating the linked list
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

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

    printf("Original List:\n");
    Traverse(head);

    moveToLastRecursive(&head);

    printf("New Head List (should point to the last node):\n");
    Traverse(head);  // Now head should point to the last node

    return 0;
}
