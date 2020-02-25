//任务名：任务6-2
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
//日期：2018/11/12

//优点：存取方便，即可以随机存取稀疏矩阵中任意一行的非零元，而三元组顺序表只能按进行顺序存储
//缺点：由于多建立了一个数组，多占了内存空间。

#include<stdio.h>
#define MAXSIZE 100
#define MAXROW 20
typedef struct
{
	int j;
	int e;
}Second;
typedef struct
{
	Second data[MAXSIZE+1];
	int rpos[MAXROW+1];
	int mu,nu,tu;
}TSMatrix;

int judge(TSMatrix A,int m,int n)
{
	int tm = A.rpos[m];
    int pm = A.rpos[m + 1];
    if(m<1 || n<1 || m>A.mu || n>A.nu)
        return 0;
    for(tm = A.rpos[m];tm < pm;tm++){
        if(A.data[tm].j == n)
            return A.data[tm].e;
    }
}

int main(void)
{
	TSMatrix A;
	int Aa,Ab,Ac,i,mm,nn,result;
	int Aelemj,Aeleme;
	int Anum=1;
	int k,sum=0;
    printf("请输入矩阵A的行数、列数、非零元个数:");
	scanf("%d%d%d",&Aa,&Ab,&Ac);
	A.mu=Aa;
	A.nu=Ab;
	A.tu=Ac;
	printf("请输入矩阵A的非零元：");
	for(i=1;i<=A.tu;i++)
	{
		scanf("%d%d",&Aelemj,&Aeleme);
		A.data[i].j=Aelemj;
		A.data[i].e=Aeleme;
	}
	printf("请输入矩阵A的行起始向量（数组）：");
	for(k=1;k<=A.mu;++k)
	{
		scanf("%d",&sum);
		A.rpos[k]=sum;
	}
	printf("请输入矩阵元素的下标值a,b:");
	scanf("%d",&mm);
	scanf("%d",&nn);
	result=judge(A,mm,nn);
    printf("请输出矩阵元素%d\n",result);
	return 0;
}

/*
#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
	int j;
	int e;
}Second;
typedef struct
{
	Second data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

bool getElem(TSMatrix M,int i,int j){
    int m,n,k;
    if(i<0 || i>M.mu || j<0 || j>M.nu){
        return false;
    }
    

}*/