//������������11-4
//���������Ǻ�
//ѧ�ţ�2017011743
//�༶��2017��2��
//���ڣ�2018/12/24

#include<stdio.h>

#define MAXSIZE 100

typedef int KeyType;

typedef struct{
    KeyType r[MAXSIZE+1];
    int length;
}SqList;
 
//�Ľ����ð������(˫��ð��)
void BidBubbleSort(SqList *L, int n)
{
    int low, high, flag, i;
    low = 0;
    high = n - 1;
    while(low < high){
        flag=0;
        for(i=low; i<high; i++) //����ð��
        {
            if(L->r[i] > L->r[i+1]) //�ҵ�ʣ��������
            {
                int temp = L->r[i];
                L->r[i] = L->r[i+1];
                L->r[i+1] = temp;
                flag = 1;    //��־��˵�������ݽ���
            }
        }
        if( !flag )
            break;
        high--;
        for( i=high; i>low; i-- ) //����ð��
        {
            if(L->r[i] < L->r[i-1]){
                //�ҵ�ʣ������С��
                int temp = L->r[i];
                L->r[i] = L->r[i - 1];
                L->r[i - 1] = temp;
            }
        }
        low++;
    }
    
}
 
int main(void)
{ 
    SqList arr;
    int i;
    printf("����������ĳ��ȣ�");
    scanf("%d",&arr.length);
    //������������Ԫ��
    printf("��������������Ԫ�أ�");
    for(i=0;i<arr.length;i++){
        scanf("%d",&arr.r[i]);
    }
    BidBubbleSort(&arr,arr.length);
    printf("��˫��ð�����������Ϊ��\n");
    int j;
    for(j=0;j<arr.length;j++){
        printf("%d\n",arr.r[j]);
    }
    return 0;
}




/*
#include<stdio.h>
 
#define Max_ 10
 
// ��ӡ���
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}
 
// ��������Ԫ��λ��
void Swap( int *num_a, int *num_b )
{
    int temp = *num_b;
    *num_b = *num_a;
    *num_a = temp;
}
 
//�Ľ����ð������(˫��ð��)
void BidBubbleSort(int array[], int n)
{
    int low, high, flag, i;
    low = 0;
    high = n - 1;
    while(low < high)
    {
        flag=0;
        for(i=low; i<high; i++)  //����ð��
        {
            if(array[i] > array[i+1]) //�ҵ�ʣ��������
            {
                Swap(&array[i], &array[i+1]);
                flag = 1;    //��־�� �����ݽ���
            }
        }
        if( !flag )
            break;
        high--;
        for( i=high; i>low; i-- ) //����ð��
        {
            if(array[i] < array[i-1])   //�ҵ�ʣ������С��
                Swap(&array[i], &array[i-1]);
        }
        low++;
    }
}
 
int main()
{   //��������
    int arr_test[Max_] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
    //����ǰ��������
    Show( arr_test, Max_ );
    BidBubbleSort( arr_test, Max_);
    //�������������
    Show( arr_test, Max_ );
    return 0;
}*/

/*
//������������
void BubbleSort(int a[],int n){
    bool change = true;
    int i,j;
    for(i = n-1;i>=1 && change;--i){
        change = false;
        for(j=0;j<i;++j){
            if(a[j]>a[j+1]){
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                change = true;
            }
        }
    }
}


int main(void){
    int a[] = {5,4,6,2,1};
    int n = 5;
    BubbleSort(a,5);
    int m;
    for(m = 0;m<n;m++){
        printf("%d\n",a[m]);
    }
    return 0;
}
*/