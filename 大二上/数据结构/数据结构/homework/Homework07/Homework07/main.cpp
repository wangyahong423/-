/*
//����7-2
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
//���ڣ�2018/11/24

#include<stdio.h>
//�洢�ṹ
typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *leftTree,*rightTree;
}BiTreeNode,*BiTree;

//��������������
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

//����7-3(1)
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
//���ڣ�2018/11/24
#include<stdio.h>

//�洢�ṹ
#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct PTNode{
    TElemType data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int r,n;//rΪ����λ�ã�nΪ�����
}PTree;

//������
void CreateTree(PTree *P){
    TElemType c;
    int a,b;
    int i;
    scanf("%d",&(P->n));
    for(i = 0;i<P->n;i++){
        fflush(stdin);
        scanf("%d",&a);//�������������
        scanf("%d",&b);//�������˫����
        P->nodes[i].data = a;
        P->nodes[i].parent = b;
    }
    P->nodes[0].parent = -1;//������ĵ����Ԫ�ص�˫��������Ϊ-1
}

//�����������
int DepthTree(PTree P){
    int i,j,d;
    int depth = 0;
    for(i = 0;i<P.n;i++){
        d=0;
        for(j = i;j >= 0;){
            d++;
            j = P.nodes[j].parent;//����˫�׵�λ����
        }
        if(d > depth)
            depth = d;
    }
    return depth; 
}