#include <stdio.h>
#include <stdlib.h>

/*Program to test basic queue(FIFO) using array implementation */

struct Queue
{
    int front,rear,size;
    unsigned int capacity;
    int *array;
};

typedef struct Queue Queue;

Queue* createQueue(unsigned int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(capacity*sizeof(int));
    return queue;
}

int isFull(Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

void Enqueue(Queue *queue, int value)
{
    if(isFull(queue))return;
    queue->rear = (queue->rear+1)%(queue->capacity);
    queue->array[queue->rear] = value;
    queue->size = queue->size + 1;
}

int Dequeue(Queue *queue)
{
    if(isEmpty(queue))return -1;
    int value = queue->array[queue->front];
    queue->front = (queue->front + 1)%(queue->capacity);
    queue->size = queue->size - 1;
    return value;
}

int front(Queue *queue)
{
    if(isEmpty(queue))return -1;
    return queue->array[queue->front];
}

int rear(Queue *queue)
{
    if(isEmpty(queue))return -1;
    return queue->array[queue->rear];
}

void main()
{
    Queue *queue = createQueue(5);
    Enqueue(queue,1);
    Enqueue(queue,2);
    Enqueue(queue,3);
    printf("Dequeue: %d \n",Dequeue(queue));
    printf("Front: %d\n",front(queue));
    printf("Rear: %d\n",rear(queue));
}