#include "ProPCB.h"

extern int CPUUsedTime;

Status GetProcess(LinkList Q,ElemType e)
{
	return ListInsert_L(Q, e);
}

int GetPriority(ElemType *e, PriorityRule PR)
{
	if(PR == FCFS)
		return Infinity - e->ArrivalTime;
	else if(PR == SPF)
		return Infinity - (e->NeedRunningTime - e->TimeUsedCPU);  
	else if(PR == SS)
		return e->GivenPriority;
	else
		printf("GetPriority Function ERROR!\n");
	return ERROR;
}

Status OutProsess(LinkList Q,ElemType *e)
{
	return ListDelete_L(Q ,e);
}
//��һ��CPU����ʱ������1��ʱ��Ƭ
Status CPURunPro(LinkList Q,PCB *pcb)
{
	if(pcb->StartTime == -1)
		pcb->StartTime = CPUUsedTime;
	pcb->ProcessState = Running;
	//PrintProQueue(Q, pcb);
	pcb->TimeUsedCPU += TimeSlice;
	

	return OK;
}


void PrintProQueue(LinkList Q, PCB *pcb)
{
	LinkList p = Q->Next;

	printf("������  ������  ����ʱ��  ����ʱ��  ����CPUʱ��  ���ʱ��  ����״̬\n");
	if(pcb)
		printf(" %4s     %2d      %4d      %4d     %3d(+1)       %3d        %4s  \n",
			pcb->Name,pcb->GivenPriority,pcb->ArrivalTime,pcb->NeedRunningTime,
			pcb->TimeUsedCPU, pcb->FinishTime,pcb->ProcessState == Ready ? "����" : "����");
	while (p)
	{
		printf(" %4s     %2d      %4d      %4d     %3d           %3d        %4s  \n",
			p->data.Name,p->data.GivenPriority,p->data.ArrivalTime,p->data.NeedRunningTime,
			p->data.TimeUsedCPU,p->data.FinishTime, p->data.ProcessState == Ready ? "����" : "����");
		p = p->Next;
	}
	printf("-------------------------------------------------------------------------------\n");
}


void PrintProResult(PCB *pcb)
{
	printf("������  ����ʱ�� ��ʼʱ�� ����ʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ�� ����״̬\n");
	if(pcb)
		printf(" %2s     %4d      %4d        %3d      %3d     %4d       %5.2lf       %4s  \n",
			pcb->Name,pcb->ArrivalTime,pcb->StartTime,pcb->NeedRunningTime,pcb->FinishTime,
			pcb->FinishTime-pcb->ArrivalTime,((pcb->FinishTime - pcb->ArrivalTime)*1.0)/pcb->NeedRunningTime,"���");
	
	printf("-------------------------------------------------------------------------------\n");
}
