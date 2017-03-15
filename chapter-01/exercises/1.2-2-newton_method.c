/*************************************************************************
> File Name: 1.2-2-NewtonMethod.c
> Author: syncher 
> Mail: syncher@qq.com 
> Description: 大写  
> Created Time: Wed Mar 15 17:14:02 2017
************************************************************************/
#include<stdio.h>
#include<math.h>
int main()
{
    double x, x0, fun, fun_Derivative;
    printf("Input a number near by the resolution:");
    scanf("%lf", &x);
    
    do
    {
        x0 = x;
        fun = x - 8*log(x)/log(2);
        fun_Derivative = 1 - 8/(x * log(2));
        x = x0 - fun/fun_Derivative;

    } while (fabs(x-x0) >= 1e-5);
    printf("The resolution of the function is:%lf\n",x);
    return 0;
}

/*************************************************************************
> Run Environment: CentOS 64 6.7 + Gcc 
> Test input: 40  
> Result:  43 
> Summary: 牛顿法求函数的零点. 如果函数f(x)在x0附近有解,则:f(x0) = f'(x0)(x-x0) ==> x1 = x0 - f(x0)/f'(x0) 
> 进而推出xn+1 = xn - f(xn)/f'(xn),当|xn+1 -xn| 小于要求精度使,xn或xn+1即可近似为函数的零点.
> 本例求解的是插入排序和归并排序的运行时间的交叉点,8n^2 = 64nlgn的解,因此可以利用牛顿法求n.
> 当输入40的时候解得n=43.因此在本例中n<43时插入排序优与快速排序.
************************************************************************/

