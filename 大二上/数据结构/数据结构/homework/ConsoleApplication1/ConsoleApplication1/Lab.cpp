#include <stdio.h>
#include "DynaLnkList.h"

int main()
{
	// TODO: Place your test code here
    LinkList mylist;
    if(InitList(&mylist))
        printf("��ʼ���ɹ�!\n");
    else
        printf("��ʼ��ʧ��!\n");
    
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
    printf("���β���Ԫ�غ�����L����Ϊ��%d\n",ListLength(mylist));
    printf("���β���Ԫ�غ�����LΪ��\n");
    ListTraverse(mylist, visit);
    printf("������ɾ�������ڼ�����㣺\n");
    int i;
    ElemType e;
    scanf("%d",&i);    
    printf("ɾ�����LΪ��\n");
    ListDelete(mylist, 9+1-i,&e);
    ListTraverse(mylist, visit);
    Inverse(mylist);//����
    printf("����֮������Ϊ��\n");
    ListTraverse(mylist, visit);
    printf("����\n");
    Sort(&mylist);
	return 0;
}