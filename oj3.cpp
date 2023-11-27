#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define M 1000000
int soldiers[M], sta[M], near[M], top, n;
long long ans;
int main()
{
	int N; 
	scanf("%d", &N);
	for (int i = 0; i <= N-1; i++)
	{
		int x; 
		scanf("%d", &x);
		if (x == soldiers[n]) near[n]++;//遇到相邻士兵武力值一样，将其合并为一组，组里人数near++
		else { soldiers[++n] = x; near[n] = 1; }//相邻士兵武力值不同，则构成新组，新组人数初始化为1，战力记为soldiers
	}
	for (int i = 1; i <= n; i++)//遍历n组士兵
	{
		ans += (near[i] - 1) * near[i] / 2;//小组之间内斗，n人小组两两之间内斗，共n（n-1）/2次
		while ((top) && (soldiers[sta[top]]<soldiers[i]))//新的元素武力值大于栈顶武力值
		{
			if (top > 1)
			{
				ans += near[sta[top]] * 2;
			}
			else ans += near[sta[top]];
			top--;//栈顶组出栈，并与该组士兵第一个（不能跟后面的，因为第一个比出栈武力值高）
			//和栈中上一个组士兵最后一个（同理不能跟更前面的）打，一共两次；如果已达栈底，只需跟该组士兵第一个打，共一次
		}//依次遍历栈完成出栈操作，直至栈顶武力值大于改组武力值
		if (soldiers[i] == soldiers[sta[top]])//该组士兵武力值和栈顶武力值相同
		{
			ans += near[i] * near[sta[top]];//这两个组士兵已完成组内内斗，进行组间内斗，次数为两组人数相乘
			near[sta[top]] += near[i];//将该组士兵合并入栈顶
		}
	  else {
		top++;
		sta[top] = i;
		   }//该组士兵入栈
	}
	while (top>1)
	{
		ans += near[sta[top]];
		top--;//完成n遍历得到最终栈，从大到小排列，栈顶组还可以与栈前面相邻组第一个打一次，打完以后出栈；栈底不打
	}
	printf("%lld", ans);//输出结果
	return 0;
}
