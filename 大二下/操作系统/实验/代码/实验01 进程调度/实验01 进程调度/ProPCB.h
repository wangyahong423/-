#ifndef _ProPCB_h_
#define _ProPCB_h_

#include "ChainList.h"

//���ܣ���e��������Q
Status GetProcess(LinkList Q,ElemType e);		//�Ͼ�������

//���ܣ����ݲ�ͬ�����ȼ����򣬷���������
int GetPriority(ElemType *e, PriorityRule PR);  //���ݲ�ͬ�Ĺ���PR ����������

//���ܣ�������Q��ͷ������ݷŵ�eָ����ڴ棬��ɾ��
Status OutProsess(LinkList Q,ElemType *e);	    //�¾�������

//���ܣ�CPU����pcbָ��Ľ��̣���������н��н���״̬
Status CPURunPro(LinkList Q, PCB *pcb);	        //CPU����PCB

//���ܣ���ӡ����PCB��Ϣ
void PrintProQueue(LinkList Q, PCB *pcb);		//��ӡ���к�PCB��Ϣ

//���ܣ���һ�����̽�������ӡ������Ϣ
void PrintProResult(PCB *pcb);

#endif