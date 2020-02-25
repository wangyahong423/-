#ifndef _ProPCB_h_
#define _ProPCB_h_

#include "ChainList.h"
//上队列
Status GetProcess(LinkList Q,ElemType e);		
//银行家算法
Status BankerAlgorithm(int *Allocation, int *Request,int i, int *Need, int *Available);
//安全性检测算法
Status SecurityCheck(int *Allocation,int *Need, int *Available);
//分配资源
Status AllocateResource(LinkList PCBdata , int pos , int *Request);
//获取资源矩阵
void GetMatrixData(LinkList PCBdata,int *Max,int *Allocation,int *Need,int *Available);
//打印进程资源信息
void PrintProQueue(LinkList L, int *A);


#endif