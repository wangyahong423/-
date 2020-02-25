#ifndef _Data_h_
#define _Data_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElemType PCB
#define Status int
#define OK		1
#define	ERROR	0
#define TimeSlice	1
#define Infinity 10 //INT_MAX


#define NAME_MAXSIZE 20
typedef enum 
{
	Ready,Running,Block
}ProState;

typedef enum 
{
	FCFS, SPF, SS	//�����ȷ��񣬶̽������ȣ���̬����Ȩ(�Լ�����)
}PriorityRule;


typedef struct 
{
	char Name[NAME_MAXSIZE];	//������
	int Priority;				//������
	int GivenPriority;			//��������Ȩ
	int ArrivalTime;			//����ʱ��		��ʱ��ƬΪ��λ
	int NeedRunningTime;		//����ʱ��		��ʱ��ƬΪ��λ
	int StartTime;				//��ʼִ��ʱ��
	int FinishTime;				//���ʱ��
	int TimeUsedCPU;			//����CPUʱ��		��ʱ��ƬΪ��λ
	ProState ProcessState;		//����״̬
}PCB;

typedef struct Node
{
	ElemType data;
	struct Node * Next;		
}LNode,*LinkList;



#endif
