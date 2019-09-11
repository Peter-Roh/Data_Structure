#include <stdio.h>

//using recursion
//print sequence of input in reverse order
//without using array

void* print_reverse(int length, int i)
{
    int data;
    scanf("%d", &data);
    if(i != (length - 1))
    {
        print_reverse(length, ++i);
        printf("%d ", data);
    }
    else
        printf("%d ", data);
}

int main(void)
{
    int n; //size of data
    scanf("%d", &n);
    int i = 0;

    print_reverse(n, i);
    printf("\n");

    return 0;
}

// read a number
// recursive call
// print
