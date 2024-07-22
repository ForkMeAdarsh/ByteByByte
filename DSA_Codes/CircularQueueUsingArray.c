#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circularQueue
{
    int size;
    int front;
    int back;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if ((q->back + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct circularQueue *q)
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

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow!!\n%d cannot be enqueued", val);
    }
    else
    {
        q->back = (q->back + 1) % q->size;
        q->arr[q->back] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!!\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        int val = q->arr[q->front];
        return val;
    }
}

void Traversing(struct circularQueue *q)
{
    for (int i = 0; i < q->back + 1; i++)
    {
        printf("Element %d: %d\n", i, q->arr[i]);
    }
}

int main()
{
    struct circularQueue q;
    q.size = 10;
    q.front = q.back = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("\t\t***Checking isFull and isEmpty condition before enqueueing elements in the queue***\n");
    printf("Full--Yes or No:%d\n", isFull(&q));
    printf("Empty--Yes or No:%d\n", isEmpty(&q));
    printf("\n");

    q.arr[0] = 100;

    enqueue(&q, 32);
    enqueue(&q, 35);
    enqueue(&q, 37);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 51);
    enqueue(&q, 56);
    enqueue(&q, 68);
    enqueue(&q, 70);
    enqueue(&q, 500);
    printf("\n");

    Traversing(&q);
    printf("\n");

    printf("Full--Yes or No:%d\n", isFull(&q));
    printf("Empty--Yes or No:%d\n", isEmpty(&q));

    printf("\n");
    printf("%d\n", q.arr[0]);
    printf("%d\n", dequeue(&q));
    printf("\n");

    printf("Full--Yes or No:%d\n", isFull(&q));
    
    return 0;
}