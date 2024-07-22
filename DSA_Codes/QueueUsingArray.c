#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int back;
    int *arr;
} q;

int isFull(struct queue *q)
{
    if (q->back == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->front == q->back)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        q->back++;
        q->arr[q->back] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        q->front++;
        int element = q->arr[q->front];
        return element;
    }
}

void Traversing(struct queue *q)
{
    for (int i = 0; i < q->back + 1; i++)
    {
        printf("Element %d: %d\n", i, q->arr[i]);
    }
}

int main()
{
    q.size = 10;
    q.front = q.back = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("\t\t***Checking isFull and isEmpty condition before enqueueing elements in the queue***\n");
    printf("Empty--Yes or No:%d\n", isEmpty(&q));
    printf("Full--Yes or No:%d\n", isFull(&q));
    printf("\n");

    // Enqueuing the element in the Queue
    enqueue(&q, 20);
    enqueue(&q, 50);

    printf("\t\t***Checking isFull and isEmpty condition after enqueueing elements in the queue***\n");
    printf("Empty--Yes or No:%d\n", isEmpty(&q));
    printf("Full--Yes or No:%d\n", isFull(&q));
    printf("\n");

    printf("Printing the elemnts in the Queue below--\n");
    Traversing(&q);
    printf("\n");

    // Dequeuing the element from the Queue
    printf("The dequeued element from the queue is %d\n", dequeue(&q));
    Traversing(&q);            //This command will not give the desired results
    // printf("The dequeued element from the queue is %d\n", dequeue(&q));


    return 0;
}




































