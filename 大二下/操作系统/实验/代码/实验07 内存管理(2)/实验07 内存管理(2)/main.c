#include "MemoryManage.h"

/*ʵ��06 �̶���������
* ������ԣ�
* �������������ܹ�װ��÷����Ľ��̣�
* �������ܹ�װ��÷������Ľ��̡�
*/

int CF_i;

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
	PartiType se = {0, 0, {0}};
	se.PartStartAddr = 16;
	se.PartitionSize = 512 - 16;
	strcpy(se.Name, "");
	InsertTable(pPartdata, 1, se);
}
//0 - 15Kb ����ϵͳռ��  �ܴ�С512KB
int main(void)
{
	PCBList PCBdata;		//PCBdata������ԭʼPCB����
	PartTable partTable;	//������
	char PcbName[NAME_MAXSIZE] = {0}, choice;
	PCBType PCBe = {{0}, 0, 0, Unallocated};
	PartiType Parte = {0, 0};
	PCBType *pcb = NULL;
	LNode *p; 
	AllocatStrategy AS = CycleFirst; //FirstPriority, BestAdapt, CycleFirst
	int i, size, pos;

	InitList_Sq(&partTable);
	SetFixedZone(&partTable);
	InitLinkList(&PCBdata);
	InputPCBData(&PCBdata);
	InitAllocation(PCBdata, &partTable, AS);

	PrintProQueue(PCBdata);
	PrintPartTable(partTable);
	
	while(true)
	{
		system("cls");
		PrintProQueue(PCBdata);
		PrintPartTable(partTable);
		printf(" ================================================\n");
		printf("|           1.�� �� �� ��                        |\n");
		printf("|           2.�� �� �� ��                        |\n");
		printf("|           3.�� �� ϵ ͳ                        |\n");
		printf(" ================================================\n");
		printf("��ѡ��:");
		fflush(stdin);
		scanf("%c",&choice);
		
		switch (choice)
		{
		case '1':
			printf("Ҫ�����Ľ�����:");
			scanf("%s",PcbName);
			for (p = PCBdata->Next, i = 1; p && strcmp(PcbName, p->data.Name); i++, p = p->Next);
			if(!p)
			{
				printf("�������������!\n");
				break;
			}
			DeleteProsess(PCBdata, i, &PCBe);
			for(i = 0; i < partTable.length; i++)
			{
				if(!strcmp(PcbName, partTable.elem[i].Name))
				{
					FreeMemory(i ,&partTable);
					break;
				}
			}

			SearchSpace( PCBdata, &partTable, AS);
			break;
		case '2':
			printf("��������ӵĽ�������������ռ�ڴ��С:");
			scanf("%s%d",PcbName , &size);
			PCBe.DistbutSt = Unallocated;
			PCBe.StartAddress = 0;
			strcpy(PCBe.Name, PcbName);
			PCBe.MemorySize = size;
			pos = SelectPart(&(PCBe), &partTable, AS);//��1��ʼ
			if(pos)
				MallocMemory(&(PCBe), &partTable, pos - 1);
			InsertProcess(PCBdata, PCBe);
			break;
		case '3':
			return 0;

		default:
			printf("ѡ���������������ѡ��\n");
			break;
		}
		PrintProQueue(PCBdata);
		PrintPartTable(partTable);
		system("pause");
	}

	return 0;
}