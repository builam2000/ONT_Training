#include <stdio.h>
#include <stdlib.h>

/*Queue implementation using array. Time complexity : O() */
typedef struct Queue Queue;
struct Queue
{
    int front,rear,size;
    unsigned int capacity;
    int *array;
};


/*Create a queue*/
Queue* createQueue(unsigned int capacity);

/*Check queue is full or not*/
int isFull(Queue *queue);

/*Check a queue is Empty or not*/
int isEmpty(Queue *queue);

/*Put an element into Queue*/
void Enqueue(Queue *queue, int value);

/*Delete an element from Queue*/
int Dequeue(Queue *queue);

/*Get front value of Queue*/
int front(Queue *queue);

/*Get latest value come into Queue*/
int rear(Queue *queue);
