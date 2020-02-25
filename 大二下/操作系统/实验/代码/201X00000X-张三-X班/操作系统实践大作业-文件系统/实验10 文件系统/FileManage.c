#include "FileManage.h"


void FileOperatInterface(LinkList_U *pUfd)
{
	char FileName[MAX_NAME_SIZE] = {0} ,choice, Pwd1[MAX_NAME_SIZE] = {0}, Pwd2[MAX_NAME_SIZE] = {0};
	int i;
	while(true)
	{
		system("cls");
		printf(" ================================================\n");
		printf("|                 1. �� �� �� ��                 |\n");
		printf("|                 2. ��ʾ�����ļ�                |\n");
		printf("|                 3. д���ļ�����                |\n");
		printf("|                 4. �� �� �� ��                 |\n");
		printf("|                 5. ɾ �� �� ��                 |\n");
		printf("|                 6. �� �� ϵ ͳ                 |\n");
		printf(" ================================================\n");
		printf("��ѡ��:");
		fflush(stdin);
		scanf("%c",&choice);

		switch (choice)
		{
		case '1':
			printf("�������ļ�����");
			scanf("%s", FileName);
			if(CreateFile(pUfd, FileName))
			{
				printf("�ļ������ɹ�!\n");
				break;
			}
			printf("�ļ�����ʧ��!\n");

			break;
		case '2':
			VisitFile(*pUfd);
			break;
		case '3':
			printf("�������ļ�����");
			scanf("%s", FileName);
			if(!AddContent(pUfd ,FileName))
				printf("�ļ�������!\n");
			break;

		case '4':
			printf("�������ļ�����");
			scanf("%s", FileName);
			if(!OpenFile(*pUfd, FileName))
				printf("�ļ�������!\n");

			break;
		case '5':
			printf("�������ļ�����");
			scanf("%s", FileName);
			if(!Delete(pUfd ,FileName))
				printf("�ļ�������!\n");

			break;

		case '6':
			return ;
		default:
			printf("ѡ���������������ѡ��\n");
			break;
		}
		system("pause");
	}

}

Status CreateFile(LinkList_U  *pUfd ,char *fileName)
{
	ElemType_U ele_u = {{0}, NULL};
    ////////////////    ������Ҫ����     ///////////////
	strcpy(ele_u.FileName,fileName);
	ele_u.FileAddress = (FCB*)malloc(sizeof(FCB));
	if(!ele_u.FileAddress)
		return ERROR;
	strcpy(ele_u.FileAddress->FileName,fileName);
	strcpy(ele_u.FileAddress->Content,"");

	ListInsert_U(*pUfd,ele_u);

	return OK;
}

void VisitFile(LinkList_U  Ufd)
{
	LinkList_U p = Ufd->Next;
	////////////////    ������Ҫ����     ///////////////
	while(p)
	{
		printf("%s ",p->data.FileName);
		p = p->Next;
	}
	printf("\n");

}

Status OpenFile(LinkList_U  Ufd ,char *fileName)
{
	LinkList_U p = Ufd->Next;
	////////////////    ������Ҫ����     ///////////////
	while(p && strcmp(p->data.FileName ,fileName))
	{
		p = p->Next;
	}
	if(!p)
		return ERROR;
	printf("%s\n",p->data.FileAddress->Content);

	return OK;
}


Status Delete(LinkList_U  *pUfd ,char *fileName)
{
	ElemType_U ele_u = {{0}, NULL};
	LinkList_U p = (*pUfd)->Next;
	int i = 1;
	////////////////    ������Ҫ����     ///////////////



	return OK;
}

Status AddContent(LinkList_U  *pUfd ,char *fileName)
{
	LinkList_U p = (*pUfd)->Next;
	////////////////    ������Ҫ����     ///////////////



	return OK;
}