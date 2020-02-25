//姓名：王亚红
//班级：2017级2班
//学号：2017011743

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char *ch;
    int length;
}HString;

bool StrInsert(HString *S,int pos,HString T){
    //在S串的第pos个字符之前插入T串，即在S.[pos-1]（第pos-1个位置插入）处插入
    //S是指针
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

