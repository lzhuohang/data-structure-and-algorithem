#include<iostream>
#pragma warning(disable: 4996)
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int N;
    cin >> N;//输入学生人数
    int a;//定义缓存整型数
    int b[10][10] ={0};//定义二维数组，行代表输入值的位序号（亿……十、个位），列代表该位置的数字（0、1、2……9）
    int d[10] = { 0 };//定义最终输出学号的数字序列，每一个数组成员的值代表其对应位序数值
    int p=0;//初始化最终输出学号
    for (int i = 0; i < 3 * N - 1; i++)
    {
        cin >> a;
        int c[10] = { 0 };
        int M = 1000000000;
        for (int j = 0; j < 10; j++)
        {
            c[j] = a/ M;
            a = a - M * c[j];
            M = M / 10; //利用c[]数组提取出输入学号的每一位数
            b[j][c[j]]++;//b数组对应位置加一
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (b[i][j] % 3 != 0)//找出每一位序中不能被3整除的数值（说明此数值有被加过两次而不是三次，也就是说该值就是缺失学号该位置的数值）
                d[i] = j;//（提取出缺失学号的数字序列）
        }
    }
    for (int i = 0; i < 10; i++)
    { 
        p *= 10;
        p += d[i];//求出该缺失学号
    }
    cout << p;
    return 0;
}
