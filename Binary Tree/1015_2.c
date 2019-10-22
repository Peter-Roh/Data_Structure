#include "1015_2.h"

TreeNode* CreateTree(TreeNode* left, ElementType item, TreeNode* right) {
    TreeNode* pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(pNewNode == NULL)
        return NULL;

    strcpy(pNewNode->data, item);

    pNewNode ->left = left;
    pNewNode ->right = right;

    return pNewNode;
}

void Preorder(TreeNode* root) {
    if(root == NULL)
        return;

    printf("%s ", root -> data);
    Preorder(root -> left);
    Preorder(root -> right);
}

void Inorder(TreeNode* root) {
    if(root == NULL)
        return;

    Inorder(root -> left);
    printf("%s ", root -> data);
    Inorder(root -> right);
}

void Postorder(TreeNode* root) {
    if(root == NULL)
        return;

    Postorder(root -> left);
    Postorder(root -> right);
    printf("%s ", root -> data);
}

TreeNode* CopyTree(TreeNode* root) {
    if(root == NULL)
        return NULL;

    return CreateTree(CopyTree(root -> left), root -> data, CopyTree(root -> right));
}

void DestroyTree(TreeNode* root) {
    if(root == NULL)
        return;

    if(root -> left)
        DestroyTree(root -> left);

    if(root -> right)
        DestroyTree(root -> right);

    free(root);
}
