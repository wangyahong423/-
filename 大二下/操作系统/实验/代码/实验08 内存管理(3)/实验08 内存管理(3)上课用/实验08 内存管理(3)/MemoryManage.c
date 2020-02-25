
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
Status InsertTable_f(SqList_f *L, int i, PartiType e) 
{
	return ListInsert_f(L,i, e);
}

Status DeleteTable_f(SqList_f *L, int i, PartiType *e)
{
	return ListDelete_f(L, i, e);
}

//*****         页表操作        *****//
Status InsertTable_y(SqList_y *L, int i, BlockNumType e)
{
	return ListInsert_y(L,i, e);
}

Status DeleteTable_y(SqList_y *L, int i, BlockNumType *e)
{
	return ListDelete_y(L, i, e);
}

Status LoadPages(PageTable *L, int size)
{
    int i, pageNum = ceil( size * 1.0 / PageSize) ;
    PageData e = {-1, Unallocated};
    for (i = 0; i < pageNum; i++)
    {
        if(!InsertTable_y(L, L->length + 1, e))
            return ERROR;
    }
    return OK;;
}



//若返回0，则代表错误
Status SelectPart(PCB* pPCB, SqList_f *pPartTable,int *arr)
{
	/////////////     以下补充     /////////////
    
    return ERROR;
}

Status MallocMemory(PCB *pe, SqList_f *pPartTable, int *arr)
{
    int i, pageNum ;
   
	////////////      以下补充     /////////////
   
	return ERROR;
}

void InitAllocation(PCBList PCBdata, PartTable *pPartTable)
{
	LNode *p;
    int pos, arr[20] = {0};
	p = PCBdata->Next;
	while (p)
	{
		if(p->data.pPagetable->elem[0].DistbutSt == Unallocated)
		{
			if(SelectPart(&(p->data), pPartTable, arr))
			{
				MallocMemory(&(p->data), pPartTable, arr);
			}
		}
		p = p->Next;
	}
}

//该释放进程只在结束进程时用到，因此不用管进程信息
void FreeMemory(int *arr, int len, SqList_f *pPartTable)
{
    int i;
	////////////     以下补充   /////////////
   
}

void SearchSpace(PCBList PCBdata, SqList_f *partTable)
{
    int pos, arr[20] = {0};
	LNode *p;
	p = PCBdata->Next;
	while (p)
	{
		if(p->data.pPagetable->elem[0].DistbutSt == Unallocated)
		{
			if(SelectPart(&(p->data), partTable, arr))
			{
				MallocMemory(&(p->data), partTable, arr);
			}
		}
		p = p->Next;
	}

}

void PrintProQueue(LinkList L)
{
	int i = 0;

	L = L->Next;
	
	while(L)
	{
        printf(" -----------------------------\n");
        printf("|进程名 | 申请大小 |\n");
        printf("|  %s   |  %4d    |\n", L->data.Name, L->data.MemorySize);

            printf("%s页表信息如下：\n|   页号   |   块号   | 是否分配 |\n", L->data.Name);
            for (i = 0; i < L->data.pPagetable->length; i++)
                printf("|  %4d    |  %4d    |  %4s    |\n", i , L->data.pPagetable->elem[i].BlockNum,
                        L->data.pPagetable->elem[i].DistbutSt == Allocated?  "是" : "否");
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
			i , L.elem[i].PartStartAddr, PageSize , strcmp(L.elem[i].Name, "") ? L.elem[i].Name :"否");
	printf(" ----------------------------------------\n");
}