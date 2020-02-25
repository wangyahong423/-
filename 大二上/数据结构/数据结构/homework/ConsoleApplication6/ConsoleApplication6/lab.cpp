//任务名：任务4_1 回文判断
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
/*
Status LibsysString（char *ch）{
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
}SqStack; //定义栈

typedef struct{
    char Queue[MAXSIZE];
    int front;
    int rear;
}LinkQueue; //定义队列

//初始化栈
void InitStack(SqStack *S){
    S->top=0;
}
//判断栈是否空    
int EmptyStack(SqStack *S){
    if(S->top==0) //栈顶为空
    {
        return 0;
    }
    else{
        return 1;
    }
} 
//入栈
int Push(SqStack *S,char x){
    if(S->top==MAXSIZE) //栈满
    {
        return 0;
    }
    else //栈未满
    {
        S->top=S->top+1; //栈顶后移
        S->Stack[S->top]=x; //字符入栈
        return 1;
    }
} 
//出栈
char Pop(SqStack *S){
    char y;
    if(S->top==0) //栈为空
    {
        return 0; //返回空格
    }
    else //栈不为空
    {
        y=S->Stack[S->top]; //取出栈顶元素
        S->top=S->top-1; //栈顶指示移动
        return 1;
    }
} 
 //初始化
void InitQueue(LinkQueue *Q){
    Q->front=0;
    Q->rear=0;
}
//判断队列是否为空
int EmptyQueue(LinkQueue *Q){
    if(Q->front==Q->rear) //队头和队尾相等
    {
        return 0;
    }
    else{
        return 1;
    }
} 
//入队
int EnQueue(LinkQueue *Q,char e){
    if((Q->rear+1) % MAXSIZE == Q->front) //队列已满
    {
        return 0;
    }
    else{
        Q->Queue[Q->rear]=e;
        Q->rear=(Q->rear+1) % MAXSIZE;
        return 1;
    }
}
//出队
char DeQueue(LinkQueue *Q){
    char f;
    if(Q->front==Q->rear) //队列为空
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
    SqStack *S=(SqStack *)malloc(sizeof(SqStack)); //为顺序栈申请空间
    LinkQueue *Q=(LinkQueue *)malloc(sizeof(LinkQueue)); //为队列申请空间
    InitStack(S); 
    InitQueue(Q); 
    printf("输入一个字符串，以@结束\n");
    while((ch=getchar())!='@'){
        //将输入的字符串入栈和队列
        putchar(ch);
        Push(S,ch); 
        EnQueue(Q,ch); 
    }
    while(EmptyStack(S))//栈中还有元素
    {
        if(Pop(S)==DeQueue(Q)) //出栈的字符与出队列的字符匹配
        {
            a=1;
            continue;
        }
        else //字符不匹配
        {
            a=0;
            break;
        }
    }
    if(a==1){
        printf("回文序列！\n");
    }
    else{
        printf("非回文序列！\n");
    }
}