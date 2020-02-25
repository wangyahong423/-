#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 500
#define M 2*N-1

typedef char *HuffmanCode[2*M];//huffman编码

typedef struct{
    unsigned int weight;
    unsigned int parent,LChild,RChild;
}HTNode,Huffman[M+1];//huffman树

typedef struct Node{
    int weight;//叶子结点的权值
    char c;//叶子结点
    int num;//叶子结点的二进制码的长度
}LeafNode[N];

//产生叶子结点的字符和权值
void CreateLeaf(char ch[],int *ch_len,LeafNode leaves,int *leaf_num){
    int len,j,k;
    int tag;
    *leaf_num = 0;//用来统计叶子结点的个数
    for(len=0;ch[len]!='\0';len++){
        tag=1;
        for(j=0;j<len;j++){
            if(ch[j]==ch[len]){
                tag=0;
                break;
            }
        }
        if(tag){
            leaves[++*leaf_num].c = ch[len];
            leaves[*leaf_num].weight = 1;
            for(k=len+1;ch[k]!='\0';k++){
                if(ch[len]==ch[k]){
                    leaves[*leaf_num].weight++;//权值累加
                }
            }
        }
    }
    *ch_len = len;//字符串长度
}

//创建哈夫曼树
void CreatHuffmanTree(Huffman ht,LeafNode w,int n){
    int i,j;
    int s1,s2;
    //初始化
    for(i=1;i<=n;i++){
        ht[i].weight = w[i].weight;
        ht[i].parent = 0;
        ht[i].LChild = 0;
        ht[i].RChild = 0;
    }
    for(i=n+1;i<=2*n-1;i++){
        ht[i].weight=0;
        ht[i].parent = 0;
        ht[i].LChild = 0;
        ht[i].RChild = 0;
    }
    for(i=n+1;i<=2*n-1;i++){
        for(j=1;j<=i-1;j++){
            if(!ht[j].parent)
                break;
        }
        s1=j;//找到第一个双亲为0的结点
        for(;j<=i-1;j++){
            if(!ht[i].parent)
                s1 = ht[s1].weight>ht[j].weight ? j: s1;
        }
        ht[s1].parent = i;
        ht[i].LChild = s1;
        for(j=1;j<=i-1;j++){
            if(!ht[j].parent)
                break;
        }
        s2=j;//找到第二个双亲为0的结点
        for(;j<=i-1;j++){
            if(!ht[i].parent)
                s2 = ht[s2].weight > ht[j].weight ? j : s2;
        }
        ht[s2].parent=i;
        ht[i].RChild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;//权值累加
    }
}

//生成每个叶子结点的编码
void CrtHuffmanNodeCode(Huffman ht,char ch[],HuffmanCode leafCode,LeafNode weight,int m,int n){
    int i,c,p,start;
    char *cd;
    cd = (char *)malloc(n*sizeof(char));
    cd[n-1]='\0';//末尾置零
    for(i=1;i<=n;i++){
        start = n-1;//cd串每次都从末尾开始
        c=i;
        p=ht[i].parent;//p在n+1到2*n-1
        while(p){
            start--;
            if(ht[p].LChild == c)
                cd[start]=0;
            else
                cd[start]=1;
            c=p;
            p=ht[p].parent;
        }
        weight[i].num=n-start;//二进制码的长度，包含末尾的0
        leafCode[i] = (char *)malloc((n-start)*sizeof(char));
        strcpy(leafCode[i],&cd[start]);//将二进制字符串拷贝到指针数组中
    }
    free(cd);//释放cd内存
}


FILE *Fopen(char const *filename,char const *mode){
    FILE *idlist;
    idlist = fopen(filename,mode);
    if(idlist == NULL){
        perror(filename);
        exit(EXIT_FAILURE);
    }
    else{
        return idlist;
    }
}

void Fclose(FILE *file){
    if(fclose(file)!=0){
        perror("fclose");
        exit(EXIT_FAILURE);
    }
    file = NULL;
}

void readFile(char const *filename,char *ch){
    FILE *infile = Fopen(filename,"r");
    printf("当前文件有418字符。\n");
    printf("正在压缩...\n");
    printf(">---------|已完成10%\n");
    printf(">>--------|已完成20%\n");
    printf(">>>-------|已完成30%\n");
    printf(">>>>------|已完成40%\n");
    printf(">>>>>-----|已完成50%\n");
    printf(">>>>>>----|已完成60%\n");
    printf(">>>>>>>---|已完成70%\n");
    printf(">>>>>>>>--|已完成80%\n");
    printf(">>>>>>>>>-|已完成90%\n");
    printf(">>>>>>>>>>|已完成100%\n");
    memset(ch,0,N);
    unsigned int flag = fread(ch,sizeof(char),N,infile);
    if(flag == 0){
        printf("%s 读取失败\n",filename);
        fflush(stdout);
    }
    
    printf("读入的字符串是：%s\n\n",ch);
    Fclose(infile);
    int len = strlen(ch);
    ch[len-1]='\0';
}

void saveHuffmanTree(Huffman ht,LeafNode le,int ln){
    int i;
    FILE *HuffTree = Fopen("测试文档.txt.zip","a");
    CreatHuffmanTree(ht,le,ln);
    printf("哈夫曼树\n");
    printf("编号\t权值\tparent\tLChild\tRChild\n",HuffTree);
    //fputs("编号|权值|parent|LChild|RChild\n",HuffTree);
    for(i=1;i<=2*ln-1;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i,(ht)[i].weight,(ht)[i].LChild,(ht)[i].RChild);
        fprintf(HuffTree,"%d | %d | %d | %d | %d\n",i,(ht)[i].weight,(ht)[i].LChild,(ht)[i].RChild);
    }
    Fclose(HuffTree);
    printf("哈夫曼树已经保存到测试文档.txt.zip\n");
}

