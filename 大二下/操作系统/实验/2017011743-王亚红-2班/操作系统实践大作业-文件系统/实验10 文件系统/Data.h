#ifndef _Data_h_
#define _Data_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true				1
#define false				0
#define PCBType				PCB
#define Status				int
#define OK					1
#define	ERROR				0
#define	MAX_NAME_SIZE		20
#define	MAX_CONTENT_SIZE	50
#define LinkList_R		RootList
#define LinkList_U		UFDList

#define ElemType_R		RootDirData
#define ElemType_U		UserDirData

#define RNode			RootDirNode
#define UNode			UserNode


typedef struct FCB
{
	char FileName[MAX_NAME_SIZE];		//�ļ���  ���п���
	char Content[MAX_CONTENT_SIZE];		//�ļ�����
}FCB;

typedef struct UserDirData				//�û�Ŀ¼�н���һ��data��
{
	char FileName[MAX_NAME_SIZE];		//�ļ���
	FCB *FileAddress;		
}UserDirData;

typedef struct UserNode					//�û����
{
	UserDirData data;					
	struct UserNode *Next;		
}UserNode, *UFDList;					//UFD�û��ļ�Ŀ¼

typedef struct RootDirData				//��Ŀ¼�е�һ��data��
{
	char UserName[MAX_NAME_SIZE];		//�û���
	char UserPWD[MAX_NAME_SIZE];		//����
	UFDList UserFileList;				//�û��ļ�Ŀ¼
}RootDirData;							

typedef struct RootDirNode				//��Ŀ¼���
{
	RootDirData data;					
	struct RootDirNode *Next;		
}RootDirNode, *RootList;					//Root��


#endif 
