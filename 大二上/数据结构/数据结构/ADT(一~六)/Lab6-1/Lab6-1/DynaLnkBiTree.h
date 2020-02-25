/***
*DynaLnkBiTree.h - ��̬��ʽ�������Ķ���
*	
****/

#if !defined(DYNALNKBITREE_H)
#define DYNALNKBITREE_H

#include "ElemType.h"

/*------------------------------------------------------------
// �������ṹ�Ķ���
------------------------------------------------------------*/

typedef struct BiNode
{
	ElemType data;				// �������Ԫ��
	struct BiNode *l;			// ��������ָ��
	struct BiNode *r;			// �����Һ���ָ��
} BinTNode, *BinTree;

enum LR {LEFT, RIGHT};


/*------------------------------------------------------------
// �������Ļ�������
------------------------------------------------------------*/

bool InitBinTree(BinTree *T);
void DestroyBinTree(BinTree *T);
bool CreateBinTree(BinTree *T);
void ClearBinTree(BinTree *T);
bool BinTreeEmpty(BinTree T);
int  BinTreeDepth(BinTree T);
BinTNode *Root(BinTree T);
bool NodeExist(BinTree T, BinTNode* n);
ElemType Value(BinTree T, BinTNode* n);
void Assign(BinTree T, BinTNode* n, ElemType e);
BinTNode* Parent(BinTree T, BinTNode* n);
BinTNode* LeftChild(BinTree T, BinTNode* n);
BinTNode* RightChild(BinTree T, BinTNode* n);
BinTNode* LeftSibling(BinTree T, BinTNode* n);
BinTNode* RightSibling(BinTree T, BinTNode* n);
void InsertNode(BinTree T, BinTNode* p, LR d, BinTNode* n);
void DeleteNode(BinTree T, BinTNode* p, LR d);
void PreOrderTraverse(BinTree T, void (*fp)(ElemType));
void InOrderTraverse(BinTree T, void (*fp)(ElemType));
void PostOrderTraverse(BinTree T, void (*fp)(ElemType));
void LevelOrderTraverse(BinTree T, void (*fp)(ElemType));

#endif /* DYNALNKBITREE_H */
