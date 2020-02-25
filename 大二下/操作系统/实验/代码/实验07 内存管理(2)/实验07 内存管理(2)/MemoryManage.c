#include "MemoryManage.h"
extern int CF_i;

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
		////////////     以下补充   /////////////



	}else if(AS == CycleFirst)
	{
		////////////     以下补充   /////////////




	}else
	{
		printf("算法选择有误！\n");
	}
	return ERROR;
}

int MallocMemory(PCB *pe, SqList *pPartTable,int i)
{
	PartiType se = {0, 0, {0}};
	////////////     以下补充   /////////////



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
			pos = SelectPart(&(p->data), pPartTable, AS);//从1开始
			if(pos)
			{
				MallocMemory( &(p->data), pPartTable, pos - 1);
			}
		}
		p = p->Next;
	}
}

void FreeMemory(int pos, SqList *pPartTable)//没考虑  pos为0情况，没考虑删除后修改起始地址情况
{
	PartiType se = {0, 0, {0}};
	////////////     以下补充   /////////////



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
			pos = SelectPart(&(p->data), partTable, AS);//从1开始
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