#include <stdio.h>

int num[8];
int arr[8];

void solve(int i, int j, int n, int m)
{
	arr[i] = num[j];
	if (i == m)
	{
		for (int i = 1; i <= m - 1; i++)
			printf("%d ", arr[i]);
		printf("%d\n", arr[i]);
		return ;
	}
	for (; j <= n - m + i; j++)
		solve(i + 1, j + 1, n, m);
}

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		num[i] = i;
	for (int i = 1; i <= n - m + 1; i++)
		solve(1, i, n, m);
	return (0);
}