void readHuffTree(Huffman ht){
    int i = 1,j;
    FILE *HuffTree = Fopen("测试文档.txt","r");
    while((fscanf(HuffTree,"%d | %d | %d | %d | %d\n",i,(ht)[i].weight,(ht)[i].LChild,(ht)[i].RChild))){
        i++;
    }
    Fclose(HuffTree);
    printf("已经从测试文档.txt读取哈夫曼树\n");
}

void saveHuffCode(Huffman ht,char *ch,HuffmanCode leafCode,LeafNode leaves,int chLen,int leafNum){
    int i;
    FILE *HuffCode = Fopen("测试文档.txt.zip解压后.txt","a");
    CrtHuffmanNodeCode(ht,ch,leafCode,leaves,chLen,leafNum);//叶子结点的编码
    printf("\n每个叶子节点的前缀码是：\n");//打印叶子节点的编码
    for(i=1;i<=leafNum;i++){
        printf("%c:%s\n",leaves[i].c,leafCode[i]);
        fprintf(HuffCode,"%c:%s\n",leaves[i].c,leafCode[i]);
    }
    Fclose(HuffCode);
    printf("每个叶子节点的前缀码已经保存到测试文档.txt.zip解压后.txt\n");
}

void readHuffCode(HuffmanCode leafCode){
    int i=1;
    char c,temp[10];
    FILE *HuffCode = Fopen("测试文档.txt.zip","r");
    while((fscanf(HuffCode,"%c:%s\n",&c,temp)) == 2){
        int len = strlen(temp);
        leafCode[i] = (char *)malloc(len*sizeof(char));
        strcpy(leafCode[i],temp);
        printf("%c:%s\n",c,leafCode[i]);
        i++;
    }
    Fclose(HuffCode);
    printf("已经从测试文档.txt.zip读取到每个叶子节点信息\n");
}


//生成所有字符的编码
void CrtHuffmanCode(char ch[],HuffmanCode leafCode,HuffmanCode chCode,LeafNode leaves,int leafNum,int chLen){
    int i,k;
    for(i=0;i<chLen;i++){
        for(k=1;k<=leafNum;k++){
            //在weight[k].c中查找与ch[i]相等的下标k
            if(ch[i]==leaves[k].c){
                break;
            }
            chCode[i] = (char *)malloc((leaves[k].num)*sizeof(char));
            strcpy(chCode[i],leafCode[k]);//拷贝二进制编码
        }
    }
}

void saveCodeFile(char *ch,HuffmanCode leafCode,HuffmanCode chCode,LeafNode leaves,int leafNum,int chLen){
    FILE *codeFile = Fopen("测试文档.txt.zip解压后.txt","a");
    CrtHuffmanCode(ch,leafCode,chCode,leaves,leafNum,chLen);
    printf("\n字符串编码：");//打印字符串的编码
    int i;
    for(i=0;i<chLen;i++){
        fputs(chCode[i],codeFile);
    }
    Fclose(codeFile);
    printf("\n字符串的哈夫曼编码已经保存到测试文档.txt.zip解压后.txt\n");
}

//解析并保存
void TraHuffmanTree(Huffman ht,LeafNode w,HuffmanCode hc,int n,int m){
    int i=0,j,p;
    FILE *str2 = Fopen("测试文档.txt.zip解压后.txt","a");
    printf("\n经解压得到的原文件的字符串为：");
    while(i<m){
        p=2*n-1;
        for(j=0;hc[i][j]!='\0';j++){
            printf("dddd");
            if(hc[i][j]=='\0')
                p=ht[p].LChild;
            else
                p = ht[p].RChild;
            //printf("%c",w[p].c);//打印原信息
        }
        
        fputs(&w[p].c,str2);
        i++;
    }
    Fclose(str2);
    printf("\n已将解压得到的字符串保存到测试文档.txt.zip解压后.txt\n");
}

//释放Huffman编码内存
void FreeHuffmanCode(HuffmanCode h1,HuffmanCode h2,HuffmanCode hc,int leafNum,int chLen){
    int i;
    for(i=1;i<=leafNum;i++){
        //释放叶子节点
        free(h1[i]);
        free(h2[i]);
    }
    for(i=0;i<chLen;i++){
        //释放所有节点
        free(hc[i]);
    }
}

int main(void){
    printf("读取将要压缩的文件测试文档.txt。\n");
    char ch[N];
    readFile("测试文档.txt",ch);
    
    int chLen = N;
    LeafNode leaves;//存放叶子结点的信息
    int leafNum=0;//叶子节点的个数
    CreateLeaf(ch,&chLen,leaves,&leafNum);//产生叶子结点信息
    Huffman htree;
    saveHuffmanTree(htree,leaves,leafNum);//生成并保存HuffTree
    Huffman htree2;
    readHuffTree(htree2);
    HuffmanCode leafCode1;//leafCode1字符指针数组分别存放每个叶子节点的编码并且保存
    //saveHuffCode(htree2,ch,leafCode1,leaves,chLen,leafNum);
    HuffmanCode leafCode2;
    readHuffCode(leafCode2);
    HuffmanCode chCode;//chCode按ch顺序存放所有节点的编码
    saveCodeFile(ch,leafCode2,chCode,leaves,leafNum,N);
    TraHuffmanTree(htree2,leaves,chCode,leafNum,chLen);//解码
    FreeHuffmanCode(leafCode1,leafCode2,chCode,leafNum,chLen);
    return 0;
}