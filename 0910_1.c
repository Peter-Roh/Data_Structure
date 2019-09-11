#include <stdio.h>

int main(void)
{
// generic code using function pointer
// able to use any data type
    void* larger(void* dataPtr1, void* dataPtr2, int (*ptrToCmpFun)(void*, void*))
    {
        if((*ptrToCmpFun)(dataPtr1, dataPtr2) > 0)
            return dataPtr1;
        else
            return dataPtr2;
    }

    int int_compare(void* ptr1, void* ptr2)
    {
        if(*(int*)ptr1 >= *(int*)ptr2)
            return 1;
        else
            return -1;
    }

    int i = 7;
    int j = 8;
    int lrg = 0;

    lrg = *(int*)larger(&i, &j, int_compare);

    printf("Larger value is: %d\n", lrg);

    return 0;
}
