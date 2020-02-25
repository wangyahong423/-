//任务名：任务8_1 图的邻接矩阵存储基本操作实现
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
#include<stdlib.h>
#include<stdio.h>

#define INFINITY INT_MAX     //最大值（无穷）
#define MAX_VERTEX_NUM 100   //最大顶点个数
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

// CreateUDG函数：
bool CreateUDG(MGraph *G){
	int i,j,k;
    int a,b;
	printf("输入顶点数和边的个数：\n");
	scanf("%d %d",&G->vexnum,&G->arcnum);
    if(G->vexnum>MAX_VERTEX_NUM)//溢出
        return false;
	for(i=0;i<G->vexnum;++i){
		printf("请输入该顶点的值："); 
		scanf("%c",&G->vexs[i]);
	 } 
	for(i=0;i<G->vexnum;++i){ 
        //初始化二维数组，置为0
		for(j=0;j<G->vexnum;++j){
			G->arcs[i][j] = 0;
		}
	} 
    //输入边
    printf("请输入边所连接的两个顶点：\n");
	for(k=0;k<G->arcnum;++k){
		scanf("%d%d",&a,&b);
		i=LocateVex(*G,a);
        j=LocateVex(*G,b);
        //根据无向图矩阵的对称性赋值
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
//图的深度优先遍历
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
    //利用队列判断该图是否为连通图
	int v,temp = 0; 
    for(v=0;v <G.vexnum;v++){
        visited[v]=false; //初始化标志数组，置为false
    }
    for(v=0;v <G.vexnum;v++){
        if(!visited[v]){ 
            temp++;
            DFS(G,v);
        }
    }
    if(temp==0){
       printf("图是非连通图");  
    }   
    else{
        printf("图是连通图");
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
//任务名：任务8_2 邻接表存储图的基本操作实现
//姓名：王亚红
//学号：2017011743
//班级：2017级2班

#include<stdio.h>
#include<stdlib.h>

//定义图的存储结构
#define MAX_VERTEX_NUM 20 
typedef int  InfoType;
typedef char VertexType;

typedef struct ArcNode {     
    int   adjvex; // 该弧所指向的顶点的位置     
    struct ArcNode   *nextarc; // 指向下一条弧的指针     
    InfoType   *info; // 该弧相关信息的指针 
} ArcNode; 
typedef struct VNode { 
    VertexType   data; // 顶点信息     
    ArcNode       *firstarc; // 指向第一条依附该顶点的弧   
} VNode, AdjList[MAX_VERTEX_NUM]; 
typedef struct { 
    AdjList   vertices;     
    int   vexnum, arcnum; // 图的当前顶点数和弧数     
    int   kind; // 图的种类标志
}ALGraph;

//定义栈的存储结构
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct{
    SElemType *base,*top;
    int stacksize;
}Stack;

//有向图的创建：
bool ALCreateDG(ALGraph *G);
//求入度函数：
void FindInDegree(ALGraph G,int *indegree);
//判断是否有回路：
Status TopologicalSort(ALGraph G);

bool ALCreateDG(ALGraph *G){
    int num = 0;
    int vex,arc,tempVex,temp;//temp为某个节点指向的节点的数目
    ArcNode *node = NULL;
	ArcNode *tempPoint = NULL;
    printf("请输入要建立的图的顶点数和边数：\n");
	scanf("%d %d",&vex,&arc);
	G->vexnum = vex;
	G->arcnum = arc;
    //初始化：
    int a;
    for(a = 0;a<MAX_VERTEX_NUM;a++){
		G->vertices[a].data = -1;
    }
    int i;
    for(i = 0;i<vex;i++){
        printf("请输入%d号节点的指向的节点的总个数：\n",i+1);
        scanf("%d",&temp);
        if(temp > 0){
            //存在指向
            printf("listNum = %d\n",num);
            G->vertices[num].data = i;
            if(num >= MAX_VERTEX_NUM ){
                //越界
				return false;
			}
            for(int j = 0;j<temp;j++){
				printf("请分别所指向的节点%d的编号:\n",j+1);
				scanf("%d",&tempVex);		 
				node = (ArcNode*)malloc(sizeof(ArcNode));//创建链表节点			
				node->nextarc = NULL;//链表指针域为空		
				node->adjvex = tempVex;//链表数据域存放该顶点指向的下一个顶点的编号			
                if(j == 0){
                    //第一个顶点，头节点
				    G->vertices[i].firstarc = node;	//连接成功		
				}
				else{
					tempPoint->nextarc = node;
				}
		    	printf("节点创建成功！其编号为：%d\n",node->adjvex);
				tempPoint = node;						//tempPoint是上一个节点的地址。
			}
			//该节点已创建完成
		}
		else{
            //没有下一个节点的指向，即该节点没有出度
			G->vertices[num].data = -1;
			G->vertices[i].firstarc = NULL;
			
		}
		num++;
	}		
	printf("邻接表建立完成!");
	return true;
}
//FindInDegree(ALGraph G,int *indegree)函数：
void FindInDegree(ALGraph G,int *indegree){
    ArcNode *p;
    int i,j,k;
    int indegree[MAX_VERTEX_NUM];
    for(i = 0;i<G.vexnum;i++){
        indegree[i] = 0;//初始化数组，将存放顶点深度的数组全部置为零
    }
    for(j=0;j<G.vexnum;j++){
        p = G.vertices[j].firstarc;
        while(p){
            indegree[p->adjvex]++;//存在firstarc就说明存在入度，对应的indegree数组中的顶点位置就+1
            p = p->nextarc;
        }
    }
    //查看每个顶点的入度
    printf("每个顶点的入度依次为：");
    for(k=0;k<G.vexnum;k++){
        printf("%d\n",indegree[k]);
    }
}

Status TopologicalSort(ALGraph G){
    //用拓扑排序判断该有向图是否有回路
    int i,j,k;
    int sum;//顶点个数
    ArcNode *p;
    int indegree[MAX_VERTEX_NUM]={};
    FindInDegree(G,indegree);
    InitStack(S);//初始化栈
    for(i = 0;i<G.vexnum;i++){
        if(indegree[i] == 0)
            S.Push(i);//将度为零的顶点入栈
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
            printf("该图有回路");
        else
            printf("该图无回路");
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