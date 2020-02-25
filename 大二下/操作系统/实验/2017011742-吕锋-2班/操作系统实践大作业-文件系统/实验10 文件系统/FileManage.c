#include "FileManage.h"


void FileOperatInterface(LinkList_U *pUfd)
{
	char FileName[MAX_NAME_SIZE] = {0} ,choice, Pwd1[MAX_NAME_SIZE] = {0}, Pwd2[MAX_NAME_SIZE] = {0};
	int i;
	while(true)
	{
		system("cls");
		printf(" ================================================\n");
		printf("|                 1. 新 建 文 件                 |\n");
		printf("|                 2. 显示所有文件                |\n");
		printf("|                 3. 写入文件内容                |\n");
		printf("|                 4. 打 开 文 件                 |\n");
		printf("|                 5. 删 除 文 件                 |\n");
		printf("|                 6. 退 出 系 统                 |\n");
		printf(" ================================================\n");
		printf("请选择:");
		fflush(stdin);
		scanf("%c",&choice);

		switch (choice)
		{
		case '1':
			printf("请输入文件名：");
			scanf("%s", FileName);
			if(CreateFile(pUfd, FileName))
			{
				printf("文件创建成功!\n");
				break;
			}
			printf("文件创建失败!\n");

			break;
		case '2':
			VisitFile(*pUfd);
			break;
		case '3':
			printf("请输入文件名：");
			scanf("%s", FileName);
			if(!AddContent(pUfd ,FileName))
				printf("文件不存在!\n");
			break;

		case '4':
			printf("请输入文件名：");
			scanf("%s", FileName);
			if(!OpenFile(*pUfd, FileName))
				printf("文件不存在!\n");

			break;
		case '5':
			printf("请输入文件名：");
			scanf("%s", FileName);
			if(!Delete(pUfd ,FileName))
				printf("文件不存在!\n");

			break;

		case '6':
			return ;
		default:
			printf("选择项输入错误，重新选择！\n");
			break;
		}
		system("pause");
	}

}

Status CreateFile(LinkList_U  *pUfd ,char *fileName)//pUfd代表的是目录
{
	ElemType_U ele_u = {{0}, NULL};
	//LinkList_U p = (*pUfd)->Next;//指向头结点的指针
    ////////////////    以下需要补充     ///////////////
	strcpy(ele_u.FileName, fileName);
	ele_u.FileAddress = (FCB*)malloc(sizeof(FCB));
	if (!ele_u.FileAddress)
		return ERROR;
	strcpy(ele_u.FileAddress->FileName, fileName);
	strcpy(ele_u.FileAddress->Content, "");

	ListInsert_U(*pUfd, ele_u);


	return OK;
}

void VisitFile(LinkList_U  Ufd)//访问目录下的所有文件，遍历文件名;遍历单链表；找到data域打印
{
	LinkList_U p = Ufd->Next;
	////////////////    以下需要补充     ///////////////
	while (p) {
		printf("%s ", p->data.FileName);
		p = p->Next;
	}
	printf("\n");
}

Status OpenFile(LinkList_U  Ufd ,char *fileName)//打开文件，fileName要打开文件的文件名；Ufd是目录
{
	LinkList_U p = Ufd->Next;
	////////////////    以下需要补充     ///////////////
	while (p && strcmp(p->data.FileName, fileName))
	{
		p = p->Next;
	}
	if (!p) {
		return ERROR;
	}
	printf("%s\n", p->data.FileAddress->Content);


	return OK;
}

Status Delete(LinkList_U  *pUfd ,char *fileName)//删除链表中的一个节点
{
	ElemType_U ele_u = {{0}, NULL};
	LinkList_U p = (*pUfd)->Next;
	int i = 1;
	////////////////    以下需要补充     ///////////////
	while (p)
	{
		if (strcmp(p->data.FileName, fileName) == 0)
		{
			break;
		}
		p = p->Next;
		i++;	
	}
	if (!p) {
		return ERROR;
	}
	ListDelete_U(*pUfd,i, &ele_u);
	return OK;
}

Status AddContent(LinkList_U  *pUfd ,char *fileName)//写入
{
	LinkList_U p = (*pUfd)->Next;
	char content[MAX_CONTENT_SIZE] = { 0 };
	////////////////    以下需要补充     ///////////////
	while (p)
	{
		if(strcmp(p->data.FileName, fileName) == 0)
		{
			printf("请输入写入的内容:");
			scanf("%s",content);
			strcpy(p->data.FileAddress->Content, content);
			printf("写入成功！");
			return OK;
		}
		else
		{
			p = p->Next;
		}
	}
	return ERROR;
}