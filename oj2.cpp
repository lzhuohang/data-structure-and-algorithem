#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
    int N;//指令数量
	int a[100001][2] = { 0 };//定义a[x][y]数组，其中x表示同学编号（1-100001），y取值0表示x前面人编号，取值1表示x后面人的编号；其中a[0][0]表示排尾编号，a[0][1]表示排头编号
	scanf("%d", &N);//输入N
	a[0][0] = 1;
	a[0][1] = 1;//开始时排头排尾编号均为1
	for (int j = 0; j < N; j++)//执行指令
	{
		int r, s, t;
		scanf("%d", &r);
		if (r == 1)
		{
			scanf("%d %d", &s,&t);
		}
		else
		{
			scanf("%d", &s);
		}
		if (r == 1)//指令为1xy情况
		{
			int x = s;
			int y = t;
			if (x != 0)//x不为0
			{
						int g = a[x][1];//x原来后面的编号g
						a[x][1] = y;//x后面编号变为y
						a[y][0] = x;//y前面编号变为x
						a[y][1] = g;//y后面编号变为g
						a[g][0] = y;//g前面编号变为y
			}
			else //x为0
				{
					int m = a[0][1];//原排头编号m
					a[0][1] = y;//新排头变为y
					a[m][0] = y;//m前面编号变为y
					a[y][1] = m;//y后面编号变为m
					a[y][0] = 0;//y前面编号变为0（没人）
				}
		}
		else if (r == 2)//指令为2x情况
		{
			int x = s;
			if (x == 0)
			{
				printf("%d\n", a[0][1]);//报告排头编号
			}
			else 
			{
			if(x==a[0][0]){ printf("%d\n",0); }//如果是排尾报告0
			else { printf("%d\n", a[x][1]); }//如果不是排头和排尾直接报告后面同学编号
			}
		}
		else//指令为3x情况
		{
			        int x = s;
					int p = a[x][0];//x前面编号p
					int q = a[x][1];//x后面编号q
					a[p][1] = q;//p后面编号变为q
					a[q][0] = p;//q前面编号变为p
					a[x][0] = 0;
					a[x][1] = 0;//x出队，前后无人，编号均为0
		}
	}
	int order = a[0][1];//锁定排头编号
	if(a[0][0]!=a[0][1])//队伍不止一个人
	{ printf("%d\n", a[0][1]);
	do
	{
		order = a[order][1];
		printf("%d\n", order);
		
	}while (a[order][1]!=0);//依次输出全队从前到后编号
	}
	else//队伍只有一个人
	{
		printf("%d\n", a[0][0]);//直接输出排尾（头）编号
	}
	
	return 0;
}
