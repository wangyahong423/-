/*
//任务：7-2
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
//日期：2018/11/24

#include<stdio.h>
//存储结构
typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *leftTree,*rightTree;
}BiTreeNode,*BiTree;

//计算二叉树的深度
int BT_Depth(BiTree T){
    int depth,max;
    int leftDepth,rightDepth;
    if(T == NULL){
        depth = 0;
    }
    else{   
        leftDepth = BT_Depth(T->leftTree);
        rightDepth = BT_Depth(T->rightTree);
        if(leftDepth > rightDepth){
            depth = leftDepth + 1;
        }
        else if(leftDepth < rightDepth){
            depth = rightDepth + 1;
        }
        else{
            depth = rightDepth + 1;
        }
    }
    return depth;
}
*/

//任务：7-3(1)
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
//日期：2018/11/24
#include<stdio.h>

//存储结构
#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct PTNode{
    TElemType data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int r,n;//r为根的位置，n为结点数
}PTree;

//创建树
void CreateTree(PTree *P){
    TElemType c;
    int a,b;
    int i;
    scanf("%d",&(P->n));
    for(i = 0;i<P->n;i++){
        fflush(stdin);
        scanf("%d",&a);//输入结点的数据域
        scanf("%d",&b);//输入结点的双亲域
        P->nodes[i].data = a;
        P->nodes[i].parent = b;
    }
    P->nodes[0].parent = -1;//将数组的第零个元素的双亲域设置为-1
}

//计算树的深度
int DepthTree(PTree P){
    int i,j,d;
    int depth = 0;
    for(i = 0;i<P.n;i++){
        d=0;
        for(j = i;j >= 0;){
            d++;
            j = P.nodes[j].parent;//访问双亲的位置域
        }
        if(d > depth)
            depth = d;
    }
    return depth; 
}