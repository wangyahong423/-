#ifndef _ProPCB_h_
#define _ProPCB_h_

#include "ChainList.h"
//���ܣ�������e��������Q
Status GetProcess(LinkList Q,ElemType e);				//�Ͼ�������

//���ܣ�������Q�е�һ�������������Ϣ����eָ����ڴ沢ɾ��
Status OutProsess(LinkList Q,ElemType *e);				//�¾�������

//���ܣ����м��㷨
Status BankerAlgorithm(int *Allocation, int *Request,int i, int *Need, int *Available);

//���ܣ���ȫ���
Status SecurityCheck(int *Allocation,int *Need, int *Available);

//���ܣ���������Դ�������pos������
Status AllocateResource(LinkList PCBdata , int pos , int *Request);

//���ܣ���PCB��Դ��Ϣ���ɾ���
void GetMatrixData(LinkList PCBdata,int *Max,int *Allocation,int *Need,int *Available);

//���ܣ���ӡ��������Դ��Ϣ
void PrintProQueue(LinkList L, int *A);

//���ܣ��ж��ͷ���Դ�Ϸ���
Status ReleaseAlgorithm(int *Allocation, int *Request, int pos);

//���ܣ��ͷ���Դ
Status ReleaseResource(LinkList PCBdata ,int pos, int *Request);

#endif