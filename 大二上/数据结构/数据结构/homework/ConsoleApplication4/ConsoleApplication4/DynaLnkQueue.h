/***
*DynaLnkQueue.h - ��̬��ʽ���еĶ���
*	
****/

#if !defined(DYNALNKQUEUE_H)
#define DYNALNKQUEUE_H

#include "ElemType.h"

/*------------------------------------------------------------
// ��ʽ���нṹ�Ķ���
------------------------------------------------------------*/

typedef struct Node
{
	ElemType data;				// Ԫ������
	struct Node *next;			// ��ʽ�����н��Ԫ�ص�ָ��
} QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;				// ����ͷָ��
	QueuePtr rear;				// ����βָ��
} LinkQueue;

/*------------------------------------------------------------
// ��ʽ���еĻ�������
------------------------------------------------------------*/

bool InitQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);
bool QueueEmpty(LinkQueue Q);
int  QueueLength(LinkQueue Q);
bool GetHead(LinkQueue Q, ElemType *e);
void QueueTraverse(LinkQueue Q, void (*fp)(ElemType));
void ClearQueue(LinkQueue *Q);
bool EnQueue(LinkQueue *Q, ElemType e);
bool DeQueue(LinkQueue *Q, ElemType *e);

#endif /* DYNALNKQUEUE_H */