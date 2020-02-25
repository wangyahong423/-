//任务名：任务4_4 循环队列
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
#include<stdio.h>
typedef char QElemType;
#define MAXSIZE 100
//tag=0表示队列为空；tag=1表示队列为满
typedef struct{
    QElemType *base;
    int front;
    int rear;
    int tag;
}SqQueue;

//初始化
int InitSqQueue(SqQueue *Q){
    Q->front = Q->rear = 0;
    Q-> tag = 0;//队列为空
}
//入队
int EnSqQueue(SqQueue *Q,QElemType e){
    if(Q->front == Q->rear && Q->tag == 1){
        //队列满
        return false;
    }
    Q->rear = (Q->rear+1)%MAXSIZE;
    Q->base[Q->rear] = e;
}
int main(void){
    
}