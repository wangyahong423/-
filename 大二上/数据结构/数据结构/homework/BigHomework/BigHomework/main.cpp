#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 500
#define M 2*N-1

typedef char *HuffmanCode[2*M];//huffman����

typedef struct{
    unsigned int weight;
    unsigned int parent,LChild,RChild;
}HTNode,Huffman[M+1];//huffman��

typedef struct Node{
    int weight;//Ҷ�ӽ���Ȩֵ
    char c;//Ҷ�ӽ��
    int num;//Ҷ�ӽ��Ķ�������ĳ���
}LeafNode[N];

//����Ҷ�ӽ����ַ���Ȩֵ
void CreateLeaf(char ch[],int *ch_len,LeafNode leaves,int *leaf_num){
    int len,j,k;
    int tag;
    *leaf_num = 0;//����ͳ��Ҷ�ӽ��ĸ���
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
                    leaves[*leaf_num].weight++;//Ȩֵ�ۼ�
                }
            }
        }
    }
    *ch_len = len;//�ַ�������
}

//������������
void CreatHuffmanTree(Huffman ht,LeafNode w,int n){
    int i,j;
    int s1,s2;
    //��ʼ��
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
        s1=j;//�ҵ���һ��˫��Ϊ0�Ľ��
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
        s2=j;//�ҵ��ڶ���˫��Ϊ0�Ľ��
        for(;j<=i-1;j++){
            if(!ht[i].parent)
                s2 = ht[s2].weight > ht[j].weight ? j : s2;
        }
        ht[s2].parent=i;
        ht[i].RChild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;//Ȩֵ�ۼ�
    }
}

//����ÿ��Ҷ�ӽ��ı���
void CrtHuffmanNodeCode(Huffman ht,char ch[],HuffmanCode leafCode,LeafNode weight,int m,int n){
    int i,c,p,start;
    char *cd;
    cd = (char *)malloc(n*sizeof(char));
    cd[n-1]='\0';//ĩβ����
    for(i=1;i<=n;i++){
        start = n-1;//cd��ÿ�ζ���ĩβ��ʼ
        c=i;
        p=ht[i].parent;//p��n+1��2*n-1
        while(p){
            start--;
            if(ht[p].LChild == c)
                cd[start]=0;
            else
                cd[start]=1;
            c=p;
            p=ht[p].parent;
        }
        weight[i].num=n-start;//��������ĳ��ȣ�����ĩβ��0
        leafCode[i] = (char *)malloc((n-start)*sizeof(char));
        strcpy(leafCode[i],&cd[start]);//���������ַ���������ָ��������
    }
    free(cd);//�ͷ�cd�ڴ�
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
    printf("��ǰ�ļ���418�ַ���\n");
    printf("����ѹ��...\n");
    printf(">---------|�����10%\n");
    printf(">>--------|�����20%\n");
    printf(">>>-------|�����30%\n");
    printf(">>>>------|�����40%\n");
    printf(">>>>>-----|�����50%\n");
    printf(">>>>>>----|�����60%\n");
    printf(">>>>>>>---|�����70%\n");
    printf(">>>>>>>>--|�����80%\n");
    printf(">>>>>>>>>-|�����90%\n");
    printf(">>>>>>>>>>|�����100%\n");
    memset(ch,0,N);
    unsigned int flag = fread(ch,sizeof(char),N,infile);
    if(flag == 0){
        printf("%s ��ȡʧ��\n",filename);
        fflush(stdout);
    }
    
    printf("������ַ����ǣ�%s\n\n",ch);
    Fclose(infile);
    int len = strlen(ch);
    ch[len-1]='\0';
}

void saveHuffmanTree(Huffman ht,LeafNode le,int ln){
    int i;
    FILE *HuffTree = Fopen("�����ĵ�.txt.zip","a");
    CreatHuffmanTree(ht,le,ln);
    printf("��������\n");
    printf("���\tȨֵ\tparent\tLChild\tRChild\n",HuffTree);
    //fputs("���|Ȩֵ|parent|LChild|RChild\n",HuffTree);
    for(i=1;i<=2*ln-1;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i,(ht)[i].weight,(ht)[i].LChild,(ht)[i].RChild);
        fprintf(HuffTree,"%d | %d | %d | %d | %d\n",i,(ht)[i].weight,(ht)[i].LChild,(ht)[i].RChild);
    }
    Fclose(HuffTree);
    printf("���������Ѿ����浽�����ĵ�.txt.zip\n");
}

void readHuffTree(Huffman ht){
    int i = 1,j;
    FILE *HuffTree = Fopen("�����ĵ�.txt","r");
    while((fscanf(HuffTree,"%d | %d | %d | %d | %d\n",i,(ht)[i].weight,(ht)[i].LChild,(ht)[i].RChild))){
        i++;
    }
    Fclose(HuffTree);
    printf("�Ѿ��Ӳ����ĵ�.txt��ȡ��������\n");
}

