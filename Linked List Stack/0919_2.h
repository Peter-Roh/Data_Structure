#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct tagStackNode {
    Element data;
    struct tagStackNode* next;
} StackNode;

typedef struct {
    int count;
    StackNode* top;
} Stack;

Stack* CreateStack(int size);
void Push(Stack* pStack, Element item);
Element Pop(Stack* pStack);
void DestroyStack(Stack* pStack);
