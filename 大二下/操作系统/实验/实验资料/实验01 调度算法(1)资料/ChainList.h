#ifndef _ChainList_h_
#define _ChainList_h_

#include "Data.h"

//���ܣ������ʼ��
Status Init(LinkList *L);

//���ܣ���ֵ���㣬��e2��ֵ��e1
void Assignment(ElemType *e1, ElemType e2);

//���ܣ���ȡ��i�����Ԫ��
Status GetElemt_L(LinkList L,int i,ElemType *e);

//���ܣ�����������ȼ�����Ԫ��
Status ListInsert_L(LinkList L,ElemType e);

//���ܣ�����ɾ��ͷ���
Status ListDelete_L(LinkList L,ElemType *e);


#endif