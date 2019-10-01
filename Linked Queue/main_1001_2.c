#include "1001_2.h"

int main(void) {
    Queue* Queue = CreateQueue();

    Enqueue(Queue, 1);
    Enqueue(Queue, 3);
    Enqueue(Queue, 5);
    Enqueue(Queue, 7);
    Enqueue(Queue, 9);
    Enqueue(Queue, 11);

    for(int i = Queue -> count; i > 1; i--) {
        printf("Dequeue: %d, ", Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue -> front -> data, Queue -> rear -> data);
    }

        printf("Dequeue: %d\n", Dequeue(Queue));

    DestroyQueue(Queue);

    return 0;
}
