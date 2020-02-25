#include "ProPCB.h"

extern int CPUUsedTime;

Status GetProcess(LinkList Q,ElemType e)
{
	return ListInsert_L(Q, e);
}

double GetPriority(ElemType *e, PriorityRule PR)
{
	if(PR == FCFS)
		return Infinity - e->ArrivalTime;
	else if(PR == SPF)
		return Infinity - e->NeedRunningTime + e->TimeUsedCPU;
	else if(PR == HRRatio)
		return (e->WaitingTime * 1.0 + e->NeedRunningTime) / (e->NeedRunningTime );
	else
		printf("GetPriority Function ERROR!\n");
	return ERROR;
}

Status OutProsess(LinkList Q,ElemType *e)
{
	return ListDelete_L(Q ,e);
}

//��һ��CPU����ʱ������1��ʱ��Ƭ
Status CPURunPro(LinkList Q,PCB *pcb,PriorityRule PR)
{
	if(pcb->StartTime == -1)
		pcb->StartTime = CPUUsedTime;
	pcb->ProcessState = Running;

    pcb->WaitingTime += TimeSlice;          //�ȴ�ʱ���ڽ���ִ��ʱ��Ҳ��ȴ�
    //PrintProQueue(Q, pcb);
    pcb->TimeUsedCPU += TimeSlice;
	
	return OK;
}

Status AddWaitTime(LinkList Q)
{
	LNode *p = Q->Next;
	while (p)
	{
		p->data.WaitingTime += TimeSlice;
        p->data.Priority = GetPriority(&(p->data),HRRatio);
		p = p->Next;
	}
	return OK;
}

void PrintProQueue(LinkList Q, PCB *pcb)
{
	LinkList p = Q->Next;
    printf("CPUTime: %d\n",CPUUsedTime);
	printf("������  ������  ����ʱ��  ����ʱ��  ����CPUʱ��  ���ʱ��      �ȴ�ʱ��   ���к���Ӧ��    ����״̬\n");
	if(pcb)
		printf(" %4s    %5.2f      %2d       %2d      %3d             %3d        %3d          %5.2f         %4s  \n",
			pcb->Name,pcb->Priority,pcb->ArrivalTime,pcb->NeedRunningTime,
			pcb->TimeUsedCPU, pcb->FinishTime, pcb->WaitingTime, (pcb->WaitingTime*1.0 + pcb->NeedRunningTime) / pcb->NeedRunningTime ,pcb->ProcessState == Ready ? "����" : "����");
	while (p)
	{
		printf(" %4s    %5.2f      %2d       %2d      %3d             %3d        %3d          %5.2f         %4s  \n",
			p->data.Name,p->data.Priority,p->data.ArrivalTime,p->data.NeedRunningTime,
			p->data.TimeUsedCPU,p->data.FinishTime,p->data.WaitingTime, (p->data.WaitingTime*1.0 + p->data.NeedRunningTime) / p->data.NeedRunningTime , p->data.ProcessState == Ready ? "����" : "����");
		p = p->Next;
	}
	printf("-------------------------------------------------------------------------------------------------\n");
}


void PrintProResult(PCB *pcb)
{
	printf("������  ����ʱ�� ��ʼʱ�� ��ҪCPUʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��      ����״̬\n");
	if(pcb)
		printf(" %2s     %4d      %4d        %3d      %3d     %4d       %5.2lf          %4s  \n",
			pcb->Name,pcb->ArrivalTime,pcb->StartTime,pcb->NeedRunningTime,pcb->FinishTime,
			pcb->FinishTime-pcb->ArrivalTime,((pcb->FinishTime - pcb->ArrivalTime)*1.0)/pcb->NeedRunningTime,  "���");
	
	printf("------------------------------------------------------------------------------------------\n");
}

//
//void PrintProQueue1(LinkList Q, PCB *pcb)
//{
//	LinkList p = Q->Next;
//
//	printf("������  ������  ����ʱ��  ����ʱ��  ����CPUʱ��  ����״̬\n");
//	if(pcb)
//		printf(" %4s     %2d      %4d      %4d     %3d(+1)       %4s  \n",
//			pcb->Name,pcb->Priority,pcb->ArrivalTime,pcb->NeedRunningTime,
//			pcb->TimeUsedCPU,pcb->ProcessState == Ready ? "����" : "����");
//	while (p)
//	{
//		printf(" %4s     %2d      %4d      %4d        %3d        %4s  \n",
//			p->data.Name,p->data.Priority,p->data.ArrivalTime,p->data.NeedRunningTime,
//			p->data.TimeUsedCPU,p->data.ProcessState == Ready ? "����" : "����");
//		p = p->Next;
//	}
//	printf("---------------------------------------------------------\n");
//}
//








