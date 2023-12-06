#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	long long int number = 0;
	long long int K, M;
	long long int H;
	scanf("%lld %lld %lld", &M, &K, &H);
	if (M >= 2000)
	{
		int height[120000] = { 0 };
		vector< int> heights;
			for (long long int i = 0; i < M; i++)
			{
				scanf("%lld", &height[i]);
				if (i <= K)heights.push_back(height[i]);//在第0个元素可以达到的范围内操作
			}
			sort(heights.begin(), heights.end());//对开头K个元素排序
			for (long long int i = 0; i < M; i++)
			{
				long long int current = height[i];
				std::vector< int> ::iterator q = lower_bound(heights.begin(), heights.end(), current);//找到第i个元素在排好序队伍的位置
				q = heights.erase(q);//将第i个元素删除
				long long int ce, cb;
				if (current - H < 0)ce = 0;
				else ce = current - H;//第i个元素能跳到的下限
				if (current + H > heights[K])cb = heights[K];
				else cb = current + H;//第i个元素能跳到的上限
				std::vector<int> ::iterator p = lower_bound(heights.begin(), heights.end(), ce);//寻找队伍中下限位置
				std::vector<int> ::iterator s = upper_bound(heights.begin(), heights.end(), cb);//寻找队伍中上限位置
				number += s - p;//在该位置能跳到的地方由s-p个
				if (i < M - K - 1)
				{
					std::vector<int> ::iterator insert0 = upper_bound(heights.begin(), heights.end(), height[i + K + 1]);//找到第i+K+1个元素在排好队伍中位置
					insert0 = heights.insert(insert0, height[i + 1 + K]);//在该位置填入第i+K+1个元素，成为有序的，第K+1个元素所能跳到的所有元素队伍
				}
			}
	}
	else
	{
		int height[150000] = { 0 };
		number = 0;
		for (long long int i = 0; i < M; i++)
		{
			scanf("%lld", &height[i]);
		}
		for (long long int i = M; i < M + K + 1; i++)
		{
			height[i] = -1;
		}
		for (long long int i = 0; i < M; i++)
		{
			for (long long int j = i + 1; j < i + K + 1; j++)
			{
				if (height[j] >= 0)
				{
					int d = height[j] - height[i];
					if ((d >= (-1) * H) && (d <= H))
					{
						number++;
					}
				}
			}
		}
	}
	printf("%lld", number);
	return 0;
}
