//������������8_1 ͼ���ڽӾ���洢��������ʵ��
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
#include<stdlib.h>
#include<stdio.h>

#define INFINITY INT_MAX     //���ֵ�����
#define MAX_VERTEX_NUM 100   //��󶥵����
bool visited [MAX_VERTEX_NUM];
typedef int VRType;
typedef int InfoType;
typedef char VertexType;

typedef enum{DG,DN,UDG,UDN}GraphKind;

typedef struct ArcCell{
    VRType adj;
    InfoType *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph;

// CreateUDG������
bool CreateUDG(MGraph *G){
	int i,j,k;
    int a,b;
	printf("���붥�����ͱߵĸ�����\n");
	scanf("%d %d",&G->vexnum,&G->arcnum);
    if(G->vexnum>MAX_VERTEX_NUM)//���
        return false;
	for(i=0;i<G->vexnum;++i){
		printf("������ö����ֵ��"); 
		scanf("%c",&G->vexs[i]);
	 } 
	for(i=0;i<G->vexnum;++i){ 
        //��ʼ����ά���飬��Ϊ0
		for(j=0;j<G->vexnum;++j){
			G->arcs[i][j] = 0;
		}
	} 
    //�����
    printf("������������ӵ��������㣺\n");
	for(k=0;k<G->arcnum;++k){
		scanf("%d%d",&a,&b);
		i=LocateVex(*G,a);
        j=LocateVex(*G,b);
        //��������ͼ����ĶԳ��Ը�ֵ
        G->arcs[i][j] = 1;
        G->arcs[j][i] = 1;
	}
	return true;
}
int LocateVex(MGraph G,VertexType v){
    int i;
    for(i=0;i<G.vexnum;i++){
        if(G.vexs[i]==v){
            return i;
        }   
    }          
    return -1;
}


bool visited[MAX_VERTEX_NUM];
//ͼ��������ȱ���
void DFS(MGraph G,int v) 
{ 
    visited[v]=true; 
    for(int i=0;i <G.vexnum;i++){
        if(G.arcs[v][i].adj==1){
            if(!visited[i]){
                DFS(G,i);   
            }           
        }
    }
}
void JudgeUDGConnectivity(MGraph G){
    //���ö����жϸ�ͼ�Ƿ�Ϊ��ͨͼ
	int v,temp = 0; 
    for(v=0;v <G.vexnum;v++){
        visited[v]=false; //��ʼ����־���飬��Ϊfalse
    }
    for(v=0;v <G.vexnum;v++){
        if(!visited[v]){ 
            temp++;
            DFS(G,v);
        }
    }
    if(temp==0){
       printf("ͼ�Ƿ���ͨͼ");  
    }   
    else{
        printf("ͼ����ͨͼ");
    }
}

int main(void)
{
	MGraph G;
	CreateUDG(&G);
	JudgeUDGConnectivity(G);
	return 0;
}


/*
//������������8_2 �ڽӱ�洢ͼ�Ļ�������ʵ��
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��

#include<stdio.h>
#include<stdlib.h>

//����ͼ�Ĵ洢�ṹ
#define MAX_VERTEX_NUM 20 
typedef int  InfoType;
typedef char VertexType;

typedef struct ArcNode {     
    int   adjvex; // �û���ָ��Ķ����λ��     
    struct ArcNode   *nextarc; // ָ����һ������ָ��     
    InfoType   *info; // �û������Ϣ��ָ�� 
} ArcNode; 
typedef struct VNode { 
    VertexType   data; // ������Ϣ     
    ArcNode       *firstarc; // ָ���һ�������ö���Ļ�   
} VNode, AdjList[MAX_VERTEX_NUM]; 
typedef struct { 
    AdjList   vertices;     
    int   vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���     
    int   kind; // ͼ�������־
}ALGraph;

//����ջ�Ĵ洢�ṹ
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct{
    SElemType *base,*top;
    int stacksize;
}Stack;

//����ͼ�Ĵ�����
bool ALCreateDG(ALGraph *G);
//����Ⱥ�����
void FindInDegree(ALGraph G,int *indegree);
//�ж��Ƿ��л�·��
Status TopologicalSort(ALGraph G);

bool ALCreateDG(ALGraph *G){
    int num = 0;
    int vex,arc,tempVex,temp;//tempΪĳ���ڵ�ָ��Ľڵ����Ŀ
    ArcNode *node = NULL;
	ArcNode *tempPoint = NULL;
    printf("������Ҫ������ͼ�Ķ������ͱ�����\n");
	scanf("%d %d",&vex,&arc);
	G->vexnum = vex;
	G->arcnum = arc;
    //��ʼ����
    int a;
    for(a = 0;a<MAX_VERTEX_NUM;a++){
		G->vertices[a].data = -1;
    }
    int i;
    for(i = 0;i<vex;i++){
        printf("������%d�Žڵ��ָ��Ľڵ���ܸ�����\n",i+1);
        scanf("%d",&temp);
        if(temp > 0){
            //����ָ��
            printf("listNum = %d\n",num);
            G->vertices[num].data = i;
            if(num >= MAX_VERTEX_NUM ){
                //Խ��
				return false;
			}
            for(int j = 0;j<temp;j++){
				printf("��ֱ���ָ��Ľڵ�%d�ı��:\n",j+1);
				scanf("%d",&tempVex);		 
				node = (ArcNode*)malloc(sizeof(ArcNode));//��������ڵ�			
				node->nextarc = NULL;//����ָ����Ϊ��		
				node->adjvex = tempVex;//�����������Ÿö���ָ�����һ������ı��			
                if(j == 0){
                    //��һ�����㣬ͷ�ڵ�
				    G->vertices[i].firstarc = node;	//���ӳɹ�		
				}
				else{
					tempPoint->nextarc = node;
				}
		    	printf("�ڵ㴴���ɹ�������Ϊ��%d\n",node->adjvex);
				tempPoint = node;						//tempPoint����һ���ڵ�ĵ�ַ��
			}
			//�ýڵ��Ѵ������
		}
		else{
            //û����һ���ڵ��ָ�򣬼��ýڵ�û�г���
			G->vertices[num].data = -1;
			G->vertices[i].firstarc = NULL;
			
		}
		num++;
	}		
	printf("�ڽӱ������!");
	return true;
}
//FindInDegree(ALGraph G,int *indegree)������
void FindInDegree(ALGraph G,int *indegree){
    ArcNode *p;
    int i,j,k;
    int indegree[MAX_VERTEX_NUM];
    for(i = 0;i<G.vexnum;i++){
        indegree[i] = 0;//��ʼ�����飬����Ŷ�����ȵ�����ȫ����Ϊ��
    }
    for(j=0;j<G.vexnum;j++){
        p = G.vertices[j].firstarc;
        while(p){
            indegree[p->adjvex]++;//����firstarc��˵��������ȣ���Ӧ��indegree�����еĶ���λ�þ�+1
            p = p->nextarc;
        }
    }
    //�鿴ÿ����������
    printf("ÿ��������������Ϊ��");
    for(k=0;k<G.vexnum;k++){
        printf("%d\n",indegree[k]);
    }
}

Status TopologicalSort(ALGraph G){
    //�����������жϸ�����ͼ�Ƿ��л�·
    int i,j,k;
    int sum;//�������
    ArcNode *p;
    int indegree[MAX_VERTEX_NUM]={};
    FindInDegree(G,indegree);
    InitStack(S);//��ʼ��ջ
    for(i = 0;i<G.vexnum;i++){
        if(indegree[i] == 0)
            S.Push(i);//����Ϊ��Ķ�����ջ
    }
    while(S.StackEmpty() == NULL){
        S.Pop();
        printf("%d\n",G.vertices[i].data);
        sum++;
        for(p = G.vertices[i].firstarc;p=p->nextarc;){
            k = p->adjvex;
            if((--indegree[k])==NULL)
                S.Push(k);
        }
        if(sum < G.vexnum)
            printf("��ͼ�л�·");
        else
            printf("��ͼ�޻�·");
    }
}


int main(void)
{
	ALGraph G;
	ALCreateDG(&G);
	TopologicalSort(G);
	return 0;
}
*/