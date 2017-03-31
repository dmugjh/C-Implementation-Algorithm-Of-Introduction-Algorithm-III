/*************************************************************************
	> File Name: 4.2-square_matrix_multiply.c
	> Author: syncher 
	> Mail: syncher@qq.com 
	> Description:《算法导论》第三版 Page 43 矩阵乘法普通算法  
	> Created Time: Fri Mar 31 08:18:21 2017
 ************************************************************************/
#include<stdio.h>
#define MAX_MATRIX_LENGTH 51   //规定矩阵最大长度
int A[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH];
int B[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH];
//定义结果矩阵
int C[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH];
void SquareMatrixMultiply(int A[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH], int B[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH], int n);


int main(void)
{
    int n = 0;
    int i, j;
    
    //输入矩阵长度n
    printf("Please intput the length of the Matrix(n should be less then 50):");
    scanf("%d", &n);
    //矩阵输入
    printf("Please intput the  square Matrix A which length is %d:\n", n);
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++)
        {
           scanf("%d", &A[i][j]);
        }
    }
    printf("\n Please intput the  square Matrix B which length is %d:\n", n);
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++)
        {
           scanf("%d", &B[i][j]);
        }
    }

    //计算矩阵乘积
    SquareMatrixMultiply(A, B, n);

// result output
    printf("\n The result is:\n");
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++)
        {
            printf(" %d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/**
 * @Description: 常规方法计算算法矩阵乘法
 * @param: int * A  矩阵A的地址（n*n 的二维数组）
 * @param: int * B  矩阵B的地址（n*n 的二维数组）
 * @param: int n  矩阵的长度
 * @return: int * C 矩阵乘积的地址
 */
void SquareMatrixMultiply(int A[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH], int B[MAX_MATRIX_LENGTH][MAX_MATRIX_LENGTH], int n)
{
   int i, j, k;

   for (i = 1; i<= n; i++)
   {
        for (j = 1; j <= n; j++)
        {
            C[i][j] = 0; // 初始化
            for (k = 1; k <= n; k++)
            {
                C[i][j] += (A[i][k] * B[k][j]); 
            }
        }
   }
    return;
}

/*************************************************************************
	> Run Environment: CentOS 64 6.7 + Clang 3.4.2 
	> Test input: 
    >2
    >
    >1 1
    >1 0
    >
    >1 1 
    >1 0
	> Result:  
    >2 1
    >1 1 
	> Summary: 虽然算法很容易理解但是算法复杂度为O(n^3) 
 ************************************************************************/

