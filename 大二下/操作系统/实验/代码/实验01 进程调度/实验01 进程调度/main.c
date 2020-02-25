#include "ProPCB.h"

/****************************
*  实验01: 非抢占式静态优先权	*
*  ① 优先权始终保持不变		*
*  ② 一旦进入CPU便运行到结束	*
*  ③ FCFS只考虑到达时间进CPU	*
*  ④ SPF认为到达时间相同		*
****************************/

int CPUUsedTime = 0;
//输入原始数据
void InputData(LinkList * pPCBdata, PriorityRule PR)
{
    ElemType e = {{0},-1,-1,-1,-1,-1,0,Ready};
    e.ArrivalTime=0;
    e.ProcessState=Ready;
    e.TimeUsedCPU=0;
    strcpy(e.Name,"A");
    e.NeedRunningTime=1;
    e.Priority=GetPriority(&e,PR);
    if(PR==SPF){
        e.ArrivalTime=0;
    }
    GetProcess(*pPCBdata,e);
}



int main(void)
{
    LinkList PCBQueue;
    ElemType e={{0},-1,-1,-1,-1,-1,0,Ready};
    ElemType *pcb = NULL;
    PriorityRule PR;
    PR=FCFS;
    printf("\n进程运行信息如下：\n");
    while(OutProsess(PCBQueue,&e)){
        while(e.TimeUsedCPU<e.NeedRunningTime){
            CPURunPro(PCBQueue,&e);
            ++CPUUsedTime;
        }
        e.FinishTime = CPUUsedTime;
        PrintProResult(&e);
    }

    return 0;
}