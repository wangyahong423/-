#ifndef _ChainList_h_
#define _ChainList_h_

#include "Data.h"

Status Init(LinkList *L);

void Assignment(ElemType *e1, ElemType e2);

//�����а������ȼ����Ӵ�С�������
Status ListInsert_L(LinkList L,ElemType e);
//������ͷ��ɾ��
Status ListDelete_L(LinkList L,ElemType *e);



#endif