#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int a = 1, b = 1, c[19948] = { 0 }, n[20] = { 0 }, m[20] = { 0 };
	int N;
	scanf("%d", &N);
	c[0] = 1;
	c[1] = 1;
	for (int i = 3; i < 19948; i+=2)
	{
		b = (a + b) % 9973;
		a = (a + b) % 9973;
		c[i-1] = b;
		c[i] = a;
	}
	for (int j = 0; j < N; j++)
	{
		scanf("%d", &n[j]);
		m[j] = n[j] % 19948;
		printf("%d\n", c[m[j]-1]);
	}
}
