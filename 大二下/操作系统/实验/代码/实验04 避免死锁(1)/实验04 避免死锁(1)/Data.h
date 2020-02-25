#ifndef _Data_h_
#define _Data_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElemType PCB
#define Status int
#define true				1
#define false				0
#define OK					1
#define	ERROR				0
#define RESOURCE_NUM		3
#define	MAX_RESOURCE_A_NUM	10
#define	MAX_RESOURCE_B_NUM	5
#define	MAX_RESOURCE_C_NUM	7
#define NAME_MAXSIZE		20
#define PCB_Num 5
typedef struct{
	int MaxNum[RESOURCE_NUM];			//��Ҫÿ����Դ����
	int AllocationNum[RESOURCE_NUM];	//��ռ��ÿ����Դ����
	int NeedNum[RESOURCE_NUM];			//����Ҫ��ÿ����Դ����
}ResourceList;

typedef struct 
{
	char Name[NAME_MAXSIZE];			//������
	ResourceList resList;				//��Դ�嵥
}PCB;

typedef struct Node
{
	ElemType data;
	struct Node * Next;		
}LNode,*LinkList;

#endif
