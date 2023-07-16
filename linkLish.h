#ifndef  __LINK_LIST_H__
#define __LINK_LIST_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef struct Link
{
    char *data;
    struct Link *next;
    struct Link *prev;
}LinkList; // Cấu trúc 1 phần tử


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void L_CreateTheFirstPointerOfList(LinkList *(*pMain), LinkList *(*F), LinkList *(*L));

void L_CreateTheElementOfList(LinkList *(*pMain), LinkList *(*L));

void L_RecreateTheFirstElement(LinkList *(*pNew), LinkList *(*pOld));

void L_InsertNextElement(LinkList *(*CurrentElement), LinkList *(*Insert), LinkList *(*NextElement));

void L_InsertPrevElement(LinkList *(*CurrentElement), LinkList *(*Insert));

void L_DeleteLinkList(LinkList *(*pMain), LinkList *(*pPREV), LinkList *(*pNEXT));

#endif /*__LINK_LIST_H__*/