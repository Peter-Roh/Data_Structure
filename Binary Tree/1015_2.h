#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType[10];

typedef struct tTreeNode {
    ElementType data;
    struct tTreeNode* left;
    struct tTreeNode* right;
} TreeNode;

TreeNode* CreateTree(TreeNode* left, ElementType item, TreeNode* right);
void Preorder(TreeNode* root);
void Inorder(TreeNode* root);
void Postorder(TreeNode* root);
void DestroyTree(TreeNode* root);
TreeNode* CopyTree(TreeNode* root);

/*
TreeNode* LeftTree(TreeNode* tree);
ElementType TreeData(TreeNode* tree);
TreeNode* RightTree(TreeNode* tree);
int IsEmpty(TreeNode* tree);
*/
