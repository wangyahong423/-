/***
*DynaLnkList.cpp - 动态链表，即顺序表的动态链式存储实现
*
*
*题目：实验2-2 线性表的动态链式存储实现
*
*班级：2017级
*
*姓名：王亚红
*
*学号：2017011743
*	
****/

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaLnkList.h"

/*------------------------------------------------------------
操作目的：	初始化链表
初始条件：	无
操作结果：	构造一个空的线性表
函数参数：
		LinkList *L	待初始化的线性表
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool InitList(LinkList *L)
{
    *L = (LinkList) malloc(sizeof(LNode));
    if(!L)//等价于NULL==L
        return false;
    (*L)->next = NULL;//加括号
    return true;
}

/*------------------------------------------------------------
操作目的：	销毁链表
初始条件：	线性表L已存在
操作结果：	销毁线性表L
函数参数：
		LinkList *L	待销毁的线性表
返回值：
		无
------------------------------------------------------------*/
void DestroyList(LinkList *L)
{
    LinkList p;
    while(*L != NULL){
        p = *L;
        *L = p->next;
        free(p);
    }
}

/*------------------------------------------------------------
操作目的：	判断链表是否为空
初始条件：	线性表L已存在
操作结果：	若L为空表，则返回true，否则返回false
函数参数：
		LinkList L	待判断的线性表
返回值：
		bool		是否为空
------------------------------------------------------------*/
bool ListEmpty(LinkList L)
{
    return true;
}

/*------------------------------------------------------------
操作目的：	得到链表的长度
初始条件：	线性表L已存在
操作结果：	返回L中数据元素的个数
函数参数：
		LinkList L	线性表L
返回值：
		int			数据元素的个数
------------------------------------------------------------*/
int ListLength(LinkList L)
{
    LinkList p = L;
    int len = 0;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

/*------------------------------------------------------------
操作目的：	得到链表的第i个元素
初始条件：	线性表L已存在，1<=i<=ListLength(L)
操作结果：	用e返回L中第i个数据元素的值
函数参数：
		LinkList L	线性表L
		int i		数据元素的位置
		ElemType *e	第i个数据元素的值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool GetElem(LinkList L, int i, ElemType *e)
{
    return true;
}

/*------------------------------------------------------------
操作目的：	得到链表指定元素的位置
初始条件：	线性表L已存在
操作结果：	返回L中第一个与e满足关系compare()的数据元素的位序。
			若这样的元素不存在则返回0。
函数参数：
		LinkList L	线性表L
		ElemType e	数据元素e
		int (*fp)()	用于比较相等的函数指针
返回值：
		int			与e满足关系compare()的数据元素的位序
------------------------------------------------------------*/
int LocateElem(LinkList L, ElemType e, int (*fp)(ElemType, ElemType))
{
    return 0;
}

/*------------------------------------------------------------
操作目的：	得到链表指定元素的前驱
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是第一个，则用pre_e返回
			它的前驱，否则操作失败，pre_e无定义
函数参数：
		LinkList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *pre_e	前驱数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    return true;
}

/*------------------------------------------------------------
操作目的：	得到链表指定元素的后继
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是最后一个，则用nxt_e返
			回它的后继，否则操作失败，nxt_e无定义
函数参数：
		LinkList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *nxt_e	后继数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool NextElem(LinkList L, ElemType cur_e, ElemType *nxt_e)
{
    return true;
}

/*------------------------------------------------------------
操作目的：	遍历链表
初始条件：	线性表L已存在
操作结果：	依次对L的每个元素调用函数fp
函数参数：
		LinkList L		线性表L
		void (*fp)()	访问每个数据元素的函数指针
返回值：
		无
------------------------------------------------------------*/
void ListTraverse(LinkList L, void (*fp)(ElemType))
{
    LinkList p = L->next;
    while(p){
        (*fp)(p->data);
        p = p->next;
    }
}

/*------------------------------------------------------------
操作目的：	清空链表
初始条件：	线性表L已存在
操作结果：	将L置为空表
函数参数：
		LinkList L	线性表L
返回值：
		无
------------------------------------------------------------*/
void ClearList(LinkList L)
{
}

/*------------------------------------------------------------
操作目的：	在链表的指定位置插入结点，插入位置i表示在第i个
			元素之前插入
初始条件：	线性表L已存在，1<=i<=ListLength(L) + 1
操作结果：	在L中第i个位置之前插入新的数据元素e，L的长度加1
函数参数：
		LinkList L	线性表L
		int i		插入位置
		ElemType e	待插入的数据元素
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListInsert(LinkList L, int i, ElemType e)
{
    int j=0;
    while(L != NULL && j<i-1){
        //寻找第i-1个结点
        L = L->next;//最终第i-1个结点为p
        ++j;
    }
    if(!L || j>i-1){  //判断p是否为空或者是否超出范围
        return false;
    }
    LinkList s = (LinkList) malloc(sizeof(LNode)); //新建一个结点
    //判断结点是否新建成功
    if(NULL == s)
        return false;
    //创建成功，插入结点
    s->data = e;
    s->next = L->next;
    L->next = s;
    //插入成功，返回true
    return true;
}

/*------------------------------------------------------------
操作目的：	删除链表的第i个结点
初始条件：	线性表L已存在且非空，1<=i<=ListLength(L)
操作结果：	删除L的第i个数据元素，并用e返回其值，L的长度减1
函数参数：
		LinkList L	线性表L
		int i		删除位置
		ElemType *e	被删除的数据元素值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListDelete(LinkList L, int i, ElemType *e)
{
    LinkList p = L;
    int j = 0;
    while(p->next && j < i-1){
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i-1)
        return false;
    LinkList q = p->next;
    p->next = q->next;
    e = &(q->data);
    free(q);
    return true;
}

/*------------------------------------------------------------
操作目的：	逆置链表
初始条件：	线性表L已存在且非空，1<=i<=ListLength(L)
操作结果：	逆置整个链表
函数参数：
		LinkList L	线性表L
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool Inverse(LinkList L){
    LinkList p = NULL;
    LinkList temp;
    LinkList q = L->next;
    while(q != NULL){
        temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    L->next = p;
    return true;
}
