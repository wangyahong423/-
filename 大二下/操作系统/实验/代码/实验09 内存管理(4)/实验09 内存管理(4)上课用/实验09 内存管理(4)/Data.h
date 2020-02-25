#ifndef _Data_h_
#define _Data_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
#define BlockNumType		PageData //��ҳ��Ϣ
#define TotalMemory			512	//KB
#define PageSize			16	//ͨ��Ϊ1 ~ 8KB    //���������ڴ�Ĵ�С[16, 256]KB    256 / 8 = 32ҳ
#define PageArrLength       ((512 - 16) / PageSize)


typedef enum 
{
	Unallocated, Allocated
}DistributState, PartitionSt;



typedef struct {
							//�������������±����
	int PartStartAddr;
	char Name[NAME_MAXSIZE];//��Ϊ�գ����������
}PartitionInfo;

typedef struct
{
	PartitionInfo *elem;
	int listsize;		//������
	int length;			//Ԫ�ظ���
}SqList_f, PartTable;	//����ʹ��˵����


typedef struct {					    
	int BlockNum;               //���
	DistributState DistbutSt;	//����״̬
}PageData;


typedef struct
{
	PageData *elem;	
	int listsize;		
	int length;			
}SqList_y, PageTable;	//ҳ��


typedef struct 
{
	char Name[NAME_MAXSIZE];	//������
	int	MemorySize;				//�ڴ�Ĵ�С
    int PagesLoadedNum;         //װ��ҳ�����
	PageTable *pPagetable;		//ҳ��ָ��
}PCB;

typedef struct Node
{
	PCBType data;
	struct Node * Next;		
}LNode, *LinkList, *PCBList;


#endif 
