/*
//������������4_4 ѭ������
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
//�㷨����ʼ��ʱ��tag����Ϊ0������ʾ�ӿա�
//      ��ӣ������ж϶����Ƿ�Ϊ��������������ӣ�����������ӣ������ɺ��ж�(Q->rear == Q->front)��������������������tag=1������tag=0.
//      ���ӣ������ж϶����Ƿ�Ϊ�գ���Ϊ�����ܽ��г��Ӳ������������γ��ӣ����Ӳ�����ɺ��ж�(Q->rear == Q->front)�������������ѿգ���tag=0�������tag=1.
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
    Q->rear = (Q->rear+1) % MAXSIZE;
    Q->base[Q->rear] = e;
    if(Q->rear == Q->front){
        //������
        Q->tag = 1;
    }
    return true;
}
//����
int DeSqQueue(SqQueue *Q,QElemType e){
    if(Q->front == Q->rear && Q->tag == 0){
        //���п�
        return false;
    }
    Q->front = (Q->rear+1) % MAXSIZE;
    e = Q->base[Q->front];
    if(Q->rear == Q->front){
        //���п�
        Q->tag = 0;
    }
    return true;
}
*/

/*
//������������4_3  ������ݹ�
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
#include<stdio.h>

int digui(int n){
    if(n<=1){
        printf("%d\n",n);
        return n;
    }
    else{  
        printf("%d\n",n);
        return digui(n-1);
    }
}
int main(void){
    digui(4);
    return 0;
}*/



/*
//������������4_2 �����ж�
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
//һ��׼���κ�ǰN��������S�ĸ���һ�����ڻ��ߵ���X�ĸ�������������������S�ĸ���һ������X�ĸ���
//֤�������������Ϸ����е�ǰN��Ԫ�ز�����ȫһ�������յ��������Ҳ��ȫһ����ջ��Ϊa��
//      ��һ��Ҫ�����Ԫ�ؾ�Ϊb�������һ�����еĵ�N+1��������X���ڶ������еĵ�N+1��������S��
//      �ھ�������֮�󣬵�һ��������������һ���ǣ������a�������b��
//      ���ڶ������е�������Ϊ�������b�������a���ɴ˿�֤��������ͬ�ĺϷ������в����ܵõ���ͬ�����Ԫ�����С�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Status;

Status Judge(char *A){
    int i,j=0,k=0;
    int len = strlen(A);
    int m=0,n=0;
    for(i=0;i<len;i++){
        if(A[i]=='X'){
            j++;//X�ĸ���
        }
        else{
            k++;//S�ĸ���
        }
    }
    if(j>k || j<k){
        printf("�Ƿ�����\n");
    }
    else{//S��X�ĸ�����ͬ
        if(A[0] == 'X'){
            printf("�Ƿ�����\n");
        }
        else if(A[len-1] == 'S'){
            printf("�Ƿ�����\n");
        }
        else if(A[len-1] == 'X'){
            for(i = 0;i<len/2;i++){
                if(A[i]=='X')
                    m++;
                else
                    n++;
            }
            if(m>n){
                printf("�Ƿ�����\n");
            }
            else{
                printf("�Ϸ�����\n");
            }
        }
    }
    return true;
}

int main(void){
    Judge("SXSX");
    Judge("SXXS");
}*/