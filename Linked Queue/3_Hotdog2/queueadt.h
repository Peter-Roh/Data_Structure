#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagQueueNode {
    ElementType data;
    struct tagQueueNode* next;
} QueueNode;

typedef struct {
    int count;
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* CreateQueue();
void Enqueue(Queue* pQueue, ElementType item);
ElementType Dequeue(Queue* pQueue);
void DestroyQueue(Queue* pQueue);
ElementType QueueFront(Queue* pQueue);
int QueueCount(Queue* pQueue);
