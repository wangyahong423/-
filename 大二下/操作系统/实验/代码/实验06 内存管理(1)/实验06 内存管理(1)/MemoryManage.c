#include "MemoryManage.h"

//*****         PCB链表操作        *****//
Status InsertProcess(LinkList Q,PCBType e)
{
	return ListInsert_L(Q, e);
}

Status DeleteProsess(LinkList Q,int i,PCBType *e)
{
	return ListDelete_L(Q ,i,e);
}

//*****         分区表操作        *****//
Status InsertTable(SqList *L, int i, PartiType e) 
{
	return ListInsert_Sq(L,i, e);
}

Status DeleteTable(SqList *L, int i, PartiType *e)
{
	return ListDelete_Sq(L, i, e);
}


//返回第几个内存块，从1开始，若返回0，则代表错误
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
		printf("内存过大，无法装入!\n");
		return ERROR;
	}

	for (i = Start; i < pPartTable->length; ++i)
		if(!strcmp(pPartTable->elem[i].Name, ""))
			return i + 1;
	return ERROR;
}

int MallocMemory(PCB *pe, SqList *pPartTable,int i)
{
	///////////   以下需要补充    /////////////

}

void InitAllocation(PCBList PCBdata, PartTable partTable)
{
	///////////   以下需要补充    /////////////


}

void FreeMemory(int pos, SqList *pPartTable)
{
	///////////   以下需要补充    /////////////


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
			pos = SelectPart(&(p->data), &partTable);//从1开始
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
	printf("|进程名 | 起始位置 | 申请大小 | 是否分配 |\n");
	while(L)
	{
		printf("|  %s   |  %4d    |  %4d    |  %4s    |\n",
			L->data.Name, L->data.StartAddress, L->data.MemorySize, L->data.DistbutSt == Allocated?  "是" : "否");
		L = L->Next;
	}
	printf(" ----------------------------------------\n");
}

void PrintPartTable(PartTable L)
{
	int i = 0, j = 0;
	printf(" ----------------------------------------\n");
	printf("|分区号 | 起始位置 | 分区大小 | 是否分配 |\n");
	for (i = 0; i < L.length; ++i)
		printf("|  %2d   |  %4d    |  %4d    |  %4s    |\n",
			i + 1 , L.elem[i].PartStartAddr, L.elem[i].PartitionSize , strcmp(L.elem[i].Name, "") ? L.elem[i].Name :"否");
	printf(" ----------------------------------------\n");
}