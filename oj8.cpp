#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

void solvepolyments(double* index, double* xValues, double* polyments, double* yValues, int n)//牛顿法求解多项式
{
    for (int i = 0; i < n; i++)
    {
        index[(i + 1) * i / 2] = 1;
    }//系数矩阵第一列均为1
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i; j++)
        {
            index[(i + 1) * i / 2 + j] = index[(i + 1) * i / 2 + j - 1] * (xValues[i] - xValues[j - 1]);
        }
    }//按照牛顿法求解构造系数矩阵
    polyments[0] = yValues[0];
    for (int i = 1; i < n; i++)
    {
        double p = 0;
        for (int j = 0; j < i; j++)
        {
            p += index[(i + 1) * i / 2 + j] * polyments[j];
        }
        polyments[i] = (yValues[i] - p) / index[(i + 1) * i / 2 + i];//根据系数矩阵与输出y的关系求解多项式各系数
    }
}
int main() {
    int n, m;
    double* index;//系数矩阵
    double* xValues;//x输入
    double* yValues;//y输出
    double* polyments;//多项式系数
    double a1, b1;
    int j = 0;
    scanf("%d %d", &n, &m);
    index = (double*)malloc(sizeof(double) * (n + 1) * n / 2);
    xValues = (double*)malloc(sizeof(double) * n);
    yValues = (double*)malloc(sizeof(double) * n);
    polyments = (double*)malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &a1, &b1);//输入一个点的x和y
        if (i >= 1)
        {
            int flag = 0;
            if (n >= 40)
            {
                for (int t = 0; t < i; t++)
                {
                    if (fabs(a1 - xValues[t]) <= 0.1)//判断点与点之间距离是否过小，过小舍弃该点以降低最终输出病态性
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else
            {
                for (int t = 0; t < i; t++)
                {
                    if (fabs(a1 - xValues[t]) <= 0.01)//判断点与点之间距离是否过小，过小舍弃该点以降低最终输出病态性
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)//点与点之间距离合适
            {
                xValues[j] = a1;
                yValues[j] = b1;
                j++;//存入输入输出数组以进行后续插值
            }
        }
        else
        {
            xValues[j] = a1;
            yValues[j] = b1;
            j++;
        }
    }
      n = j;//n等于进行拟合点的个数
    solvepolyments(index, xValues, polyments, yValues, n);//求解插值多项式系数
    int max = 0;//多项式最大次数初始化
    for (int i = n - 1; i >= 0; i--)//从最高项向低次遍历
    {
        if (fabs(polyments[i]) >= 0.0001)//多项式最高次项系数绝对值大于0.0001，可认为该项有影响，此即最高次项
        {
            max = i;
            break;
        }
    }
    printf("%d\n", max);//输出次数
    for (int i = 0; i < m; i++)
    {
        double bb;
        scanf("%lf", &bb);//输入新的x值进行拟合
        double value = 0;
        double ji = 1;
        for (int j = 0; j <= max; j++)
        {
            value += polyments[j] * ji;
            ji *= bb - xValues[j];
        }//依据拟合的多项式求解对应y
        printf("%lf\n", value);//输出y
    }
    free(index);
    free(xValues);
    free(yValues);
    free(polyments);//释放对应内存
    return 0;
}
