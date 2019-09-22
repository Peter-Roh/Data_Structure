#include "0919_2.h"

Stack* CreateStack(int size) {
    //size is not used in linked list implementation
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if(pStack == NULL)
        return NULL;

    pStack -> count = 0;
    pStack -> top = NULL;

    return pStack;
}

void Push(Stack* pStack, Element item) {
    StackNode* pNewNode = (StackNode*)malloc(sizeof(StackNode));
    if(pNewNode == NULL)
        return;

    pNewNode -> data = item;
    pNewNode -> next = pStack -> top;
    pStack -> top = pNewNode;
    pStack -> count++;
}

Element Pop(Stack* pStack) {
    if(pStack -> top == NULL)
        return 0;
    else {
        Element item = pStack -> top -> data;
        StackNode* pOldTop = pStack -> top;
        pStack -> top = pOldTop -> next;
        free(pOldTop);
        pStack -> count--;
        return item;
    }
}

void DestroyStack(Stack* pStack) {
    while(pStack -> count-- >0)
    {
        StackNode* pOldTop = pStack -> top;
        pStack -> top = pOldTop -> next;
        free(pOldTop);
    }

    free(pStack);
}
