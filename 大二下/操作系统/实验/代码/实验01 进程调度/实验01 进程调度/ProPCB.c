#include "ProPCB.h"

extern int CPUUsedTime;

//���ܣ���e��������Q
Status GetProcess(LinkList Q,ElemType e)
{
	return OK;
}

//���ܣ����ݲ�ͬ�����ȼ����򣬷���������
int GetPriority(ElemType *e, PriorityRule PR)
{
    if(PR==FCFS){
        return Infinity - e->ArrivalTime;
    }
    else if(PR == SPF){
        return Infinity - e->NeedRunningTime;
    }
    else{
        printf("PriorityRule is ERROR!\n");
    }
    return ERROR;
}

//���ܣ�������Q��ͷ������ݷŵ�eָ����ڴ棬��ɾ��
Status OutProsess(LinkList Q,ElemType *e)
{
    return ListDelete_L(Q, e);
}

//��һ��CPU����ʱ������1��ʱ��Ƭ
Status CPURunPro(LinkList Q,PCB *pcb)
{
    if(pcb->StartTime == -1){
        pcb->StartTime = CPUUsedTime;
    }
    pcb->TimeUsedCPU+=TimeSlice;
    pcb->ProcessState = Running;
    return OK;
}

//���ܣ���ӡ����PCB��Ϣ
void PrintProQueue(LinkList Q, PCB *pcb)
{
   
}

//���ܣ���һ�����̽�������ӡ������Ϣ
void PrintProResult(PCB *pcb)
{
    
}


