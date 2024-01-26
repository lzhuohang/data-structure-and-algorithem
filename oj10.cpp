#include <iostream>
#include <vector>
using namespace std;

struct tensor//存储dp数组张量结构与次数
{
    int former = 0;//按照二进制记录当前张量前k-2维的情况，大于1该位为1，等于1该位为0
    unsigned short dim1;//k-1维
    unsigned short dim2;//k维
    int mintimes;//需要的最小乘法次数
    int times = 1;//计算前k-2维相乘的结果
};
int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<vector<tensor>> dp(n, vector<tensor>(n)); 
    vector<int> fom(k - 2, 1);//存储张量前k-2维的大于1的值
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 2; j++)
        {
            int tempt;
            cin >> tempt;//输入第j维的值
            if (tempt > 1) { dp[i][i].former |= (1 << j); fom[j] = tempt; }//former该位置bool值为1，更新fom数组
            else { dp[i][i].former &= ~(1 << j); }//former该位置bool值为0
            dp[i][i].times *= tempt;//递推计算times的值
        }//对前k-2维处理，同时将该维度大于1的值存储在fom里
        cin >> dp[i][i].dim1;//输入k-1维
        cin >> dp[i][i].dim2;//输入k维
    }
    for (int j = 1; j < n; j++)//从列开始从左往右遍历构造dp数组
    {
        for (int i = j - 1; i >= 0; i--)//从该列最下一行开始向上构造
        {
            int min = 2147483647;
            int t = dp[i][i].former | dp[i + 1][j].former;//取两者或运算，判断新张量哪些位置bool值为1
            for (int i1 = 0; i1 < k - 2; i1++)//构造dp[i][j]的张量结构
            {
                if (t % 2 == 0) { dp[i][j].former &= ~(1 << i1); }
                else { dp[i][j].former |= (1 << i1);dp[i][j].times*= fom[i1]; }
                t = t / 2;
                if (t == 0)break;
            }
            dp[i][j].dim1 = dp[i][i].dim1;
            dp[i][j].dim2 = dp[i + 1][j].dim2;
            for (int m = i; m < j; m++)//进行递推，计算dp[i][j]的最小乘法次数
            {
                if ((dp[i][m].mintimes + dp[m + 1][j].mintimes + dp[i][m].times * dp[i][m].dim1 * dp[i][m].dim2 * dp[m + 1][j].dim2 < min))
                {//如果i到m的最小次数加m+1到j的最小次数加这两个状态后2维相乘的次数小于当前最小次数则往下进行
                    int temp = dp[i][m].times;//用temp计算次数
                    int t = (dp[i][m].former | dp[m + 1][j].former) - dp[i][m].former;
                    for (int i1 = 0; i1 < k - 2; i1++)
                    {
                        if (t % 2 != 0) temp *= fom[i1];
                        t = t / 2;
                        if (t == 0)break;
                    }
                    temp *= dp[i][m].dim1 * dp[i][m].dim2 * dp[m + 1][j].dim2;
                    temp += dp[i][m].mintimes + dp[m + 1][j].mintimes;//这种情况下i到j的乘法次数
                    if (temp < min)//逐渐选择最小值
                    {
                        min = temp;
                        dp[i][j].mintimes = temp;
                    }
                }
            }
        }
    }
    cout << dp[0][n - 1].mintimes << endl;//i=0，j=n-1时，即0到n-1的最小乘法次数
    return 0;
}
