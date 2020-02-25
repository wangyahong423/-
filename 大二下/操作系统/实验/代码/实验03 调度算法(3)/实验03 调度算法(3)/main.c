#include "ProPCB.h"


int CPUUsedTime = 0;

void InputData(LinkList * pPCBdata)
{
	ElemType e = {{0},-1,-1,-1,-1,-1,-1,0,Ready};
	e.ArrivalTime = 0;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"A");
	e.WaitingTime = 0;
	e.Priority = GetPriority(&e,FCFS);
	e.NeedRunningTime = 4;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 1;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"B");
	e.WaitingTime = 0;
	e.Priority = GetPriority(&e,FCFS);
	e.NeedRunningTime = 1;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 2;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"C");
	e.WaitingTime = 0;
	e.Priority = GetPriority(&e,FCFS);
	e.NeedRunningTime = 3;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 3;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"D");
	e.WaitingTime = 0;
	e.Priority = GetPriority(&e,FCFS);
	e.NeedRunningTime = 3;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 4;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"E");
	e.WaitingTime = 0;
	e.Priority = GetPriority(&e,FCFS);
	e.NeedRunningTime = 4;
	GetProcess(*pPCBdata,e);
}

int main(void)
{
	LinkList PCBQueue = NULL, PCBdata = NULL;	//PCBdata������ԭʼ����
	ElemType e = {{0},-1,-1,-1,-1,-1,-1,0,Ready};
	ElemType *pcb = NULL;
	LNode *p;
	PriorityRule PR;
	Init(&PCBdata);
	InputData(&PCBdata);
	PrintProQueue(PCBdata, pcb);

	//����������׼���׶�
	Init(&PCBQueue);			//��ʼ����������
	p = PCBdata->Next;			//����ӳ�ʼ�����������ݵ�ָ��p
	
	PR = HRRatio;			    //ѡ������㷨
	while (p || PCBQueue->Next)
	{
		if(p && p->data.ArrivalTime == CPUUsedTime)
		{
			p->data.Priority = GetPriority(&(p->data), PR); 
			GetProcess(PCBQueue, p->data);
			p = p->Next;
		}
		OutProsess(PCBQueue, &e);	//��ͷԪ�س���
		CPURunPro(PCBQueue,&e, PR);	//��CPU
		++CPUUsedTime;				//CPUʱ������

		AddWaitTime(PCBQueue);		//����ǰδ��CPU�����ӵȴ�ʱ��
        e.Priority = GetPriority(&e, PR);
        //PrintProQueue(PCBQueue, &e);
		if(e.TimeUsedCPU < e.NeedRunningTime)	//����CPU�Ľ����Ƿ����
		{
			e.ProcessState = Ready;
            e.Priority = GetPriority(&e, PR);
			GetProcess(PCBQueue,e);
		}else
		{
			e.FinishTime = CPUUsedTime;
			PrintProResult(&e);
		}
	}

	return 0;
}