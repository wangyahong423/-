#include "List.h"



//*******           ��Ŀ¼����            *******//
Status InitLinkList_R(LinkList_R *L)
{
	*L = (LinkList_R)malloc(sizeof(RNode));
	strcpy((*L)->data.UserName, "");
	(*L)->Next = NULL;
	return OK;
}

void RElemAssign_R(ElemType_R *e1, ElemType_R e2)
{
	strcpy(e1->UserName,e2.UserName);
	strcpy(e1->UserPWD,e2.UserPWD);
	e1->UserFileList = e2.UserFileList;
}

Status GetElemt_R(LinkList_R L,int i,ElemType_R *e)
{
	LinkList_R p = L->Next;	//ָ���j�����
	int j = 1;				//�ӵ�һ����ʼ������
	while ( p && j < i )	//p��Ϊ����j < i
	{
		p = p->Next;
		++j;
	}						//pΪ�գ�˵������ѭ��������Ҳû�е���i�����   j==i
	if (!p || j > i)		//��Ϊ�˴���i   û�����ж�   ��� i==0  �� ����  ��������
							//���� i == j == 1 ���������ѭ������  ����
	{
		return ERROR;
	}
	RElemAssign_R(e , p->data);	//ͨ��Ѱַ�ı��� �õ�ַ�ڴ���Ԫ�ص�ֵ
		
	return OK;
}

Status ListInsert_R(LinkList_R L,ElemType_R e)	 
{
	LinkList_R p = L, s;
	while (p->Next)	
		p = p->Next;
	s = (LinkList_R)malloc(sizeof(RNode));
	RElemAssign_R(&(s->data), e);
	s->Next = p->Next;
	p->Next = s;
	return OK;
}
//������ͷ��ɾ��
Status ListDelete_R(LinkList_R L,int i,ElemType_R *e)
{
	LinkList_R p = L, q;
	int j = 0;
	while (p->Next && j < i-1)
	{
		p = p->Next; ++j;
	}
	if(!p->Next || j > i - 1)
		return ERROR;
	q = p->Next;
	p->Next = q->Next;
	RElemAssign_R(e, q->data);
	free(q);
	return OK;
}

//******         �û�Ŀ¼����           ******//

Status InitLinkList_U(LinkList_U *L)
{
	*L = (LinkList_U)malloc(sizeof(UNode));
	strcpy((*L)->data.FileName, "");
	(*L)->data.FileAddress = NULL;
	(*L)->Next = NULL;
	return OK;
}

void RElemAssign_U(ElemType_U *e1, ElemType_U e2)
{
	strcpy(e1->FileName,e2.FileName);
	e1->FileAddress = e2.FileAddress;
}

Status GetElemt_U(LinkList_U L,int i,ElemType_U *e)
{
	LinkList_U p = L->Next;	//ָ���j�����
	int j = 1;				//�ӵ�һ����ʼ������
	while ( p && j < i )	//p��Ϊ����j < i
	{
		p = p->Next;
		++j;
	}						//pΪ�գ�˵������ѭ��������Ҳû�е���i�����   j==i
	if (!p || j > i)		//��Ϊ�˴���i   û�����ж�   ��� i==0  �� ����  ��������
							//���� i == j == 1 ���������ѭ������  ����
	{
		return ERROR;
	}
	RElemAssign_U(e , p->data);	//ͨ��Ѱַ�ı��� �õ�ַ�ڴ���Ԫ�ص�ֵ
		
	return OK;
}
//�����а������ȼ����Ӵ�С�������
Status ListInsert_U(LinkList_U L,ElemType_U e)	//�����޸�Ӧ�ò��� p = *L����
{
	LinkList_U p = L, s;
	while (p->Next)	
		p = p->Next;
	s = (LinkList_U)malloc(sizeof(UNode));
	RElemAssign_U(&(s->data), e);
	s->Next = p->Next;
	p->Next = s;
	return OK;
}
//������ͷ��ɾ��
Status ListDelete_U(LinkList_U L,int i,ElemType_U *e)
{
	LinkList_U p = L, q;
	int j = 0;
	while (p->Next && j < i-1)
	{
		p = p->Next; ++j;
	}
	if(!p->Next || j > i - 1)
		return ERROR;
	q = p->Next;
	p->Next = q->Next;
	RElemAssign_U(e, q->data);
	free(q);
	return OK;
}

