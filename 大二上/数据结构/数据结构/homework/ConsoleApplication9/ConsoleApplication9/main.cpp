//������������6-2
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
//���ڣ�2018/11/12

//�ŵ㣺��ȡ���㣬�����������ȡϡ�����������һ�еķ���Ԫ������Ԫ��˳���ֻ�ܰ�����˳��洢
//ȱ�㣺���ڶཨ����һ�����飬��ռ���ڴ�ռ䡣

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
    printf("���������A������������������Ԫ����:");
	scanf("%d%d%d",&Aa,&Ab,&Ac);
	A.mu=Aa;
	A.nu=Ab;
	A.tu=Ac;
	printf("���������A�ķ���Ԫ��");
	for(i=1;i<=A.tu;i++)
	{
		scanf("%d%d",&Aelemj,&Aeleme);
		A.data[i].j=Aelemj;
		A.data[i].e=Aeleme;
	}
	printf("���������A������ʼ���������飩��");
	for(k=1;k<=A.mu;++k)
	{
		scanf("%d",&sum);
		A.rpos[k]=sum;
	}
	printf("���������Ԫ�ص��±�ֵa,b:");
	scanf("%d",&mm);
	scanf("%d",&nn);
	result=judge(A,mm,nn);
    printf("���������Ԫ��%d\n",result);
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