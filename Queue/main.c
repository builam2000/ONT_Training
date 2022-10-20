#include "lib/queue.h"

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