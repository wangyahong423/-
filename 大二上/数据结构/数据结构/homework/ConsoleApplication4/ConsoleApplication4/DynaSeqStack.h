/***
*DynaSeqStack.h - ��̬˳��ջ�Ķ���
*	
****/

#if !defined(DYNASEQSTACK_H)
#define DYNASEQSTACK_H

#include "ElemType.h"

/*------------------------------------------------------------
// ջ�ṹ�Ķ���
------------------------------------------------------------*/
typedef struct Stack
{
	ElemType *base;				// ջ��ַ
	ElemType *top;				// ջ��
	int stacksize;				// ջ�洢�ռ�ĳߴ�
} SqStack;

/*------------------------------------------------------------
// ջ�Ļ�������
------------------------------------------------------------*/

bool InitStack(SqStack *S);
void DestroyStack(SqStack *S);
bool StackEmpty(SqStack S);
int  StackLength(SqStack S);
bool GetTop(SqStack S, ElemType *e);
void StackTraverse(SqStack S, void (*fp)(ElemType));
bool Push(SqStack *S, ElemType e);
bool Pop(SqStack *S, ElemType *e);

#endif /* DYNASEQSTACK_H */
