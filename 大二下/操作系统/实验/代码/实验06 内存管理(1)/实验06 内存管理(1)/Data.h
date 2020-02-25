#ifndef _Data_h_
#define _Data_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT  2
#define true				1
#define false				0
#define PCBType				PCB
#define Status				int
#define OK					1
#define	ERROR				0
#define NAME_MAXSIZE		20
#define PCB_Num				5
#define LIST_INITSIZE		10
#define PartiType			PartitionInfo
#define TotalMemory			512	//KB


typedef enum 
{
	Unallocated, Allocated
}DistributState, PartitionSt;

typedef enum
{
	FirstPriority, BestAdapt
}AllocatStrategy;


typedef struct 
{
	char Name[NAME_MAXSIZE];	//������
	int	MemorySize;				//�ڴ�Ĵ�С
	int StartAddress;			//�ڴ���ʼ��ַ
	DistributState DistbutSt;	//����״̬
}PCB;

typedef struct Node
{
	PCBType data;
	struct Node * Next;		
}LNode, *LinkList, *PCBList;			//

typedef struct {
							//�������������±����
	int PartitionSize;
	int PartStartAddr;
	char Name[NAME_MAXSIZE];//��Ϊ�գ����������
}PartitionInfo;

typedef struct
{
	PartiType *elem;
	int listsize;		//������
	int length;			//Ԫ�ظ���
}SqList, PartTable;		//������

#endif 
