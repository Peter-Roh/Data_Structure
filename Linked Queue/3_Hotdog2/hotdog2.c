#include "queueadt.h"

int main(void) {
    int n;
    int ans = 0;
    int time = 0;

    printf("number of customer : ");
    scanf("%d", &n);

    Queue* Queue = CreateQueue();

    while(n--) {
        int patience;
        printf("Patience of customer : ");
        scanf("%d", &patience);
        Enqueue(Queue, patience);
    }

    while(Queue -> count > 0) {
        Dequeue(Queue);
        ans++;
        if(Queue -> count == 0)
            break;
        Dequeue(Queue);
        ans++;
        time++;
        if(Queue -> count == 0)
            break;
        while(1) {
            if(Queue -> front -> data < time) {
                Dequeue(Queue);
                break;
            }
            else {
                break;
            }
        }
        while(1) {
            if(Queue -> front -> data < time) {
                Dequeue(Queue);
                break;
            }
            else {
                break;
            }
        }
    }

    printf("I sell %d hotdogs. \n", ans);

    DestroyQueue(Queue);

    return 0;
}
