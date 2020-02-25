#include "ChainList.h"

extern int CPUUsedTime;

//功能：链表初始化
Status Init(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        return ERROR;
    (*L)->Next = NULL;
    return OK;
}

//功能：赋值运算，将e2赋值给e1
void Assignment(ElemType *e1, ElemType e2)
{
    
}


Status GetElemt_L(LinkList L,int i,ElemType *e)
    //当我们进行的操作要进行，写操作时，传递引用或地址
{
    
    return OK;
}
//链表中按照优先级：从大到小排序插入
Status ListInsert_L(LinkList L,ElemType e)	//这样修改应该不对 p = *L出错
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
//链表中头部删除
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


