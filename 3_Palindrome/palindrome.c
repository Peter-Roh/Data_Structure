#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
    int length = 0;
    int flag = 0;
    char* str;
    str = malloc(sizeof(char) * 10);
    scanf("%s", str);

    int stringLength(char* str)
    {
        if(str[i] == '\0')
            return length;
        else
        {
            length++;
            i++;
            stringLength(str);
        }
    }

    void palindrome(char* str)
    {
        int j = 0;
        int l = stringLength(str);
        while(j < (l - j - 1))
        {
            if(str[j] != str[l - j - 1])
            {
                flag = 1;
                break;
            }
            j++;
        }
    }

    palindrome(str);

    if(flag == 0)
        printf("The string is palindrome. \n");
    else
        printf("The string is not palindrome. \n");

    return 0;
}
