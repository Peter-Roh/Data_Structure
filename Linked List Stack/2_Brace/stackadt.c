#include "stackadt.h"

Stack* CreateStack(int size) {
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

StackNode* StackTop(Stack* pStack) {
    return pStack -> top;
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

int IsEmpty(Stack* pStack) {
    return (pStack -> count == 0);
}

Stack* CatStack(Stack* prevStack, Stack* nextStack) {
    Stack* tempStack = CreateStack(nextStack -> count);
    while(!IsEmpty(nextStack)) {
        Push(tempStack, Pop(nextStack));
    }

    while(!IsEmpty(tempStack)) {
        Push(prevStack, Pop(tempStack));
    }

    DestroyStack(tempStack);
    tempStack = NULL;
    DestroyStack(nextStack);
    nextStack = NULL;
}
