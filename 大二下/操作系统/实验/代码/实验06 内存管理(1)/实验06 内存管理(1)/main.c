#include "MemoryManage.h"

/*实验06 固定分区分配
* 分配策略：
* ①离队首最近，能够装入该分区的进程；
* ②搜索能够装入该分区最大的进程。
*/

void InputPCBData(PCBList * pPCBdata)
{
	PCBType e = {{0}, 0, 0, Unallocated};
	strcpy(e.Name,"P1");
	e.MemorySize = 16;
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P2");
	e.MemorySize = 32;
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P3");
	e.MemorySize = 48;
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P4");
	e.MemorySize = 96;
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P5");
	e.MemorySize = 100;
	InsertProcess(*pPCBdata,e);
}

void SetFixedZone(PartTable * pPartdata)
{
	PartiType se = {0, 0, Unallocated };
	se.PartStartAddr = 16;
	se.PartitionSize = 16;
	InsertTable(pPartdata, 1, se);

	se.PartStartAddr = 32;
	se.PartitionSize = 32;
	InsertTable(pPartdata, 2, se);

	se.PartStartAddr = 64;
	se.PartitionSize = 64;
	InsertTable(pPartdata, 3, se);

	se.PartStartAddr = 128;
	se.PartitionSize = 128;
	InsertTable(pPartdata, 4, se);

	se.PartStartAddr = 256;
	se.PartitionSize = 256;
	InsertTable(pPartdata, 5, se);

}
//0 - 15Kb 操作系统占用  总大小512KB
int main(void)
{
	PCBList PCBdata;		//PCBdata里面存放原始PCB数据
	PartTable partTable;	//分区表
	char PcbName[NAME_MAXSIZE] = {0}, choice;
	PCBType PCBe = {{0}, 0, 0, Unallocated};
	PartiType Parte = {0, 0};
	PCBType *pcb = NULL;
	LNode *p; 
	int i, size, pos;

	InitList_Sq(&partTable);
	SetFixedZone(&partTable);
	InitLinkList(&PCBdata);
	InputPCBData(&PCBdata);
	InitAllocation(PCBdata, partTable);

	PrintProQueue(PCBdata);
	PrintPartTable(partTable);
	
	while(true)
	{
		system("cls");
		PrintProQueue(PCBdata);
		PrintPartTable(partTable);
		printf(" ================================================\n");
		printf("|           1.结 束 进 程                        |\n");
		printf("|           2.添 加 进 程                        |\n");
		printf("|           3.退 出 系 统                        |\n");
		printf(" ================================================\n");
		printf("请选择:");
		fflush(stdin);
		scanf("%c",&choice);
		
		switch (choice)
		{
		///////////   以下需要补充    /////////////


		}
		PrintProQueue(PCBdata);
		PrintPartTable(partTable);
		system("pause");
	}

	return 0;
}