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
void INSERTION-SORT(int *A,int len)
{
    int i, key;
    for (int j = 2; j <= len; j--)
    {
        key = A[j];
        i = j-1;
        while (A[j] < A[i] && i >= 1) // 数组从1号开始
        {
            
        }
    return;
}

/*************************************************************************
	> Run Environment: CentOS 64 6.7 + Gcc 
	> Test input:  
	> Result:  
	> Summary: 插入排序的思想是将下标为j的元素插入到已经有序的j-1个元素中,使得j个元素有序.排序时,先将A[j]与A[1,..,j-1]
    > 每个元素比较,当A[j]大于某个元素i时,将A[j]插入到第i号元素之后,因此每次比较如果A[j]<A[i]成立,则需要将i号元素后移赋值给i+1.
 ************************************************************************/

