#include "0919_2.h"
//Stack Applications_reversing data
int main(void) {
    Stack* pStack = CreateStack(1000);

    while(1) {
        int element =0;
        int retVal = 0;
        printf("Enter a number : <EOF> to stop : ");
        retVal = scanf("%d", &element); //scanf returns total number of inputs scanned successfully
        if(retVal != 1)
            break;
        Push(pStack, element);
    }

    printf("\n");
    printf("The List of numbers reversed : \n");

    while(!IsEmpty(pStack))
        printf("%-3d\n", Pop(pStack));

    DestroyStack(pStack);
    pStack = NULL;

    return 0;
}
