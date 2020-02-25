#ifndef _ProPCB_h_
#define _ProPCB_h_

#include "ChainList.h"

Status GetProcess(LinkList Q,ElemType e);				//�Ͼ�������
Status CPURunPro(LinkList Q,PCB *pcb,PriorityRule PR);	//CPU����PCB
Status OutProsess(LinkList Q,ElemType *e);				//�¾�������
double GetPriority(ElemType *e, PriorityRule PR);			//���ݲ�ͬ�Ĺ���PR ����������
Status AddWaitTime(LinkList Q);							//δ��CPU�Ľ��̵����ӵȴ�ʱ��
void PrintProQueue(LinkList Q, PCB *pcb);				//��ӡ���к�PCB��Ϣ
void PrintProResult(PCB *pcb);

#endif