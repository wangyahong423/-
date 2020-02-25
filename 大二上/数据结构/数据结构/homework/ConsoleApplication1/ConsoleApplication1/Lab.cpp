#include <stdio.h>
#include "DynaLnkList.h"

int main()
{
	// TODO: Place your test code here
    LinkList mylist;
    if(InitList(&mylist))
        printf("初始化成功!\n");
    else
        printf("初始化失败!\n");
    
    ListInsert(mylist,1, -9);
    ListInsert(mylist,1, 0);
    ListInsert(mylist,1, 77);
    ListInsert(mylist,1, 21);
    ListInsert(mylist,1, -88);
    ListInsert(mylist,1, -3);
    ListInsert(mylist,1, 33);
    ListInsert(mylist,1, -22);
    ListInsert(mylist,1, 11);
    ListTraverse(mylist, visit);
    //DestroyList(&mylist);
    printf("依次插入元素后链表L长度为：%d\n",ListLength(mylist));
    printf("依次插入元素后链表L为：\n");
    ListTraverse(mylist, visit);
    printf("请输入删除倒数第几个结点：\n");
    int i;
    ElemType e;
    scanf("%d",&i);    
    printf("删除后的L为：\n");
    ListDelete(mylist, 9+1-i,&e);
    ListTraverse(mylist, visit);
    Inverse(mylist);//逆置
    printf("逆置之后链表为：\n");
    ListTraverse(mylist, visit);
    printf("排序：\n");
    Sort(&mylist);
	return 0;
}