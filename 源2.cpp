#include<stdlib.h>
#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
struct tnode {
	long long int data;
	struct tnode* parent;
	struct tnode* Lchildren;
	struct tnode* Rchildren;
};
tnode* createnode(long long int data)
{
	struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
	newNode->data = data;
	newNode->Lchildren = NULL;
	newNode->Rchildren = NULL;
	return newNode;
}
int main()
{
	long long int order = 1;
	long long int lost[132] = { 0 };
	long long int target[132] = { 0 };
	int m, n;
	int j = 0;
	int k = 0;
	int ff = 0;
	queue<tnode*>q;
	scanf("%d", &n);
	scanf("%d", &m);
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &lost[i]);
		}
	}
	for (int jj = 0; jj < m; jj++)
	{
		scanf("%lld", &target[jj]);
	}
	long long int M = target[m - 1];
	struct tnode* root;
	root = createnode(order);
	root->parent = NULL;
	q.push(root);
	if (lost[0] == 1)
	{
		if (target[0] == 1)
		{
			printf("%d\n", 1);
			for (int i = 0; i < m - 1; i++)
			{
				printf("%d\n", 0);
			}
		}
		else
		{
			for (int i = 0; i < m; i++)
			{
				printf("%d\n", 0);
			}
		}
		order = 2 * M + 1;
	}

	else
	{
		if (target[0] == 1)
		{
			printf("%d\n", 1);
			k++;
			ff++;
		}

		while ((!q.empty()) && (order <= 2 * M))
		{
			long long int currentlost = lost[j];
			long long int currenttarget = target[k];
			tnode* now = q.front();
			if (now->data != currentlost)
			{
				order++;
				now->Lchildren = createnode(order);
				order++;
				now->Rchildren = createnode(order);
				now->Lchildren->parent = now;
				now->Rchildren->parent = now;
			}
			else if (now->data == currentlost)
			{
				j++;
			}
			if (now->data == currenttarget)
			{
				long long int ch[200] = { 0 };
				int rt = 0;
				tnode* ref = now;
				while (ref->parent != NULL)
				{
					ch[rt] = ref->data;
					rt++;
					ref = ref->parent;
				}
				ch[rt] = 1;
				for (int pb = rt; pb >= 0; pb--)
				{
					printf("%lld ", ch[pb]);
				}
				printf("\n");
				k++;
				ff++;
			}
			q.pop();
			if (now->Lchildren != NULL) q.push(now->Lchildren);
			if (now->Rchildren != NULL) q.push(now->Rchildren);
		}
		for (int i = 0; i < m - ff; i++)
		{
			printf("%d\n", 0);
		}
	}
}
