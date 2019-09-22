#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct {
    Element* stack; //array to store elements
    int size; //max size
    int top; //stack top
} Stack;

Stack* CreateStack(int size);
void Push(Stack* pStack, Element item);
Element Pop(Stack* pStack);
Element Top(Stack* pStack);
void DestroyStack(Stack* pStack);
/*bool IsFullStack(stack);
bool IsEmptyStack(stack);
int CountStackItem(stack);
void ClearStack(stack);*/
