#include "stackadt.h"
#include <string.h>

int main(void) {
    char* str = malloc(sizeof(char) * 100);
    Stack* pStack = CreateStack(100);
    int flag = 0;
    scanf("%[^\n]", str);

    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(')
            Push(pStack, 1);
        else if(str[i] == '{')
            Push(pStack, 2);
        else if(str[i] == '[')
            Push(pStack, 3);
        else {
            if(str[i] == ')') {
                if(IsEmpty(pStack)) {
                    flag = 1;
                }
                else if(StackTop(pStack) -> data == 1) {
                    Pop(pStack);
                }
            }
            else if(str[i] == '}') {
                if(IsEmpty(pStack)) {
                    flag = 1;
                }
                else if(StackTop(pStack) -> data == 2) {
                    Pop(pStack);
                }
            }
            else if(str[i] == ']') {
                if(IsEmpty(pStack)) {
                    flag = 1;
                }
                else if(StackTop(pStack) -> data == 3) {
                    Pop(pStack);
                }
            }
        }
    }

    if(!IsEmpty(pStack)) {
        flag = 1;
    }

    if(flag == 0)
        printf("yes\n");
    else
        printf("no\n");

    DestroyStack(pStack);
    pStack = NULL;
    free(str);

    return 0;
}
