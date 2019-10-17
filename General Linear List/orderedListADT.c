#include "orderedListADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool retrieve(LIST* pList, void* pKey, void** pDataOut)
{
    NODE* pPre;
    NODE* pCur;

    if (_search(pList, &pPre, &pCur, pKey))
    {
        *pDataOut = pCur->pData;
        return true;
    } else
    {
        *pDataOut = NULL;
        return false;
    }
}

static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pKey)
{
#define COMPARE (((*pList->compare)(pKey, (*pLoc)->pData)))
#define COMPARE_LAST ((*pList->compare) (pKey, pList->rear->pData))

    int result;
    *pPre = NULL;
    *pLoc = pList->head;
    if (pList->size == 0)
        return false;

    if (COMPARE_LAST > 0)
    {
        *pPre = pList->rear;
        *pLoc = NULL;
        return false;
    }

    while ((result = COMPARE) > 0)
    {
        *pPre = *pLoc;
        *pLoc = (*pLoc)->next;
    }

    if (result == 0)
        return true;
    else
        return false;
}

LIST* createList(int(*compare)(void* pArg1, void* pArg2)) {
    LIST* list = NULL;
    list = (LIST*)malloc(sizeof(LIST));
    if(list) {
        list -> head = NULL;
        list -> pos = NULL;
        list -> rear = NULL;
        list -> size = 0;
        list -> compare = compare;
    }

    return list;
}

void destroyList(LIST* pList) {
    NODE* pDel = NULL, *pNext = NULL;

    for(pDel = pList -> head; pDel != NULL; pDel = pNext) {
        pNext = pDel -> next;

        free(pDel);
    }

    free(pList);
}

bool insert(LIST* pList, void* pDataIn) {
    NODE* pPre = NULL;
    NODE* pLoc = NULL;

    if(!_search(pList, &pPre, &pLoc, pDataIn)) {
        _insert(pList, pPre, pDataIn);
        return true;
    }
    else 
        return false;
}

bool myremove(LIST* pList, void* pKey) {
    NODE* pPre = NULL, *pLoc = NULL;

    if(_search(pList, &pPre, &pLoc, pKey)) {
        _delete(pList, pPre, pLoc);
        return true;
    }
    else 
        return false;
}

int size(LIST* pList) {
    return pList -> size;
}

bool isEmpty(LIST* pList) {
    if(pList -> size == 0)
        return true;
    else
        return false;
}

bool iterate(LIST* pList, void** pDataOut) {
    if(pList -> pos == NULL) {
        pList -> pos = pList -> head;
        *(STUDENT**)(pDataOut) = pList -> pos -> pData;
        return true;
    }
    else if(pList -> pos -> next != NULL) {
        pList -> pos = pList -> pos -> next;
        *(STUDENT**)(pDataOut) = pList -> pos -> pData;
        return true;
    }
    else
        return false;

}

void initIterator(LIST* pList) {
    pList -> pos = pList -> head;
}

void printList(LIST* pList, void(*print)(void* pArg)) {
    NODE* pCur = pList -> head;
    int s = pList -> size;

    while(s--) {
        print((void*)pCur -> pData);
        pCur = pCur -> next;
    }
}

void printStudent(void* pArg) {
    printf("STUDENT ID: %d\n", ((STUDENT*)pArg) -> id);
    printf("NAME: %s\n", ((STUDENT*)pArg) -> name);
    printf("EMAIL: %s\n", ((STUDENT*)pArg) -> email);
}

int cmpStudentId(void* pStudent1, void* pStudent2) {
    return ((STUDENT*)pStudent1) -> id - ((STUDENT*)pStudent2) -> id;
}

static bool _insert(LIST* pList, NODE* pPre, void* pDataIn) {
    NODE* pNew = NULL;
    if(!(pNew = (NODE*)malloc(sizeof(NODE))))
        return false;
    pNew -> pData = pDataIn;
    pNew -> next = NULL;

    if(pPre == NULL) {
        pNew -> next = pList -> head;
        pList -> head = pNew;
        if(pList -> size == 0)
            pList -> rear = pNew;
    }
    else {
        pNew -> next = pPre -> next;
        pPre -> next = pNew;

        if(pNew -> next == NULL)
            pList -> rear = pNew;
    }

    (pList -> size)++;
    return true;
}

static void _delete(LIST* pList, NODE* pPre, NODE* pCur) {
    if(pPre == NULL)
        pList -> head = pCur -> next;
    else
        pPre -> next = pCur -> next;

    if(pCur -> next == NULL)
        pList -> rear = pPre;

    free(pCur);
    (pList -> size)--;
}
