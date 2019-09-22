#include "0919_1.h"

int main()
{
    int i = 0;
    int item = 0;

    Stack* pStack = CreateStack(100);

    printf("Input 10 numbers : ");

    for(i = 0 ; i < 10; i++) {
        item = 0;
        scanf("%d", &item);
        Push(pStack, item);
    }

    printf("Reversed : ");

    while(pStack -> top >= 0) {
        item = Pop(pStack);
        printf("%d ", item);
    }
    printf("\n");

    DestroyStack(pStack);
    pStack = NULL;

    return 0;
}
