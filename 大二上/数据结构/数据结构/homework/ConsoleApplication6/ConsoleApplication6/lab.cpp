//������������4_1 �����ж�
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
/*
Status LibsysString��char *ch��{
	Queue q;
	if(!InitQueue(q)){
	 return 0;
	}
	Stack s;
	InitStack(s);
	ElemType e1,e2;
	while(*ch){
		Push(s * ch);
		EnQueue(q * ch);
		p++;
	}
	while(!StackEmpty(s)){
		Pop(s * e1);
		DeQueue(q *e2);
		if(e1 != e2)
		return False;
	}
	return OK;
}*/










#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct{
    char Stack[MAXSIZE];
    int top;
}SqStack; //����ջ

typedef struct{
    char Queue[MAXSIZE];
    int front;
    int rear;
}LinkQueue; //�������

//��ʼ��ջ
void InitStack(SqStack *S){
    S->top=0;
}
//�ж�ջ�Ƿ��    
int EmptyStack(SqStack *S){
    if(S->top==0) //ջ��Ϊ��
    {
        return 0;
    }
    else{
        return 1;
    }
} 
//��ջ
int Push(SqStack *S,char x){
    if(S->top==MAXSIZE) //ջ��
    {
        return 0;
    }
    else //ջδ��
    {
        S->top=S->top+1; //ջ������
        S->Stack[S->top]=x; //�ַ���ջ
        return 1;
    }
} 
//��ջ
char Pop(SqStack *S){
    char y;
    if(S->top==0) //ջΪ��
    {
        return 0; //���ؿո�
    }
    else //ջ��Ϊ��
    {
        y=S->Stack[S->top]; //ȡ��ջ��Ԫ��
        S->top=S->top-1; //ջ��ָʾ�ƶ�
        return 1;
    }
} 
 //��ʼ��
void InitQueue(LinkQueue *Q){
    Q->front=0;
    Q->rear=0;
}
//�ж϶����Ƿ�Ϊ��
int EmptyQueue(LinkQueue *Q){
    if(Q->front==Q->rear) //��ͷ�Ͷ�β���
    {
        return 0;
    }
    else{
        return 1;
    }
} 
//���
int EnQueue(LinkQueue *Q,char e){
    if((Q->rear+1) % MAXSIZE == Q->front) //��������
    {
        return 0;
    }
    else{
        Q->Queue[Q->rear]=e;
        Q->rear=(Q->rear+1) % MAXSIZE;
        return 1;
    }
}
//����
char DeQueue(LinkQueue *Q){
    char f;
    if(Q->front==Q->rear) //����Ϊ��
    {
        return 0;
    }
    else{
        f=Q->Queue[Q->front]; 
        Q->front=(Q->front+1) % MAXSIZE;
        return 1;
    }
} 

void main()
{
    char ch;
    int a=0;
    SqStack *S=(SqStack *)malloc(sizeof(SqStack)); //Ϊ˳��ջ����ռ�
    LinkQueue *Q=(LinkQueue *)malloc(sizeof(LinkQueue)); //Ϊ��������ռ�
    InitStack(S); 
    InitQueue(Q); 
    printf("����һ���ַ�������@����\n");
    while((ch=getchar())!='@'){
        //��������ַ�����ջ�Ͷ���
        putchar(ch);
        Push(S,ch); 
        EnQueue(Q,ch); 
    }
    while(EmptyStack(S))//ջ�л���Ԫ��
    {
        if(Pop(S)==DeQueue(Q)) //��ջ���ַ�������е��ַ�ƥ��
        {
            a=1;
            continue;
        }
        else //�ַ���ƥ��
        {
            a=0;
            break;
        }
    }
    if(a==1){
        printf("�������У�\n");
    }
    else{
        printf("�ǻ������У�\n");
    }
}