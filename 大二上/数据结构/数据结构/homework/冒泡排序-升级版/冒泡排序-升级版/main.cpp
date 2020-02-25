//任务名：任务11-4
//姓名：王亚红
//学号：2017011743
//班级：2017级2班
//日期：2018/12/24

#include<stdio.h>

#define MAXSIZE 100

typedef int KeyType;

typedef struct{
    KeyType r[MAXSIZE+1];
    int length;
}SqList;
 
//改进版的冒泡排序(双向冒泡)
void BidBubbleSort(SqList *L, int n)
{
    int low, high, flag, i;
    low = 0;
    high = n - 1;
    while(low < high){
        flag=0;
        for(i=low; i<high; i++) //正向冒泡
        {
            if(L->r[i] > L->r[i+1]) //找到剩下中最大的
            {
                int temp = L->r[i];
                L->r[i] = L->r[i+1];
                L->r[i+1] = temp;
                flag = 1;    //标志，说明有数据交换
            }
        }
        if( !flag )
            break;
        high--;
        for( i=high; i>low; i-- ) //反向冒泡
        {
            if(L->r[i] < L->r[i-1]){
                //找到剩下中最小的
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
    printf("请输入数组的长度：");
    scanf("%d",&arr.length);
    //依次输入数组元素
    printf("请依次输入数组元素：");
    for(i=0;i<arr.length;i++){
        scanf("%d",&arr.r[i]);
    }
    BidBubbleSort(&arr,arr.length);
    printf("经双向冒泡排序后，数组为：\n");
    int j;
    for(j=0;j<arr.length;j++){
        printf("%d\n",arr.r[j]);
    }
    return 0;
}




/*
#include<stdio.h>
 
#define Max_ 10
 
// 打印结果
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}
 
// 交换数组元素位置
void Swap( int *num_a, int *num_b )
{
    int temp = *num_b;
    *num_b = *num_a;
    *num_a = temp;
}
 
//改进版的冒泡排序(双向冒泡)
void BidBubbleSort(int array[], int n)
{
    int low, high, flag, i;
    low = 0;
    high = n - 1;
    while(low < high)
    {
        flag=0;
        for(i=low; i<high; i++)  //正向冒泡
        {
            if(array[i] > array[i+1]) //找到剩下中最大的
            {
                Swap(&array[i], &array[i+1]);
                flag = 1;    //标志， 有数据交换
            }
        }
        if( !flag )
            break;
        high--;
        for( i=high; i>low; i-- ) //反向冒泡
        {
            if(array[i] < array[i-1])   //找到剩下中最小的
                Swap(&array[i], &array[i-1]);
        }
        low++;
    }
}
 
int main()
{   //测试数据
    int arr_test[Max_] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
    //排序前数组序列
    Show( arr_test, Max_ );
    BidBubbleSort( arr_test, Max_);
    //排序后数组序列
    Show( arr_test, Max_ );
    return 0;
}*/

/*
//单向起泡排序
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