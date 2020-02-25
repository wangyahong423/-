#include "ProPCB.h"

extern int CPUUsedTime;

//功能：将e插入链表Q
Status GetProcess(LinkList Q,ElemType e)
{
	return OK;
}

//功能：根据不同的优先级规则，返回优先数
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

//功能：将链表Q的头结点数据放到e指向的内存，并删除
Status OutProsess(LinkList Q,ElemType *e)
{
    return ListDelete_L(Q, e);
}

//上一次CPU运行时间增加1个时间片
Status CPURunPro(LinkList Q,PCB *pcb)
{
    if(pcb->StartTime == -1){
        pcb->StartTime = CPUUsedTime;
    }
    pcb->TimeUsedCPU+=TimeSlice;
    pcb->ProcessState = Running;
    return OK;
}

//功能：打印所有PCB信息
void PrintProQueue(LinkList Q, PCB *pcb)
{
   
}

//功能：当一个进程结束，打印进程信息
void PrintProResult(PCB *pcb)
{
    
}


