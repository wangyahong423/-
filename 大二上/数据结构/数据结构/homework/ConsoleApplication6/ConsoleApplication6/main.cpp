//������������4_4 ѭ������
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
#include<stdio.h>
typedef char QElemType;
#define MAXSIZE 100
//tag=0��ʾ����Ϊ�գ�tag=1��ʾ����Ϊ��
typedef struct{
    QElemType *base;
    int front;
    int rear;
    int tag;
}SqQueue;

//��ʼ��
int InitSqQueue(SqQueue *Q){
    Q->front = Q->rear = 0;
    Q-> tag = 0;//����Ϊ��
}
//���
int EnSqQueue(SqQueue *Q,QElemType e){
    if(Q->front == Q->rear && Q->tag == 1){
        //������
        return false;
    }
    Q->rear = (Q->rear+1)%MAXSIZE;
    Q->base[Q->rear] = e;
}
int main(void){
    
}