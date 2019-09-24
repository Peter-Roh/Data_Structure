#include "0919_2.h"
//Stack Applications_converting decimal to binary
int main(void) {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    Stack* pStack = CreateStack(100);

    while(1) {
        int r = num % 2;
        Push(pStack, r);
        num /= 2;
        if(num == 1) {
            Push(pStack, num);
            break;
        }
    }

    printf("The binary number is : ");
    while(!IsEmpty(pStack)) {
        printf("%d", Pop(pStack));
    }
    printf("\n");

    DestroyStack(pStack);
    pStack = NULL;

    return 0;
}
