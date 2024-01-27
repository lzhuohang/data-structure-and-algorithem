#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	char a[200] = { "" }, b[200] = { "" },  c[201] = { "0" }, d[200] = { "" };
	scanf("%s", &a);
	scanf("%s", &b);
	int len_a = strlen(a);
	int len_b = strlen(b);
	int p=0,dd = 0;
	if (len_b > len_a)
	{
		strcpy(d, a); dd = len_a;
		strcpy(a, b); len_a = len_b;
		strcpy(b, d); len_b = dd;
	}
	for (int i = 0; i < len_b; i++)
	{
		c[i] = ((a[len_a-i-1]-'0') + (b[len_b-i-1]-'0') + p) % 10 + '0';
		p = ((a[len_a - i-1] - '0') + (b[len_b-i-1] - '0') + p) / 10;
	}
	for (int i = len_b; i < len_a; i++)
	{
		c[i] = ((a[len_a - i-1] - '0')+ p) % 10+'0';
		p = ((a[len_a - i-1] - '0') + p) / 10;
	}
	c[len_a] = p+'0';
	if (p == 0)
	{
		for (int j = len_a - 1; j >= 0; j--)
		{
			printf("%c", c[j]);
		}

	}
	else
	{
		for (int j = len_a ; j >= 0; j--)
		{
			printf("%c", c[j]);
		}
	}
	return 0;
}
