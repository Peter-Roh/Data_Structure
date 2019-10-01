#include "stackadt.h"

int main(void) {
    Stack* stack_1 = CreateStack(5);
    Stack* stack_2 = CreateStack(5);

    for(int i = 0; i < 3; i++) {
        Push(stack_1, i + 1);
    }

    for(int i = 4; i < 6; i++) {
        Push(stack_2, i);
    }

    printf("Top of stack_1: %d\n", StackTop(stack_1) -> data);
    printf("Top of stack_2: %d\n", StackTop(stack_2) -> data);

    CatStack(stack_1, stack_2);

    printf("Top of stack_1: %d\n", StackTop(stack_1) -> data);

    Pop(stack_1);

    printf("Top of stack_1: %d\n", StackTop(stack_1) -> data);

    return 0;
}
