#include "ChainList.h"

extern int CPUUsedTime;

//���ܣ������ʼ��
Status Init(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        return ERROR;
    (*L)->Next = NULL;
    return OK;
}

//���ܣ���ֵ���㣬��e2��ֵ��e1
void Assignment(ElemType *e1, ElemType e2)
{
    
}


Status GetElemt_L(LinkList L,int i,ElemType *e)
    //�����ǽ��еĲ���Ҫ���У�д����ʱ���������û��ַ
{
    
    return OK;
}
//�����а������ȼ����Ӵ�С�������
Status ListInsert_L(LinkList L,ElemType e)	//�����޸�Ӧ�ò��� p = *L����
{
    LinkList p = L->Next,pre=L,s;
    while(p&&p->data.Priority >= e.Priority ){
        pre=p;
        p=p->Next;
    }
    s=(LinkList)malloc(sizeof(LNode));
    Assignment(&s->data,e);
    s->Next = p;
    pre->Next = s;
    return OK;
}
//������ͷ��ɾ��
Status ListDelete_L(LinkList L,ElemType *e)
{
    LinkList P=L,q=L->Next;
    if(!q)
        return ERROR;
    p->Next = q->Next;
    Assignment(e,q->data);
    free(q);
    return OK;
}


