#include <stdio.h>
#include<stdlib.h>
#include "DynaSeqStack.h"
#include "DynaLnkQueue.h"

/*思路：
将要检验的字符串按顺序依次进栈，然后再让这些字符串依次进队列，
再让栈中的字符出栈同时队列中的字符依次依个出队，
比较出栈的字符和出队的字符是否完全相同。
若完全相同，即为回文；否则，不是回文。
*/
/*
int main()
{
	// TODO: Place your test code here
    SqStack S;
    LinkQueue Q;
    char *ch;
    ElemType a,b;
    InitStack(&S);
    InitQueue(&Q);
    printf("请输入你要检验的字符串：");
    scanf("%s",&ch);
    while(*ch != '@'){
        Push(&S,*ch); //入栈
        EnQueue(&Q,*ch); //入队
        ch++;
    }
    while(!StackEmpty(S)){
        Pop(&S,&a);
        DeQueue(&Q,&b);
        if(a!=b)
            printf("不是回文");
    }
    printf("Huiwen");
    return 0;
}*/
void main()
{
/*  //函数声明:
    void StInit(Sqstack *s); //初始化顺序栈
    int StEmpty(Sqstack *s); //判断栈是否为空
    int StPush(Sqstack *s,char x); //入栈
    char StPop(Sqstack *s); //出栈
    void QuInit(LinkQueue *q); //初始化循环队列
    int QuEmpty(LinkQueue *q); //判断队列是否为空
    int EnQueue(LinkQueue *q,char e); //入队
    char DeQueue(LinkQueue *q); //出队
    */
    char c;
    int huiwen=0;
    SqStack *s=(SqStack *)malloc(sizeof(SqStack)); //为顺序栈申请空间
    LinkQueue *q=(LinkQueue *)malloc(sizeof(LinkQueue)); //为队列申请空间
    InitStack(&S); //初始化栈
    InitQueue(&Q); //初始化队列
    printf("输入一个字符串，以@结束\n");
    while((c=getchar())!='@') //将输入的字符串入栈和队列
    {
        putchar(c); //输出输入的字符
        StPush(s,c); //字符进栈
        EnQueue(q,c); //字符进队列
    }
    while(StEmpty(s))//栈中还有元素
    {
        if(StPop(s)==DeQueue(q)) //出栈的字符与出队列的字符匹配
        {
            huiwen=1;
            continue;
        }
        else //字符不匹配
        {
            huiwen=0;
            break;
        }
    }
    if(huiwen==1){
        printf("是回文\n");
    }
    else{
        printf("不是回文\n");
    }
}
