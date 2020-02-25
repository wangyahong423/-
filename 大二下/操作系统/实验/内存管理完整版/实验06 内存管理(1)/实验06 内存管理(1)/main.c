#include "MemoryManage.h"

/*ʵ��06 �̶���������
* ������ԣ�
* �������������ܹ�װ��÷����Ľ��̣�
* �������ܹ�װ��÷������Ľ��̡�
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
		printf("|           1.�� �� �� ��                        |\n");
		printf("|           2.�� �� �� ��                        |\n");
		printf("|           3.�� �� ϵ ͳ                        |\n");
		printf(" ================================================\n");
		printf("��ѡ��:");
		fflush(stdin);
		scanf("%c",&choice);
		
		switch (choice)
		{
		///////////   ������Ҫ����    /////////////
		case '1':
			printf("Ҫ�����Ľ�������");
			scanf("%s",PcbName);
			for (i = 1, p = PCBdata->Next; i <= PcbName && strcmp(p->data.Name, PcbName);i++) {
				if (i > PcbName) {
					break;
				}
				DeleteProsess(PCBdata, i, &PCBe);
				for (int j = 0; j < partTable.length; j++) {
					if (!strcmp(partTable.elem[j].Name, PcbName))
					{
						FreeMemory(j, &partTable);
						break;
					}
						
				}
				SearchSpace(PCBdata, partTable);
				break;
			}
			break;

			//PrintProQueue(PCBdata);
			//PrintPartTable(partTable);
			//break;





		case '2':
			printf("Ҫ��ӵĽ�������������ռ�ڴ��С��");
			scanf("%s%d", PcbName,&size);
			strcpy(PCBe.Name, PcbName);
			PCBe.DistbutSt = Unallocated;
			PCBe.MemorySize = size;
			PCBe.StartAddress = 0;
			pos = SelectPart(&PCBe, &partTable);
			if (pos)
				MallocMemory(&PCBe, &partTable, pos - 1);
			InsertProcess(PCBdata, PCBe);//�������

			break;
			

		case '3':
			return 0;


		}
		PrintProQueue(PCBdata);
		PrintPartTable(partTable);
		system("pause");
	}

	return 0;
}