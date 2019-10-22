#include "1015_2.h"

int main(void) {
    TreeNode *a = CreateTree(NULL, "a", NULL);
    TreeNode *b = CreateTree(NULL, "b", NULL);
    TreeNode *c = CreateTree(NULL, "c", NULL);
    TreeNode *d = CreateTree(NULL, "d", NULL);
    TreeNode *plus1 = CreateTree(b, "+", c);
    TreeNode *multiply = CreateTree(a, "*", plus1);
    TreeNode *root = CreateTree(multiply, "+", d);

    printf("%s\n", root -> left -> right -> right -> data);

    Preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");

    DestroyTree(root);

    return 0;
}
