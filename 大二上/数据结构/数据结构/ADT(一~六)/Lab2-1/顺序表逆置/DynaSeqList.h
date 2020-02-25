/***
*DynaSeqList.h - ��̬˳���Ķ���
*	
****/

#if !defined(DYNASEQLIST_H)
#define DYNASEQLIST_H

#include "ElemType.h"

/*------------------------------------------------------------
// ˳���ṹ�Ķ���
------------------------------------------------------------*/

typedef struct List
{
	ElemType *elem;				// �洢�ռ�Ļ�ַ
	int length;					// ˳����н��Ԫ�صĸ���
	int listsize;				// ˳���Ĵ洢�ռ��С
} SqList;

/*------------------------------------------------------------
// ˳���Ļ�������
------------------------------------------------------------*/

bool InitList(SqList *L);
void DestroyList(SqList *L);
bool ListEmpty(SqList L);
int  ListLength(SqList L);
bool GetElem(SqList L, int i, ElemType *e);
int  LocateElem(SqList L, ElemType e, int (*fp)(ElemType, ElemType));
bool PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
bool NextElem(SqList L, ElemType cur_e, ElemType *nxt_e);
void ListTraverse(SqList L, void (*fp)(ElemType));
void ClearList(SqList *L);
bool ListInsert(SqList *L, int i, ElemType e);
bool ListDelete(SqList *L, int i, ElemType *e);
void Reserve(SqList *L);

#endif /* DYNASEQLIST_H */