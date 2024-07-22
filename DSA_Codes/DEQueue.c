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

void enqueueB(struct queue *q, int val)
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

void enqueueF(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow!!");
    }
    else if (q->front == -1)
    {
        printf("Element cannot be enqueued at the front!!");
    }
    else
    {
        printf("Enqueue at front opertion successfully performed");
        q->arr[q->front] = val;
    }
}

int dequeueF(struct queue *q)
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

int dequeueB(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!!");
    }
    else if (q->back == -1)
    {
        printf("Cannot dequeue element from the back");
    }
    else
    {
        printf("Dequeue from back operation successfully performend\n");
        int element = q->arr[q->back];
        q->back--;
        return element;
    }
}

void Traversing(struct queue *q)
{
    for (int i = q->front + 1; i < q->back + 1; i++)
    {
        printf("Element %d: %d\n", i, q->arr[i]);
    }
    
}

void newTraversing(struct queue *q)
{
    for (int i = q->front; i < q->back + 1; i++)
    {
        printf("Element %d: %d\n", i, q->arr[i]);
    }
    
}

int main()
{
    q.size = 10;
    q.front = q.back = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueueB(&q, 50);
    enqueueB(&q, 100);
    enqueueB(&q, 25);
    enqueueB(&q, 100);
    enqueueB(&q, 90);
    enqueueB(&q, 65);
    enqueueB(&q, 600);
    printf("The element dequeued is: %d\n", dequeueF(&q));
    printf("The element dequeued is: %d\n", dequeueF(&q));
    printf("The element dequeued is: %d\n", dequeueF(&q));
    printf("The element dequeued is: %d\n", dequeueF(&q));
    printf("\n");
    Traversing(&q);
    printf("\n");
    enqueueF(&q, 43);
    printf("\n\n");
    newTraversing(&q);
    printf("\n");
    printf("The element dequeued is: %d\n\n", dequeueB(&q));
    newTraversing(&q);

    return 0;
}