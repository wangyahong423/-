#include "MemoryManage.h"

/*   ʵ��08  ������ҳ   */

void InputPCBData(PCBList * pPCBdata)
{
	PCBType e = {{0}, 0, NULL};
    
	strcpy(e.Name,"P1");
	e.MemorySize = 16;
    InitList_y(&(e.pPagetable));
    LoadPages(e.pPagetable, e.MemorySize);
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P2");
	e.MemorySize = 32;
    InitList_y(&(e.pPagetable));
    LoadPages(e.pPagetable, e.MemorySize);
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P3");
	e.MemorySize = 48;
    InitList_y(&(e.pPagetable));
    LoadPages(e.pPagetable, e.MemorySize);
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P4");
	e.MemorySize = 96;
    InitList_y(&(e.pPagetable));
    LoadPages(e.pPagetable, e.MemorySize);
	InsertProcess(*pPCBdata,e);

	strcpy(e.Name,"P5");
	e.MemorySize = 100;
    InitList_y(&(e.pPagetable));
    LoadPages(e.pPagetable, e.MemorySize);
	InsertProcess(*pPCBdata,e);
}

void SettingPage(PartTable * pPartdata)
{
	PartiType se = {0, {0}};
	int Num = (512 - 16) / PageSize , i;
	for (i = 0; i < Num; ++i)
	{
		se.PartStartAddr = 16 + i * PageSize;
		InsertTable_f(pPartdata, i + 1, se);
	}
}
//0 - 15Kb ����ϵͳռ��  �ܴ�С512KB
int main(void)
{
	PCBList PCBdata;		//PCBdata������ԭʼPCB����
	PartTable partTable;	//������
	char PcbName[NAME_MAXSIZE] = {0}, choice;
	PCBType PCBe = {{0}, 0, NULL};
	PartiType Parte = {0, 0};
	PCBType *pcb = NULL;
	LNode *p; 
	
    int i, size, pos, arr[20] = {0}, k = 0;

	InitList_f(&partTable);
	SettingPage(&partTable);
	InitLinkList(&PCBdata);
	InputPCBData(&PCBdata);
	InitAllocation(PCBdata, &partTable);

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
            k = 0;
			for(i = 0; i < partTable.length; i++)
			{
				if(!strcmp(PcbName, partTable.elem[i].Name))
				{
					arr[k++] = i;
				}
			}
            FreeMemory(arr, k, &partTable);

			SearchSpace(PCBdata, &partTable);
			break;
		case '2':
			printf("��������ӵĽ�������������ռ�ڴ��С:");
			scanf("%s%d",PcbName , &size);
			strcpy(PCBe.Name, PcbName);
			PCBe.MemorySize = size;
            InitList_y(&(PCBe.pPagetable));
            LoadPages(PCBe.pPagetable, PCBe.MemorySize);
			if(SelectPart(&(PCBe), &partTable, arr))
				MallocMemory(&(PCBe), &partTable, arr);
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