#ifndef _MemoryManage_h_
#define _MemoryManage_h_

#include "List.h"

//*****         PCB �� �� �� ��        *****//
Status InsertProcess(LinkList Q,PCBType e);
Status DeleteProsess(LinkList Q,int i,PCBType *e);
//*****         �� �� �� �� ��         *****//
//���������Ԫ��
Status InsertTable_f(SqList_f *L, int i, PartiType e);	
//ɾ��������Ԫ��
Status DeleteTable_f(SqList_f *L, int i, PartiType *e);


//******          ҳ �� �� ��         ******//
//����ҳ��Ԫ��
Status InsertTable_y(SqList_y *L, int i, BlockNumType e);
//ɾ��ҳ��Ԫ��
Status DeleteTable_y(SqList_y *L, int i, BlockNumType *e);
Status LoadPages(PageTable *L, int size);
Status MallocMemory(PCB *pe, SqList_f *pPartTable, int *arr,int *pagenumArr);
//Status MallocMemory(PCB *pe, SqList_f *pPartTable, int *arr);
Status SelectPart(PCB* pPCB, SqList_f *pPartTable,int *arr);
//void SearchSpace(PCBList PCBdata, SqList_f *partTable);
void FreeMemory(int *arr, int len, SqList_f *pPartTable);
void InitAllocation(PCBList PCBdata, PartTable *partTable);
void PrintProQueue(LinkList L);
void PrintPartTable(PartTable L);




#endif