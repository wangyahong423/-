#ifndef _List_h_
#define _List_h_

#include "Data.h"

//*******           ��Ŀ¼����            *******//
Status InitLinkList_R(LinkList_R *L);
void RElemAssign_R(ElemType_R *e1, ElemType_R e2);
Status GetElemt_R(LinkList_R L,int i,ElemType_R *e);
Status ListInsert_R(LinkList_R L,ElemType_R e)	;
Status ListDelete_R(LinkList_R L,int i,ElemType_R *e);

//******         �û�Ŀ¼����           ******//

Status InitLinkList_U(LinkList_U *L);
void RElemAssign_U(ElemType_U *e1, ElemType_U e2);
Status GetElemt_U(LinkList_U L,int i,ElemType_U *e);
Status ListInsert_U(LinkList_U L,ElemType_U e);
Status ListDelete_U(LinkList_U L,int i,ElemType_U *e);


#endif