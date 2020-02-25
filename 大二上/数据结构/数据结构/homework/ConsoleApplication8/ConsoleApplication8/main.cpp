
//任务名：任务6-1
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
//日期：2018/11/9

#include<stdio.h>

typedef int ElemType;

#define MAXSIZE 12500
typedef struct {
    int i,j;
    ElemType e;
}Triple;
typedef struct{
    Triple data[MAXSIZE + 1];
    int mu,nu,tu;//mu为行标；nu为列标；tu为元素值。
}TSMatrix;

//初始化
int CreateTriple(TSMatrix *T) //构造一个三元组顺序表存储矩阵
{
    int i,m,n;
    ElemType e;
    int k;
    printf("请输入矩阵的行数、列数、非零元素个数（请用逗号隔开）：\n");
    scanf("%d,%d,%d",&T->mu,&T->nu,&T->tu);
    (*T).data[0].i = 0; 
    for(i = 1;i<=(*T).tu;i++){
        do{
            printf("请按行序顺序输入第%d个非零元素所在的行,列,元素值（请用逗号隔开）：\n",i,(*T).mu,(*T).nu);
            scanf("%d,%d,%d",&m,&n,&e);
            k = 0;
            if(m<1 || m>(*T).mu || n<1 || n > (*T).nu)
                k = 1;
            if((m<(*T).data[i-1].i || m == (*T).data[i-1].i) && n <= (*T).data[i-1].j)
                k = 1;
        }while(k);
        (*T).data[i].i = m;
        (*T).data[i].j = n;
        (*T).data[i].e = e;
    }
    return 1;
}

//判断非零元
bool IfZeroElemTypeTSMatrix(TSMatrix T,int i,int j){
    int x;
    if(i <= 0 || j <= 0 || i > T.mu || j > T.nu)
        return false;
    for(x=1;x<MAXSIZE+1;x++){
        if(T.data[x].i == i && T.data[x].j == j)
            return true;
    }
    return false;
}

int main(void){
    TSMatrix arr;
    CreateTriple(&arr);
    int i,j;
    printf("请输入i、j的值（请用逗号隔开）：");
    scanf("%d,%d",&i,&j);
    if(i>arr.mu || j>arr.nu || i<1 || j<1){
        printf("您输入的i，j的下标值不合法！\n");
    }
    else{
        if(IfZeroElemTypeTSMatrix(arr,i,j) == false)
            printf("你输入的i、j下标值所对应的元素不是非零元！\n");
        else
            printf("你输入的i、j下标值所对应的元素是非零元！\n");
    }
    return 0;
}