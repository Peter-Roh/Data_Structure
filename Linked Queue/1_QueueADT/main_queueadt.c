#include "queueadt.h"

int main(void) {
    Queue* Q1 = CreateQueue();
    Enqueue(Q1, 10);
    Enqueue(Q1, 20);
    Enqueue(Q1, 30);

    int c1 = QueueCount(Q1);
    printf("%d\n", c1);

    Dequeue(Q1);
    printf("%d\n", QueueFront(Q1));

    int c2 = QueueCount(Q1);
    printf("%d\n", c2);

    DestroyQueue(Q1);

    return 0;
}
