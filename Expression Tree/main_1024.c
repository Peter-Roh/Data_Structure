#include "1024.h"

int main(void) {
    NODE* left, *right, *root;

    left = CreateTree(NULL, "6", NULL);
    right = CreateTree(NULL, "2", NULL);
    root = CreateTree(left, "/", right);

    left = CreateTree(NULL, "3", NULL);
    right = root;
    root = CreateTree(left, "+", right);

    left = CreateTree(NULL, "2", NULL);
    right = root;
    root = CreateTree(left, "*", right);

    left = root;
    right = CreateTree(NULL, "4", NULL);
    root = CreateTree(left, "/", right);

    if(hasChild(root)) {
        printf("Result: %f\n", evaluate(root));
    }

    DestroyTree(root);

    return 0;
}
