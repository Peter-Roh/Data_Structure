#include "0919_2.h"
#include <string.h>
//Stack Applications_parsing
int main(void) {
    char* str = malloc(sizeof(char) * 100);
    Stack* pStack = CreateStack(100);

    printf("Enter expression: ");
    scanf("%s", str);

    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(')
            Push(pStack, 1);
        else {
            if(str[i] == ')')
            {
                if(IsEmpty(pStack))
                {
                    printf("Error: Closing parenthesis not matched. \n");
                }
                else
                    Pop(pStack);
            }
        }
    }

    while(!IsEmpty(pStack))
    {
        Pop(pStack);
        printf("Error: Opening parenthesis not matched. \n");
    }

    DestroyStack(pStack);
    pStack = NULL;
    free(str);

    return 0;
}
