#include <stdio.h>
#include <string.h>

int main(void)
{
    int preToPostFix(char* preFixIn, char* postFix)
    {
        char op[2];
        int p = 0;

        if(strchr("+-*/", preFixIn[0]) == NULL)
        {
            postFix[0] = preFixIn[0];
            postFix[1] = '\0';
            return strlen(postFix);
        }

        op[0] = preFixIn[p++];
        op[1] = '\0';
        p += preToPostFix(preFixIn + p, postFix);
        p += preToPostFix(preFixIn + p, postFix + strlen(postFix));
        strcat(postFix, op);

        return strlen(postFix);
    }

    char* preFix = "-+*ABC/EF";
    char* postFix;

    preToPostFix(preFix, postFix);

    printf("%s\n", postFix);

    return 0;
}
