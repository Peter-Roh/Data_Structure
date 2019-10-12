#include "1010.h"

List* CreateList() {
    List* pNewList = (List*)malloc(sizeof(List));
    if(pNewList == NULL)
        return NULL;

    pNewList -> count = 0;
    pNewList -> head = NULL;

    return pNewList;
}

void _insertList(List* pList, ListNode *pPre, ElementType data) {
    ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
    pNewNode -> data = data;

    if(pPre == NULL) {
        pNewNode -> next = pList -> head;
        pList -> head = pNewNode;
    }
    else {
        pNewNode -> next = pPre -> next;
        pPre -> next = pNewNode;
    }

    pList -> count++;
}

int _searchList(List* pList, ListNode **ppPre, ListNode **ppLoc, ElementType data) {
    for(*ppPre = NULL, *ppLoc = pList -> head; *ppLoc != NULL; *ppPre = *ppLoc, *ppLoc = (*ppLoc) -> next) {
        if((*ppLoc) -> data == data)
            return 1;
        else if((*ppLoc) -> data > data)
            break;
    }

    return 0;
}

void AddNode(List* pList, ElementType data) {
    ListNode* pPre = NULL;
    ListNode* pLoc = NULL;

    if(!_searchList(pList, &pPre, &pLoc, data))
        _insertList(pList, pPre, data);
}

void _deleteNode(List* pList, ListNode* pPre, ListNode* pLoc) {
    if(pPre == NULL)
        pList -> head = pLoc -> next;
    else
        pPre -> next = pLoc -> next;

    free(pLoc);
    pList -> count--;
}

void RemoveNode(List* pList, ElementType data) {
    ListNode* pPre = NULL, *pLoc = NULL;

    if(_searchList(pList, &pPre, &pLoc, data))
        _deleteNode(pList, pPre, pLoc);
}

void DestroyList(List* pList) {
    ListNode* pDel = NULL, *pNext = NULL;

    for(pDel = pList -> head; pDel != NULL; pDel = pNext) {
        pNext = pDel -> next;

        free(pDel);
    }

    free(pList);
}

int TraverseList(List* pList, int fromWhere, ElementType* pDataOut) {
    if(fromWhere ==0 || pList -> pos == NULL)
        pList -> pos = pList -> head;
    else
        pList -> pos = pList -> pos -> next;

    if(pList -> pos != NULL) {
        *pDataOut = pList -> pos -> data;
        return 1;
    }
    else {
        *pDataOut = 0;
        return 0;
    }
}

int ListCount(List* pList) {
    return pList -> count;
}

int IsEmptyList(List* pList) {
    if(pList -> count == 0)
        return 1;
    else
        return 0;
}
