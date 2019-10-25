#include "1024.h"

NODE* CreateTree(NODE* left, const char* dataPtr, NODE* right) {
    NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
    if(pNewNode == NULL)
        return NULL;

    strcpy(pNewNode -> dataPtr, dataPtr);

    pNewNode ->left = left;
    pNewNode ->right = right;

    return pNewNode;
}

void DestroyTree(NODE* node) {
    if(node == NULL)
        return;

    if(node -> left)
        DestroyTree(node -> left);

    if(node -> right)
        DestroyTree(node -> right);

    free(node);
}

char* treeData(NODE* node) {
    return node -> dataPtr;
}

bool hasChild(NODE* node) {
    if(node -> left == NULL && node -> right == NULL) {
        return false;
    }
    else
        return true;
}

double evaluate(NODE* node) {
    char temp[2];

    double Left;
    double Right;
    double Result;

    if(node == NULL)
        return 0;

    switch(node -> dataPtr[0]) {
        case '+': case '-': case '*': case '/':
        Left = evaluate(node -> left);
        Right = evaluate(node -> right);

        if(node -> dataPtr[0] == '+') Result = Left + Right;
        else if(node -> dataPtr[0] == '-') Result = Left - Right;
        else if(node -> dataPtr[0] == '*') Result = Left * Right;
        else if(node -> dataPtr[0] == '/') Result = Left / Right;

        break;

        default: 
        memset(temp, 0, sizeof(temp));
        temp[0] = node -> dataPtr[0];
        Result = atof(temp);
        break;
    }

    return Result;
}
