#include "1001_1.h"

int main(void) {
    Queue* Queue = CreateQueue(6);

    Enqueue(Queue, 1);
    Enqueue(Queue, 3);
    Enqueue(Queue, 5);
    Enqueue(Queue, 7);
    Enqueue(Queue, 9);

    Enqueue(Queue, 11);

    for(int i = 0; i < 5; i++) {
        printf("Dequeue: %d, ", Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue -> front, Queue -> rear);
    }

    Dequeue(Queue);

    free(Queue -> queue);
    Queue -> queue = NULL;
    free(Queue);
    Queue = NULL;

    return 0;
}
