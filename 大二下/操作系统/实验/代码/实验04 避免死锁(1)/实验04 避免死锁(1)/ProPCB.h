#ifndef _ProPCB_h_
#define _ProPCB_h_

#include "ChainList.h"
//�϶���
Status GetProcess(LinkList Q,ElemType e);		
//���м��㷨
Status BankerAlgorithm(int *Allocation, int *Request,int i, int *Need, int *Available);
//��ȫ�Լ���㷨
Status SecurityCheck(int *Allocation,int *Need, int *Available);
//������Դ
Status AllocateResource(LinkList PCBdata , int pos , int *Request);
//��ȡ��Դ����
void GetMatrixData(LinkList PCBdata,int *Max,int *Allocation,int *Need,int *Available);
//��ӡ������Դ��Ϣ
void PrintProQueue(LinkList L, int *A);


#endif