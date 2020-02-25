#include "MemoryManage.h"

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
int SelectPart(PCB* pPCB, SqList *pPartTable)
{
	int i,Start;
	if(pPCB->MemorySize <= 16)
		Start = 0;
	else if(pPCB->MemorySize <= 32)
		Start = 1;
	else if(pPCB->MemorySize <= 64)
		Start = 2;
	else if(pPCB->MemorySize <= 128)
		Start = 3;
	else if(pPCB->MemorySize <= 256)
		Start = 4;
	else
	{
		printf("�ڴ�����޷�װ��!\n");
		return ERROR;
	}

	for (i = Start; i < pPartTable->length; ++i)
		if(!strcmp(pPartTable->elem[i].Name, ""))
			return i + 1;
	return ERROR;
}

int MallocMemory(PCB *pe, SqList *pPartTable,int i)
{
	///////////   ������Ҫ����    /////////////

}

void InitAllocation(PCBList PCBdata, PartTable partTable)
{
	///////////   ������Ҫ����    /////////////


}

void FreeMemory(int pos, SqList *pPartTable)
{
	///////////   ������Ҫ����    /////////////


}


void SearchSpace(PCBList PCBdata, SqList partTable)
{
	int pos;
	LNode *p;
	p = PCBdata->Next;
	while (p)
	{
		if(p->data.DistbutSt == Unallocated)
		{
			pos = SelectPart(&(p->data), &partTable);//��1��ʼ
			if(pos)
			{
				MallocMemory(&(p->data), &partTable, pos - 1);
				break;
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