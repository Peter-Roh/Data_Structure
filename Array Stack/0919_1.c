#include "0919_1.h"

Stack* CreateStack(int size) {
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if(pStack == NULL)
        return NULL;

    pStack -> stack = (Element*)malloc(size * sizeof(Element));
    if(pStack -> stack == NULL) {
        free(pStack);
        return NULL;
    }

    pStack -> size = size;
    pStack -> top = -1;

    return pStack;
}

void Push(Stack* pStack, Element item) {
    if(pStack -> top == pStack -> size - 1)
        return;

    pStack -> stack[++pStack->top] = item;
}

Element Pop(Stack* pStack) {
    if(pStack -> top < 0)
        return 0;

    return pStack -> stack[pStack -> top--];
}

Element Top(Stack* pStack) {
    if(pStack -> top < 0)
        return 0;

    return pStack -> stack[pStack -> top];
}

void DestroyStack(Stack* pStack) {
    if(pStack -> size > 0)
        free(pStack -> stack);

    free(pStack);
}
