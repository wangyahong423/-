/***
*SqList.h - �����Ķ���
*	
****/

#ifndef SqList_H
#define SqList_H

#include "ElemType.h"

/*------------------------------------------------------------
// ˳�������ṹ
------------------------------------------------------------*/
typedef struct {  // ��㶨��
	ElemType   r[10+1];    // �ؼ������飬r[0]����
	int   length;          // �����е�ǰ�Ĺؼ��ָ���
} SqList;

/*------------------------------------------------------------
// �����Ļ�������
------------------------------------------------------------*/
void InitSqList(SqList *ll);
void QSort(SqList *L,int low,int high);
void HeapSort(SqList *L);
void InsertSort(SqList *ll);
void ShellSort(SqList *ll, int dlta[],int t);
#endif /* SqList_H */



