/***
*SqList.h - 排序表的定义
*	
****/

#ifndef SqList_H
#define SqList_H

#include "ElemType.h"

/*------------------------------------------------------------
// 顺序排序表结构
------------------------------------------------------------*/
typedef struct {  // 结点定义
	ElemType   r[10+1];    // 关键字数组，r[0]不用
	int   length;          // 数组中当前的关键字个数
} SqList;

/*------------------------------------------------------------
// 排序表的基本操作
------------------------------------------------------------*/
void InitSqList(SqList *ll);
void QSort(SqList *L,int low,int high);
void HeapSort(SqList *L);
void InsertSort(SqList *ll);
void ShellSort(SqList *ll, int dlta[],int t);
#endif /* SqList_H */



