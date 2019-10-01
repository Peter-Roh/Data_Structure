#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct {
    ElementType* queue;
    int size;
    int front, rear;
} Queue;

Queue* CreateQueue(int size);
void Enqueue(Queue* q, ElementType item);
ElementType Dequeue(Queue* q);
int IsFullQueue(Queue* q);
int IsEmptyQueue(Queue* q);
