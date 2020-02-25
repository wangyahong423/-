/*
//任务名：任务4_4 循环队列
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
//算法：初始化时将tag设置为0用来表示队空。
//      入队：首先判断队列是否为满，若满则不能入队；否则依次入队，入队完成后，判断(Q->rear == Q->front)，若相等则队列已满，令tag=1；否则tag=0.
//      出队：首先判断队列是否为空，若为空则不能进行出队操作；否则依次出队，出队操作完成后，判断(Q->rear == Q->front)，若相等则队列已空，令tag=0；否恩泽tag=1.
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
    Q->rear = (Q->rear+1) % MAXSIZE;
    Q->base[Q->rear] = e;
    if(Q->rear == Q->front){
        //队列满
        Q->tag = 1;
    }
    return true;
}
//出队
int DeSqQueue(SqQueue *Q,QElemType e){
    if(Q->front == Q->rear && Q->tag == 0){
        //队列空
        return false;
    }
    Q->front = (Q->rear+1) % MAXSIZE;
    e = Q->base[Q->front];
    if(Q->rear == Q->front){
        //队列空
        Q->tag = 0;
    }
    return true;
}
*/

/*
//任务名：任务4_3  递推与递归
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
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
//任务名：任务4_2 序列判断
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
//一般准则：任何前N个序列中S的个数一定大于或者等于X的个数，并且整个序列中S的个数一定等于X的个数
//证明：假设两个合法序列的前N个元素操作完全一样，最终的序列情况也完全一样，栈顶为a，
//      下一个要进入的元素均为b。假设第一个序列的第N+1个操作是X，第二个序列的第N+1个操作是S，
//      在经过操作之后，第一个序列输出的情况一定是：先输出a，再输出b；
//      而第二个序列的输出情况为：先输出b，再输出a。由此可证：两个不同的合法）序列不可能得到相同的输出元素序列。
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
            j++;//X的个数
        }
        else{
            k++;//S的个数
        }
    }
    if(j>k || j<k){
        printf("非法序列\n");
    }
    else{//S和X的个数相同
        if(A[0] == 'X'){
            printf("非法序列\n");
        }
        else if(A[len-1] == 'S'){
            printf("非法序列\n");
        }
        else if(A[len-1] == 'X'){
            for(i = 0;i<len/2;i++){
                if(A[i]=='X')
                    m++;
                else
                    n++;
            }
            if(m>n){
                printf("非法序列\n");
            }
            else{
                printf("合法序列\n");
            }
        }
    }
    return true;
}

int main(void){
    Judge("SXSX");
    Judge("SXXS");
}*/