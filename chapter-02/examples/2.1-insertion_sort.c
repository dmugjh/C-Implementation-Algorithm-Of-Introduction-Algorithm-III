/*************************************************************************
	> File Name: insertion_sort.c
	> Author: syncher 
	> Mail: syncher@qq.com 
	> Description:算法导论第三版 Page 10 Chapter 2 INSERTION-SORT
	> Created Time: Tue Mar 14 08:59:32 2017
 ************************************************************************/
#include<stdio.h>

/**
 * @pram A: 待排序的数组的指针
 * @pram len: 数组的长度
 * @return void;
 */
void INSERTION_SORT(int * A,int len)
{
    int i, key;
    for (int j = 2; j <= len; j++)
    {
        key = A[j];
        i = j-1;
        while (key < A[i] && i >= 1) // 数组从1号开始
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
    return;
}

/**
 * 主函数:测试INSERTION-SORTRT
 */
int main(void)
{
    int A[101] = {0};
    int len;
    
    printf("Please input the length of the test Array (should be less then 100):");
    scanf("%d",&len); 
    printf("Please input %d numbers:\n",len);
    int i = 1;
    while (i <= len)
    {
        scanf("%d",&A[i]);
        i++;
    }

    printf("Your input number is:\n");
    i = 1;
    while (i <= len)
    {
        printf("%d ",A[i]);
        i++;
    }

    INSERTION_SORT(&A[0],len);  //sorting
    printf("\nSorted by INSERTION-SORT is:\n");
    i = 1;
    while (i <= len)
    {
        printf("%d ",A[i]);
        i++;
    }
    return 0;
}
/*************************************************************************
	> Run Environment: CentOS 64 6.7 + Gcc 
    > Test input: 9 [ENTER] 9 8 7 6 5 4 3 2 9 [ENTER]
	> Result: 2 3 4 5 6 7 8 9 9   
	> Summary: 插入排序的思想是将下标为j的元素插入到已经有序的j-1个元素中,使得j个元素有序.排序时,先将A[j]与A[1,..,j-1]
    > 每个元素比较,当A[j]大于某个元素i时,将A[j]插入到第i号元素之后,因此每次比较如果A[j]<A[i]成立,则需要将i号元素后移赋值给i+1.
 ************************************************************************/

