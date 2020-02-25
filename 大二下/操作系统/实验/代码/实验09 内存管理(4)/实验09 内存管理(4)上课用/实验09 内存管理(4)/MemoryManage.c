
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
Status InsertTable_f(SqList_f *L, int i, PartiType e) 
{
	return ListInsert_f(L,i, e);
}

Status DeleteTable_f(SqList_f *L, int i, PartiType *e)
{
	return ListDelete_f(L, i, e);
}

//*****         ҳ�����        *****//
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
    return OK;
}



//������0����������
Status SelectPart(PCB* pPCB, SqList_f *pPartTable,int *arr)
{
     int pageNum = 0, i, k = 0;
	/////////////     ���²���     /////////////
   

	
    return ERROR;
}

Status MallocMemory(PCB *pe, SqList_f *pPartTable, int *arr,int *pagenumArr)
{
    int i, pageNum = pe->PagesLoadedNum ;
	////////////      ���²���     /////////////
    
  
    return ERROR;
}

void InitAllocation(PCBList PCBdata, PartTable *pPartTable)
{
	LNode *p;
    int i, arr[20] = {0}, pagenumArr[PageArrLength] = {0};
	p = PCBdata->Next;
    
	while (p)
	{
        for (i = 0; i < ceil(p->data.MemorySize * 1.0 / PageSize) ; i++){
            pagenumArr[i] = i;
        }
        p->data.PagesLoadedNum = i;
		if(p->data.pPagetable->elem[0].DistbutSt == Unallocated)
		{
			if(SelectPart(&(p->data), pPartTable, arr))
			{
				MallocMemory(&(p->data), pPartTable, arr, pagenumArr);
			}
		}
		p = p->Next;
	}
}

//���ͷŽ���ֻ�ڽ�������ʱ�õ�����˲��ùܽ�����Ϣ
void FreeMemory(int *arr, int len, SqList_f *pPartTable)
{
    int i;
	////////////     ���²���   /////////////
  
}


void PrintProQueue(LinkList L)
{
	int i = 0;

	L = L->Next;
	
	while(L)
	{
        printf(" -----------------------------\n");
        printf("|������ | �����С |\n");
        printf("|  %s   |  %4d    |\n", L->data.Name, L->data.MemorySize);

            printf("%sҳ����Ϣ���£�\n|   ҳ��   |   ���   | �Ƿ���� |\n", L->data.Name);
            for (i = 0; i < L->data.pPagetable->length; i++)
                printf("|  %4d    |  %4d    |  %4s    |\n", i , L->data.pPagetable->elem[i].BlockNum,
                        L->data.pPagetable->elem[i].DistbutSt == Allocated?  "��" : "��");
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
			i , L.elem[i].PartStartAddr, PageSize , strcmp(L.elem[i].Name, "") ? L.elem[i].Name :"��");
	printf(" ----------------------------------------\n");
}