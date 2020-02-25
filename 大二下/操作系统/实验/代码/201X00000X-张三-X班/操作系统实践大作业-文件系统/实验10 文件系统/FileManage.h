#ifndef _FileManage_h_
#define _FileManage_h_

#include "List.h"

//�ļ���������
void FileOperatInterface(LinkList_U *pUfd);

//�����ļ����ļ���
Status CreateFile(LinkList_U  *pUfd ,char *fileName);

//��ʾ��ǰ�ļ����������ļ�
void VisitFile(LinkList_U  Ufd);   

//���ļ����ļ���
Status OpenFile(LinkList_U  Ufd ,char *fileName);   


//ɾ���ļ����ļ���
Status Delete(LinkList_U  *pUfd ,char *fileName); 

//���ļ�д������
Status AddContent(LinkList_U  *pUfd ,char *fileName); 







#endif