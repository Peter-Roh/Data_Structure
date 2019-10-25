#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define STR_MAX 16

typedef struct node {
    char dataPtr[STR_MAX];
    struct node* left;
    struct node* right;
} NODE;

NODE* CreateTree(NODE* left, const char* dataPtr, NODE* right);
void DestroyTree(NODE* node);
char* treeData(NODE* node);
bool hasChild(NODE* node);
double evaluate(NODE* node);
