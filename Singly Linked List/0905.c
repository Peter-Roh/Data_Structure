#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct node
    {
        void* dataPtr;
        struct node* link;
    } NODE;

//generic code using void pointer -> with one set of code, it is possible to apply any data type
    NODE* createNode(void* itemPtr)
    {
        NODE* nodePtr = NULL;
        nodePtr = (NODE*)malloc(sizeof(NODE));
        nodePtr -> dataPtr = itemPtr;
        nodePtr -> link = NULL;

        return nodePtr;
    }

    int* newData = NULL;
    int* nodeData = NULL;
    NODE* node = NULL;

    newData = (int*)malloc(sizeof(int));
    *newData = 7;

    node = createNode(newData);
    nodeData = (int*)node -> dataPtr;

    printf("Data from node: %d\n", *nodeData);

    int* nextData = NULL;
    nextData = (int*)malloc(sizeof(int));
    *nextData = 75;

    NODE* node_2 = NULL;
    node_2 = createNode(nextData);

    node -> link = node_2;

    printf("Data from second node: %d\n", *(int*)node->link->dataPtr);

    return 0;
}