void saveHuffCode(Huffman ht,char *ch,HuffmanCode leafCode,LeafNode leaves,int chLen,int leafNum){
    int i;
    FILE *HuffCode = Fopen("�����ĵ�.txt.zip��ѹ��.txt","a");
    CrtHuffmanNodeCode(ht,ch,leafCode,leaves,chLen,leafNum);//Ҷ�ӽ��ı���
    printf("\nÿ��Ҷ�ӽڵ��ǰ׺���ǣ�\n");//��ӡҶ�ӽڵ�ı���
    for(i=1;i<=leafNum;i++){
        printf("%c:%s\n",leaves[i].c,leafCode[i]);
        fprintf(HuffCode,"%c:%s\n",leaves[i].c,leafCode[i]);
    }
    Fclose(HuffCode);
    printf("ÿ��Ҷ�ӽڵ��ǰ׺���Ѿ����浽�����ĵ�.txt.zip��ѹ��.txt\n");
}

void readHuffCode(HuffmanCode leafCode){
    int i=1;
    char c,temp[10];
    FILE *HuffCode = Fopen("�����ĵ�.txt.zip","r");
    while((fscanf(HuffCode,"%c:%s\n",&c,temp)) == 2){
        int len = strlen(temp);
        leafCode[i] = (char *)malloc(len*sizeof(char));
        strcpy(leafCode[i],temp);
        printf("%c:%s\n",c,leafCode[i]);
        i++;
    }
    Fclose(HuffCode);
    printf("�Ѿ��Ӳ����ĵ�.txt.zip��ȡ��ÿ��Ҷ�ӽڵ���Ϣ\n");
}


//���������ַ��ı���
void CrtHuffmanCode(char ch[],HuffmanCode leafCode,HuffmanCode chCode,LeafNode leaves,int leafNum,int chLen){
    int i,k;
    for(i=0;i<chLen;i++){
        for(k=1;k<=leafNum;k++){
            //��weight[k].c�в�����ch[i]��ȵ��±�k
            if(ch[i]==leaves[k].c){
                break;
            }
            chCode[i] = (char *)malloc((leaves[k].num)*sizeof(char));
            strcpy(chCode[i],leafCode[k]);//���������Ʊ���
        }
    }
}

void saveCodeFile(char *ch,HuffmanCode leafCode,HuffmanCode chCode,LeafNode leaves,int leafNum,int chLen){
    FILE *codeFile = Fopen("�����ĵ�.txt.zip��ѹ��.txt","a");
    CrtHuffmanCode(ch,leafCode,chCode,leaves,leafNum,chLen);
    printf("\n�ַ������룺");//��ӡ�ַ����ı���
    int i;
    for(i=0;i<chLen;i++){
        fputs(chCode[i],codeFile);
    }
    Fclose(codeFile);
    printf("\n�ַ����Ĺ����������Ѿ����浽�����ĵ�.txt.zip��ѹ��.txt\n");
}

//����������
void TraHuffmanTree(Huffman ht,LeafNode w,HuffmanCode hc,int n,int m){
    int i=0,j,p;
    FILE *str2 = Fopen("�����ĵ�.txt.zip��ѹ��.txt","a");
    printf("\n����ѹ�õ���ԭ�ļ����ַ���Ϊ��");
    while(i<m){
        p=2*n-1;
        for(j=0;hc[i][j]!='\0';j++){
            printf("dddd");
            if(hc[i][j]=='\0')
                p=ht[p].LChild;
            else
                p = ht[p].RChild;
            //printf("%c",w[p].c);//��ӡԭ��Ϣ
        }
        
        fputs(&w[p].c,str2);
        i++;
    }
    Fclose(str2);
    printf("\n�ѽ���ѹ�õ����ַ������浽�����ĵ�.txt.zip��ѹ��.txt\n");
}

//�ͷ�Huffman�����ڴ�
void FreeHuffmanCode(HuffmanCode h1,HuffmanCode h2,HuffmanCode hc,int leafNum,int chLen){
    int i;
    for(i=1;i<=leafNum;i++){
        //�ͷ�Ҷ�ӽڵ�
        free(h1[i]);
        free(h2[i]);
    }
    for(i=0;i<chLen;i++){
        //�ͷ����нڵ�
        free(hc[i]);
    }
}

int main(void){
    printf("��ȡ��Ҫѹ�����ļ������ĵ�.txt��\n");
    char ch[N];
    readFile("�����ĵ�.txt",ch);
    
    int chLen = N;
    LeafNode leaves;//���Ҷ�ӽ�����Ϣ
    int leafNum=0;//Ҷ�ӽڵ�ĸ���
    CreateLeaf(ch,&chLen,leaves,&leafNum);//����Ҷ�ӽ����Ϣ
    Huffman htree;
    saveHuffmanTree(htree,leaves,leafNum);//���ɲ�����HuffTree
    Huffman htree2;
    readHuffTree(htree2);
    HuffmanCode leafCode1;//leafCode1�ַ�ָ������ֱ���ÿ��Ҷ�ӽڵ�ı��벢�ұ���
    //saveHuffCode(htree2,ch,leafCode1,leaves,chLen,leafNum);
    HuffmanCode leafCode2;
    readHuffCode(leafCode2);
    HuffmanCode chCode;//chCode��ch˳�������нڵ�ı���
    saveCodeFile(ch,leafCode2,chCode,leaves,leafNum,N);
    TraHuffmanTree(htree2,leaves,chCode,leafNum,chLen);//����
    FreeHuffmanCode(leafCode1,leafCode2,chCode,leafNum,chLen);
    return 0;
}