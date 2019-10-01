#include "1001_2.h"

Queue* CreateQueue() {
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    if(pQueue == NULL)
        return NULL;

    pQueue -> count = 0;
    pQueue -> front = pQueue -> rear = NULL;

    return pQueue;
}

void Enqueue(Queue* pQueue, ElementType item) {
    QueueNode* pNode = (QueueNode*)malloc(sizeof(QueueNode));
    if(pNode == NULL)
        return;
    pNode -> data = item;
    pNode -> next = NULL;

    if(pQueue -> count <= 0)
        pQueue -> front = pQueue -> rear = pNode;
    else {
        pQueue -> rear -> next = pNode;
        pQueue -> rear = pNode;
    }

    pQueue -> count++;
}

ElementType Dequeue(Queue* pQueue) {
    QueueNode* pFront = NULL;
    ElementType item;

    if(pQueue -> count <= 0)
        return 0;

    pFront = pQueue -> front;
    item = pFront -> data;

    if(pQueue -> count == 1)
        pQueue -> front = pQueue -> rear = NULL;
    else
        pQueue -> front = pFront -> next;

    free(pFront);
    pQueue -> count--;

    return item;
}

void DestroyQueue(Queue* pQueue) {
    QueueNode* pCur = NULL;
    QueueNode* pNext = NULL;

    for(pCur = pQueue -> front; pCur != NULL; pCur = pNext) {
        pNext = pCur -> next;
        free(pCur);
    }

    pQueue -> count = 0;
    pQueue -> front = pQueue -> rear = NULL;

    free(pQueue);
}
