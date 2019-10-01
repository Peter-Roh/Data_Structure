#include "1001_1.h"

Queue* CreateQueue(int size) {
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    if(pQueue == NULL)
        return NULL;

    pQueue -> queue = (ElementType*)malloc(sizeof(ElementType) * size);
    if(pQueue -> queue == NULL) {
        free(pQueue);
        return NULL;
    }

    pQueue -> size = size;
    pQueue -> front = pQueue -> rear = 0;

    return pQueue;
}

void Enqueue(Queue* q, ElementType item) {
    if(IsFullQueue(q))
        printf("Error: Queue is full. \n");
    else {
        q -> rear = (q -> rear + 1) % q -> size;
        q -> queue[q -> rear] = item;
    }
}

ElementType Dequeue(Queue* q) {
    if(IsEmptyQueue(q))
        printf("Error: Queue is empty. \n");
    else {
        q -> front = (q -> front + 1) % q -> size;
        return q -> queue[q -> front];
    }
}

int IsFullQueue(Queue* q) {
    if((q -> rear + 1) % q -> size == q -> front)
        return 1;
    else
        return 0;
}

int IsEmptyQueue(Queue* q) {
    if(q -> front == q -> rear)
        return 1;
    else
        return 0;
}
