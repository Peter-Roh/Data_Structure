#include <stdio.h>
//tail recursion
unsigned long long int fiboTailRec(int n, unsigned long long int prevFibo, unsigned long long int prevprevFibo) {
    unsigned long long int currentFibo;
    if(n == 1)
        return prevFibo;

    currentFibo = prevFibo + prevprevFibo;
    prevprevFibo = prevFibo;
    prevFibo = currentFibo;

    return fiboTailRec(n - 1, prevFibo, prevprevFibo);
}

int main(void)
{
    for(int i = 50; i < 60; i++)
    {
        printf("%d : %llu\n", i, fiboTailRec(i, 0, 1));
    }

    return 0;
}
