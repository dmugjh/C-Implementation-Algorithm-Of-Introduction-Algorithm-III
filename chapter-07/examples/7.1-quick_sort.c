/*************************************************************************
	> File Name: quick_sort.c
	> Author: syncher 
	> Mail: syncher@qq.com 
	> Description:  算法导论第7章  page 95  快速排序实现
	> Created Time: Mon Mar 20 16:13:47 2017
 ************************************************************************/
#include<stdio.h>
int PARTITION(int *A, int low, int high);

/**
 * @description: 快速排序主方法
 * @param:  int * pA 待排序数组的指针
 * @param: int  low 排序起始位置
 * @param: int high 排序终止位置
 * @return: void
 */
 void QUICK_SORT(int *A, int low, int high)
 {
     if (low < high)
     {
         int pos = PARTITION(A,low,high);
         QUICK_SORT(A,low,pos-1);  
         QUICK_SORT(A,pos+1,high);
     }
     return;
 }


/**
 * @Description: 快速排序的核心方法，找出一个位置pos使得pos左侧全部小于等于A[pos],右侧全部大于等于A[pos]
 * @param: int * A 待排序数组的地址
 * @param: int low 排序起始位置
 * @param: int high 排序终止位置
 * @return: int pos 返回一位置
 */
int PARTITION(int *A, int low, int high)
{
    int tmp = A[high];
    int i = low - 1; //i的起始位置要在low前一位
    int j;

    for (j = low; j <= high-1; j++ )
    {
        if (A[j] <= tmp)
        {
            i++;
            //坑：要交换的两个数如果指向同一片存储区域那么省略交换步骤
            //交换A[i]与A[j]
            if (i != j)
            {
                A[i] ^= A[j];
                A[j] ^= A[i];
                A[i] ^= A[j];
            }
        }
    }
    // for循环结束后第A[i]的值实际上是大于tmp的，因此需要与tmp交换
    if (high != i+1)
    {
        A[high] ^= A[i+1];
        A[i+1] ^= A[high];
        A[high] ^= A[i+1];
    }
    
    return i+1;    
}

//---------------------------数测试快速排序----------------------------//
 int main(void)
 {
     int A[101] = {0};
     
     // data input
     printf("Please input 10 integral numbers for a test: \n");
     int i = 1;
     while (i <= 10)
     {
        scanf("%d",&A[i]);
        i++;
     }

     //sorting && output
     printf("Your input number is: \n");
     i = 1;
     while (i <= 10)
     {
        printf(" %d ",A[i]);
        i++;
     }

     QUICK_SORT(A,1,10); //数组名作函数参数相当于传递指针

     printf("\nThe sorting results is: \n");
     i = 1;
     while (i <= 10)
     {
        printf(" %d ",A[i]);
        i++; 
     }
    
     return 0;
 }
/*************************************************************************
	> Run Environment: CentOS 64 6.7 + Clang 3.4.2 
    > Test input: 
    > 5  4  5  2  67  5  7  89  3  1 
    > Results: 
    > 1  2  3  4  5  5  5  7  67  89 
	> Summary: 快速排序的核心是找到递归位置，PARTITION方法的复杂度是O(n),快速排序的期望算法复杂度是nlog(n),
    > 最坏情况下是O(n^2).
 ************************************************************************/

