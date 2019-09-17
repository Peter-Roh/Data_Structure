#include <stdio.h>
//towers of Hanoi

void towers(int numDisks, char source, char dest, char auxiliary) {
    if(numDisks == 1)
        printf("Move from %c to %c\n", source, dest);
    else {
        towers(numDisks - 1, source, auxiliary, dest);
        printf("Move from %c to %c\n", source, dest);
        towers(numDisks - 1, auxiliary, dest, source);
    }
}

int main(void)
{
    int n = 4; //number of disks
    char a = 'A';
    char b = 'B';
    char c = 'C';

    towers(n, a, c, b);

    return 0;
}
