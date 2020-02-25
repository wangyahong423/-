#include "MemoryManage.h"
extern int CF_i;

//*****         PCB�������        *****//
Status InsertProcess(LinkList Q,PCBType e)
{
	return ListInsert_L(Q, e);
}

Status DeleteProsess(LinkList Q,int i,PCBType *e)
{
	return ListDelete_L(Q ,i,e);
}

//*****         ���������        *****//
Status InsertTable(SqList *L, int i, PartiType e) 
{
	return ListInsert_Sq(L,i, e);
}

Status DeleteTable(SqList *L, int i, PartiType *e)
{
	return ListDelete_Sq(L, i, e);
}


//���صڼ����ڴ�飬��1��ʼ��������0����������
int SelectPart(PCB* pPCB, SqList *pPartTable,AllocatStrategy AS)
{
	int i;
	int BestArr[20] = {0}, k = 0, min = 500, min_i = -1;

	if(AS == FirstPriority)
	{
		for (i = 0; i < pPartTable->length; ++i)
			if(!strcmp(pPartTable->elem[i].Name, "") && pPartTable->elem[i].PartitionSize >= pPCB->MemorySize)
				return i + 1;
	}else if(AS == BestAdapt)
	{
		////////////     ���²���   /////////////



	}else if(AS == CycleFirst)
	{
		////////////     ���²���   /////////////




	}else
	{
		printf("�㷨ѡ������\n");
	}
	return ERROR;
}

int MallocMemory(PCB *pe, SqList *pPartTable,int i)
{
	PartiType se = {0, 0, {0}};
	////////////     ���²���   /////////////



	return OK;
}

void InitAllocation(PCBList PCBdata, PartTable *pPartTable,AllocatStrategy AS)
{
	LNode *p;
	int pos;
	p = PCBdata->Next;
	while (p)
	{
		if(p->data.DistbutSt == Unallocated)
		{
			pos = SelectPart(&(p->data), pPartTable, AS);//��1��ʼ
			if(pos)
			{
				MallocMemory( &(p->data), pPartTable, pos - 1);
			}
		}
		p = p->Next;
	}
}

void FreeMemory(int pos, SqList *pPartTable)//û����  posΪ0�����û����ɾ�����޸���ʼ��ַ���
{
	PartiType se = {0, 0, {0}};
	////////////     ���²���   /////////////



}

void SearchSpace(PCBList PCBdata, SqList *partTable, AllocatStrategy AS)
{
	int pos;
	LNode *p;
	p = PCBdata->Next;
	while (p)
	{
		if(p->data.DistbutSt == Unallocated)
		{
			pos = SelectPart(&(p->data), partTable, AS);//��1��ʼ
			if(pos)
			{
				MallocMemory(&(p->data), partTable, pos - 1);
			}
		}
		p = p->Next;
	}

}

void PrintProQueue(LinkList L)
{
	int i = 0;
	L = L->Next;
	printf(" ----------------------------------------\n");
	printf("|������ | ��ʼλ�� | �����С | �Ƿ���� |\n");
	while(L)
	{
		printf("|  %s   |  %4d    |  %4d    |  %4s    |\n",
			L->data.Name, L->data.StartAddress, L->data.MemorySize, L->data.DistbutSt == Allocated?  "��" : "��");
		L = L->Next;
	}
	printf(" ----------------------------------------\n");
}

void PrintPartTable(PartTable L)
{
	int i = 0, j = 0;
	printf(" ----------------------------------------\n");
	printf("|������ | ��ʼλ�� | ������С | �Ƿ���� |\n");
	for (i = 0; i < L.length; ++i)
		printf("|  %2d   |  %4d    |  %4d    |  %4s    |\n",
			i + 1 , L.elem[i].PartStartAddr, L.elem[i].PartitionSize , strcmp(L.elem[i].Name, "") ? L.elem[i].Name :"��");
	printf(" ----------------------------------------\n");
}