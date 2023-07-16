/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include "linkLish.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/************************************************************************************
 * Static function
 *************************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/

void L_CreateTheFirstPointerOfList(LinkList *(*pMain), LinkList *(*F), LinkList *(*L))
{
    (*pMain)->prev = NULL;
    *F = *pMain;
    *L = *pMain;
}

void L_CreateTheElementOfList(LinkList *(*pMain), LinkList *(*L))
{
    LinkList *pTemp;
    pTemp = *L;
    pTemp->next = *pMain;
    (*pMain)->prev = pTemp;
    *L = *pMain;
}

void L_RecreateTheFirstElement(LinkList *(*pNew), LinkList *(*pOld))
{
    (*pNew)->next = *pOld;
    (*pOld)->prev = *pNew;
    (*pNew)->prev = NULL;
}

void L_InsertNextElement(LinkList *(*CurrentElement), LinkList *(*Insert), LinkList *(*NextElement))
{
    (*CurrentElement)->next = *Insert;
    (*Insert)->prev = *CurrentElement;
    (*Insert)->next = *NextElement;
    (*NextElement)->prev = *Insert;
}
// CurrentElement : Phần tử đang xét
// Insert : Phần tử chèn 
void L_InsertPrevElement(LinkList *(*CurrentElement), LinkList *(*Insert))
{
    LinkList *PreElement;
    PreElement = (*CurrentElement)->prev;
    PreElement->next = *Insert;
    (*Insert)->prev = PreElement;
    (*Insert)->next = *CurrentElement;
    (*CurrentElement)->prev = *Insert;
}

void L_DeleteLinkList(LinkList *(*pMain), LinkList *(*pPREV), LinkList *(*pNEXT))
{
    (*pPREV)->next = (*pNEXT);
    (*pNEXT)->prev = (*pPREV);
    free((*pMain));
}
