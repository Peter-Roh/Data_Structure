#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagListNode {
    ElementType data;
    struct tagListNode* next;
} ListNode;

typedef struct {
    int count;
    ListNode* pos;
    ListNode* head;
} List;

List* CreateList();
void AddNode(List* pList, ElementType data);
void RemoveNode(List* pList, ElementType data);
void DestroyList(List* pList);
int ListCount(List* pList);
int IsEmptyList(List* pList);
int TraverseList(List* pList, int fromWhere, ElementType* pDataOut);
