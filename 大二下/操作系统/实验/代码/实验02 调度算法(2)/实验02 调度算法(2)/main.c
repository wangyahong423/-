#include "ProPCB.h"

/********************************************
 *		ʵ��02: ��ռʽ��̬����Ȩ���̽�������		*
 *		�� ����Ȩ���ھ�̬����Ȩ					*
 *		�� ����CPU����һ��ʱ��Ƭ				*
 *		�� �������ȸ�������Ȩ�Ͷ̽��������������	*
 *		�� ���ǵ���ʱ�䲻ͬ					*
 *******************************************/

int CPUUsedTime = 0;

void InputData(LinkList * pPCBdata, PriorityRule PR)
{
	ElemType e = {{0},-1,-1,-1,-1,-1,-1,0,Ready};
	e.ArrivalTime = 0;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"A");
	e.Priority = GetPriority(&e, PR);
	e.GivenPriority = 8;
	e.NeedRunningTime = 4;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 1;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"B");
	e.Priority = GetPriority(&e, PR);
	e.GivenPriority = 3;
	e.NeedRunningTime = 3;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 2;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"C");
	e.Priority = GetPriority(&e, PR);
	e.GivenPriority = 2;
	e.NeedRunningTime = 5;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 3;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"D");
	e.Priority = GetPriority(&e, PR);
	e.GivenPriority = 9;
	e.NeedRunningTime = 2;
	GetProcess(*pPCBdata,e);

	e.ArrivalTime = 4;
	e.ProcessState = Ready;
	e.TimeUsedCPU = 0;
	strcpy(e.Name,"E");
	e.Priority = GetPriority(&e, PR);
	e.GivenPriority = 7;
	e.NeedRunningTime = 4;
	GetProcess(*pPCBdata,e);
}

int main(void)
{
	LinkList PCBQueue=NULL, PCBdata=NULL;	//PCBdata������ԭʼ����
    LNode *p;
	PriorityRule PR;
	ElemType e = {{0},-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,0 , Ready};
	ElemType *pcb = NULL;

	Init(&PCBdata);
	InputData(&PCBdata, FCFS);	
	PrintProQueue(PCBdata, pcb);

	//����������׼���׶�
	Init(&PCBQueue);			
	p = PCBdata->Next;			//����ӳ�ʼ�����������ݵ�ָ��p
	
	PR = SPF;					// SPF, SS	//�̽������ȣ���̬����Ȩ
	while (p || PCBQueue->Next)
	{
		if(p && p->data.ArrivalTime == CPUUsedTime)
		{
			p->data.Priority = GetPriority(&(p->data), PR);//����ȷ������Ȩ����Ϊ��ʼ̬
			GetProcess(PCBQueue, p->data);
			p = p->Next;
		}
		if(!OutProsess(PCBQueue, &e) && p)	//��ͷԪ�س���
		{
			++CPUUsedTime;
			break;
		}
		CPURunPro(PCBQueue, &e);		//��CPU
		++CPUUsedTime;						//CPUʱ������

		if(e.TimeUsedCPU < e.NeedRunningTime)	//����CPU�Ľ����Ƿ����
		{
			e.ProcessState = Ready;
            e.Priority = GetPriority(&e, PR);  //ȡ����������Ȩ
			GetProcess(PCBQueue, e);
		}else
		{
			e.FinishTime = CPUUsedTime;
			PrintProResult(&e);
		}
	}

	return 0;
}

void Assignment(ElemType *e1,ElemType e2){
    e1->ArrivalTime = e2.ArrivalTime;
    strcpy(e1->Name,e2.Name);

}
