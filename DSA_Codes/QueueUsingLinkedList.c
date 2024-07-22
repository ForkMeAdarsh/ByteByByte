#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *back = NULL;

int isFull(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Node *ptr)
{
    if (front == NULL)
    {
        return 1;        
    }
    else
    {
        return 0;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isFull(n))
    {
        printf("Queue Overflow!");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (front == NULL)
        {
            front = back = n;
        }
        else
        {
            back->next = n;
            back = n;            
        }
    }
}

int dequeue()
{
    struct Node *n = front;
    if (isEmpty(front))
    {
        printf("Queue Underflow!");
    }
    else
    {
        front = front->next;
        int element = n->data;
        free(n);
        return element;
    }
}

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    enqueue(50);
    enqueue(60);
    enqueue(70);

    LinkedListTraversal(front);
    printf("\n");

    printf("First element dequeued is: %d\n", dequeue());
    printf("\n");

    LinkedListTraversal(front);
    printf("\n");

    return 0;
}
