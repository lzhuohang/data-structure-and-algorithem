#include<stdlib.h>
#include<stdio.h>
#pragma warning(disable:4996)
struct node {
    long long int head;
	long long int tail;
	long long int thislost[100] = { 0 };
	long long int lostnumber=0;
	long long int allnumber;
	long long int alllost=0;
};//构建一个结构体记录每层信息，记录这一层头和末尾代表的数和这一层缺损点个数以及缺损点的值，所有点个数
int main()
{
	long long int lost[132] = { 0 };//记录缺损点数组
	long long int target[132] = { 0 };//记录目标点数组
	int m, n;
	int j = 0;
	int k = 0;
	int kk = 0;
	int ff = 0;
	int layer = 0;
	long long int flag = 0;
	struct node tree[132] ;//创建每层信息的结构体数组
	scanf("%d", &n);
	scanf("%d", &m);
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &lost[i]);
		}
	}//输入缺损点编号
	for (int jj = 0; jj < m; jj++)
	{
		scanf("%lld", &target[jj]);
	}//输入目标点编号
	long long int M = target[m - 1];//根据最大目标点确定构建范围
	if (lost[0] == 1)//缺损点为1
	{
		if (target[0] == 1)
		{
			printf("%d\n", 1);
			for (int i = 0; i < m - 1; i++)
			{
				printf("%d\n", 0);
			}
		}//目标点也有1，则输出1和m-1个0
		else
		{
			for (int i = 0; i < m; i++)
			{
				printf("%d\n", 0);
			}
		}//否则路径不存在，输出m个0
		kk=1;
	}
	else
	{
		if (target[0] == 1)
		{
			printf("%d\n", 1);
			k++;
			ff++;
		}//如果目标点第一个为1，先输出一个1
		long long int end = 2;
		int lostset = 0;
		tree[0].head = 1;
		tree[0].tail = 1;
		tree[0].allnumber = 1;
		tree[0].lostnumber = 0;
		tree[0].alllost = 0;
		tree[1].head = 2;
		tree[1].allnumber = 2;
		tree[1].tail = 3;
		layer = 1;
		while (kk==0&&(tree[layer].tail <=  M))//构建tree数组
		{
			while ((tree[layer].head<= lost[j]) && (tree[layer].tail >= lost[j]))//当前缺损点在该层
			{
				tree[layer].lostnumber++;
				tree[layer].thislost[lostset] = lost[j];//缺损点赋值到这一层
				j++;
				lostset++;
			}
				if (tree[layer].allnumber == tree[layer].lostnumber)//如果这一层被缺损点占满，记录这一层的层数，跳出循环
				{
					flag = layer; break;
				}
				tree[layer+1].allnumber = 2 * (tree[layer].allnumber - tree[layer].lostnumber);
				tree[layer].alllost = tree[layer - 1].alllost + tree[layer].lostnumber;
				layer++;//进入下一层
				lostset = 0;
				tree[layer].head = tree[layer-1].tail + 1;
				tree[layer].tail = tree[layer - 1].tail +tree[layer].allnumber;
		}
		for (int jj = 0; jj < m; jj++)//对m个目标点遍历
		{
			long long int NN = target[jj];
			int depth = -1;
			while (tree[depth].tail < NN)
			{
				depth++;
			}//算出目标点所处层数
			if ((flag!=0)&&(flag <= depth))break;//如果遇到某层被缺损点占满情况，结束循环
			long long int ch[132] = { 0 };//定义数组记录路径
			int pr = 0;
			int move;
			while (depth > 0)
			{
				move = 0;
				ch[pr] = NN;
				if (NN % 2 == 0)
				{
					for (int i = 0; i < tree[depth-1].lostnumber; i++)
					{
						if (move + (NN + 2 * tree[depth - 2].alllost) / 2 >= tree[depth-1].thislost[i])
						{
							move++;
						}
					}
					NN = move + (NN + 2 * tree[depth - 2].alllost) / 2;
				}
				else if (NN % 2 == 1)
				{
					for (int i = 0; i < tree[depth-1].lostnumber; i++)
					{
						if (move + (NN-1 + 2 * tree[depth - 2].alllost) / 2 >= tree[depth-1].thislost[i])
						{
							move++;
						}
					}
					NN = move + (NN - 1 + 2 * tree[depth - 2].alllost) / 2;
				}
				depth--;
				pr++;
			}
			ch[pr] = 1;
			for (int i = pr; i >= 0; i--)
			{
				printf("%lld ", ch[i]);//输出对应路径
			}
			printf("\n");
			ff++;
		}
       for (int i = 0; i < m-ff; i++)
		{
			printf("%d\n", 0);//如果有某层被缺损点占满情况，在那一层后面层数的点都输出0
		}
		}
	}
