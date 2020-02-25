#ifndef _List_h_
#define _List_h_

#include "Data.h"

//*******           ����            *******//
Status InitLinkList(LinkList *L);
void PCBAssign(PCBType *e1, PCBType e2);
Status GetElemt_L(LinkList L,int i,PCBType *e);
Status ListInsert_L(LinkList L,PCBType e);
Status ListDelete_L(LinkList L,int i,PCBType *e);

//******         ����ʹ��˵����           ******//
void PartiAssign_f(PartiType *e1, PartiType e2);
Status InitList_f(SqList_f *L);
Status ListInsert_f(SqList_f *L,int i,PartiType e);
Status ListDelete_f(SqList_f *L,int i,PartiType *e);


//******         ҳ��           ******//
void PartiAssign_y(BlockNumType *e1, BlockNumType e2);
Status InitList_y(SqList_y **L);
Status ListInsert_y(SqList_y *L,int i,BlockNumType e);
Status ListDelete_y(SqList_y *L,int i,BlockNumType *e);

#endif