#include "1010.h"

int main(void) {
    List* list = CreateList();

    AddNode(list, 10);
    AddNode(list, 5);
    AddNode(list, 20);
    AddNode(list, 30);

    printf("count: %d, head: %d\n", ListCount(list), list->head->data);

    RemoveNode(list, 5);

    printf("count: %d, head: %d\n", ListCount(list), list->head->data);

    RemoveNode(list, 20);

    printf("count: %d, head: %d\n", ListCount(list), list->head->data);

    DestroyList(list);

    return 0;
}
