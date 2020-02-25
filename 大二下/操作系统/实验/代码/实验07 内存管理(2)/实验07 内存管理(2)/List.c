#include "List.h"

Status InitLinkList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	strcpy((*L)->data.Name, "");
	(*L)->Next = NULL;
	return OK;
}

void PCBAssign(PCBType *e1, PCBType e2)
{
	strcpy(e1->Name,e2.Name);
	e1->DistbutSt = e2.DistbutSt;
	e1->MemorySize = e2.MemorySize;
	e1->StartAddress = e2.StartAddress;
}

Status GetElemt_L(LinkList L,int i,PCBType *e)
{
	LinkList p = L->Next;	//ָ���j�����
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
	*e = p->data;			//ͨ��Ѱַ�ı��� �õ�ַ�ڴ���Ԫ�ص�ֵ
	return OK;
}
//�����а������ȼ����Ӵ�С�������
Status ListInsert_L(LinkList L,PCBType e)	//�����޸�Ӧ�ò��� p = *L����
{
	LinkList p = L, s;
	while (p->Next)	
		p = p->Next;
	s = (LinkList)malloc(sizeof(LNode));
	PCBAssign(&s->data, e);
	s->Next = p->Next;
	p->Next = s;
	return OK;
}
//������ͷ��ɾ��
Status ListDelete_L(LinkList L,int i,PCBType *e)
{
	LinkList p = L, q;
	int j = 0;
	while (p->Next && j < i-1)
	{
		p = p->Next; ++j;
	}
	if(!p->Next || j > i - 1)
		return ERROR;
	q = p->Next;
	p->Next = q->Next;
	PCBAssign(e, q->data);
	free(q);
	return OK;
}

//////////           ��ʼ��         ///////////
void PartiAssign(PartiType *e1, PartiType e2)
{
	e1->PartitionSize = e2.PartitionSize;
	e1->PartStartAddr = e2.PartStartAddr;
	strcpy(e1->Name, e2.Name);
}

Status InitList_Sq(SqList *L)
{
	//����һ���յ����Ա�L
	L->elem = (PartiType *)malloc((LIST_INIT_SIZE)*sizeof(PartiType));
	if(!L->elem) return ERROR;        //�洢����ʧ��
	L->length = 0;                 //�ձ���Ϊ0
	L->listsize = LIST_INIT_SIZE;  //��ʼ�洢������
	return OK;
}

//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
Status ListInsert_Sq(SqList *L,int i,PartiType e)
{
	//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
	//i�ĺϷ�ֵΪ1 <= i <= ListLength_Sq(L)+1
	PartiType *q, *p, *newbase;

	if(i < 1 || i > L->length + 1 ) return ERROR;     //iֵ���Ϸ�
	if(L->length >= L->listsize){               //��ǰ�洢�ռ����������ӷ���
		newbase = (PartiType *)realloc(L->elem
			,(L->listsize + LISTINCREMENT)*sizeof(PartiType));
		if(!newbase) return ERROR;				//�洢����ʧ��
		L->elem = newbase;						//�»�ַ
		L->listsize += LISTINCREMENT;			//���Ӵ洢����
	} 
	q = &(L->elem[i - 1]);			         	//qΪ����λ��
	for(p = &(L->elem[L->length-1]);p >= q; --p)
		PartiAssign((p+1),*p); 					//����λ�ü�֮���Ԫ������
	PartiAssign(q ,e);							//����e
	L->length++;
	return OK;
}

//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete_Sq(SqList *L,int i,PartiType *e)
{
	//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ1 <= i <= ListLength_Sq(L)
	PartiType *p,*q;
	if((i < 1) || (i > L->length))	
		return ERROR;							 //iֵ���Ϸ�
	p = &(L->elem[i-1]);						 //pΪ��ɾ��Ԫ�ص�λ��
	PartiAssign(e, *p);							 //����ɾ��Ԫ�ص�ֵ����e ��������
	q = L->elem + L->length-1;					 //�ƶ�����βԪ�ص�λ��
	for (++p;p<=q;++p)
		PartiAssign((p-1), *p);					 //��ɾ��Ԫ��֮���Ԫ������
	L->length--;
	return OK;
}

