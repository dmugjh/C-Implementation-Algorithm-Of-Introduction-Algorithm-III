/*************************************************************************
	> File Name: 2.3-merge_sort.c
	> Author: syncher 
	> Mail: syncher@qq.com 
	> Description: <<算法导论第三版>> page 17 merg_sort 
	> Created Time: Wed Mar 15 18:08:34 2017
 ************************************************************************/
#include<stdio.h>

/**
 * Description: 合并两个有序数组得到新的有序数组A
 * @param A: 数组指针
 * @param p: 起点 
 * @param q: 中间点,并非中点
 * @param r: 终点
 * @return: void
 */
void  MERGE(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - p;
    int L[101] = {0};
    int R[101] = {0};
    //将A[p,..,q]中数据存入新的数组L
    for (int i = 1; i <= n1; i++)
    {
       L[i] = A[p + i -1]; 
    }
    return;
}
int main()
{
    
}

/*************************************************************************
	> Run Environment: CentOS 64 6.7 + Clang 3.4.2 
	> Test input:  
	> Result:  
	> Summary: 
 ************************************************************************/

