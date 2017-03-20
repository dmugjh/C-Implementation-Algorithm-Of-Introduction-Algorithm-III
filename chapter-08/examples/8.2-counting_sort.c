/*************************************************************************
	> File Name: 8.2-counting_sort.c
	> Author: syncher 
	> Mail: syncher@qq.com 
	> Description:  《算法导论》中文第三版 page 108 计数排序
	> Created Time: Mon Mar 20 21:26:11 2017
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>

/**
 * @description: 计数排序使用于输入规模为n的所有元素都在[0,k]区间内的排序，这是一个线性排序算法，算法复杂度为O(n).
 * 该算法的思路是：对于每一个输入元素x，要确定小于x的元素个数m，确定好个数m后，即可确定x在m+1位置。计数排序难点在于如
 * 何确定小于x的数的个数，解决这一问题首先确定0-k内每个数值在待排序中出现的次数，这样比数值x小的数的个数就是x前面的所
 * 有数出现次数之后。
 * @param int * pA 带排序的数组指针
 * @param int * pB 排序完成输出数组指针
 * @param int k 带排序数列最大值
 * @param int len_A 数组A的有效长度
 * @return void
 */
 void COUNTING_SORT(int *pA, int *pB, int k, int len_A)
 {
    //动态分配数组，自动初始化为0，用完序手释放内存，辅助数组，用来存储数值为k的元素出现的次数
    int * pC = (int *)calloc(len_A,sizeof(int));
    for (int j = 1; j <= len_A; j++ )
    {
        pC[pA[j]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        pC[i] += pC[i-1];
    }

    for (int j = len_A; j >= 1; j--)
    {
        pB[pC[pA[j]]] = pA[j];
        pC[pA[j]]--; 
    }
    return;
 }


int getMAX(int *pA, int len_A)
{
    int k = pA[0];    
    int i = 1; //数组从1开始计数
    while (i <= len_A)
    {
        if (pA[i] > k)
        {
            k = pA[i];
        }
        i++;
    }
    return k;
}

int main(void)
{
    int A[101] = {0};
    int B[101] = {0};
    int len_A = 0;

    printf("Please input the length of the array A:");
    scanf("%d", &len_A);
    printf("Please input %d data:\n",len_A);
    int i = 1;
    while (i <= len_A)
    {
        scanf("%d",&A[i]);    
        i++;
    }
   

    printf("Your input number is:\n");
    i = 1;
    while (i <= len_A)
    {
        printf(" %d ", A[i]);
        i++;
    }
    //加一个获取最大值的函数，在实际情况中最大值应该知道的
   int k = getMAX(&A[0], len_A);
    //sorting
    COUNTING_SORT(&A[0],&B[0],k,len_A);
    //output
    printf("\nThe sorting result is:\n");
    i = 1;
    while (i <= len_A)
    {
        printf(" %d ", B[i]);
        i++;
    }
   
return 0;
}

/*************************************************************************
	> Run Environment: CentOS 64 6.7 + Clang 3.4.2 
    > Your input number is:
    > 2  5  3  0  2  3  0  3 
    > The sorting result is:
    > 0  0  2  2  3  3  3  5 
 ************************************************************************/

