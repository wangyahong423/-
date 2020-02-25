#include "ProPCB.h"

/****************************
*  ʵ��01: ����ռʽ��̬����Ȩ	*
*  �� ����Ȩʼ�ձ��ֲ���		*
*  �� һ������CPU�����е�����	*
*  �� FCFSֻ���ǵ���ʱ���CPU	*
*  �� SPF��Ϊ����ʱ����ͬ		*
****************************/

int CPUUsedTime = 0;
//����ԭʼ����
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
    printf("\n����������Ϣ���£�\n");
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