#include <stdio.h>

int fibLoop(int n)
{
    int fibo[9];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 0; i < n; i++)
    {
        if(i > 1)
        {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        printf("%d : %d\n", i + 1, fibo[i]);
    }
}

int fib(int n)
{
    if(n == 1 || n == 2)
    {
        return n - 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    printf("Loop: \n");
    fibLoop(9);
    printf("-----------\n");
    printf("Recursion: \n");
    for(int i = 0; i < 9; i++)
    {
        printf("%d : %d\n", i + 1, fib(i + 1));
    }

    return 0;
}
