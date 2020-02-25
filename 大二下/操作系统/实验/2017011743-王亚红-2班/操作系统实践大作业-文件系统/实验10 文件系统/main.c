#include "FileManage.h"

/*ʵ��10 �ļ�ϵͳ  *
*   �����ļ�Ŀ¼   */


int main(void)
{
	RootList Root, p = NULL;
	ElemType_R ele_r = {{0}, {0}, NULL};
	UFDList Ufd;
	ElemType_U ele_u = {{0}, NULL};
	char UserName[MAX_NAME_SIZE] = {0} ,choice, Pwd1[MAX_NAME_SIZE] = {0}, Pwd2[MAX_NAME_SIZE] = {0};
	int i;

	InitLinkList_R(&Root);
	
	while(true)
	{
		system("cls");
		printf(" ================================================\n");
		printf("|           1. �� �� �� ��                        |\n");
		printf("|           2. �� �� �� ¼                        |\n");
		printf("|           3. �� �� ϵ ͳ                        |\n");
		printf(" ================================================\n");
		printf("��ѡ��:");
		fflush(stdin);
		scanf("%c",&choice);
		
		switch (choice)
		{
		case '1':
			printf("�����봴�����û�����");
			scanf("%s",UserName);
			printf("���������룺");
			scanf("%s",Pwd1);
			printf("���ٴ��������룺");
			scanf("%s",Pwd2);
			if(strcmp(Pwd1, Pwd2))
			{
				printf("��������һ��һ�£�\n");
				break;
			}
			
			strcpy(ele_r.UserName, UserName);
			strcpy(ele_r.UserPWD, Pwd1);
			InitLinkList_U(&(ele_r.UserFileList));
			
			ListInsert_R(Root, ele_r);
			printf("�����û��ɹ���\n");
			break;
		case '2':
			printf("�������û�����");
			scanf("%s",UserName);
			p = Root->Next;
			while (p && strcmp(p->data.UserName, UserName)){
				p = p->Next;
			}
			if(!p){
				printf("�û���������!\n");
				break;
			}
			printf("���������룺");
			scanf("%s",Pwd1);
			if(strcmp(p->data.UserPWD, Pwd1)){
				printf("��������!\n");
				break;
			}
			
			FileOperatInterface(&(p->data.UserFileList));

			return ;
		case '3':
			return ;

		default:
			printf("ѡ���������������ѡ��\n");
			break;
		}
		system("pause");
	}

	return 0;
}