//���������Ǻ�
//�༶��2017��2��
//ѧ�ţ�2017011743

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char *ch;
    int length;
}HString;

bool StrInsert(HString *S,int pos,HString T){
    //��S���ĵ�pos���ַ�֮ǰ����T��������S.[pos-1]����pos-1��λ�ò��룩������
    //S��ָ��
    int i;
    if(pos < 1 || pos > S->length + 1)
        return false;
    if(T.length != NULL){
        if(!(S->ch = (char *)realloc(S->ch,(S->length + T.length)*sizeof(char))))
            return false;
        for(i = S->length-1;i>=pos-1;--i){
            S->ch[i+T.length] = S->ch[i];
        }
        for(i = 0;i<T.length;i++){
            S->ch[pos-1+i] = T.ch[i];
        }
        S->length += T.length;
    }
    return true;
}

