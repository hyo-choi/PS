#include <stdio.h>

int arr[10001];
int dp[10001];

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	dp_solve(int n)
{
	int tmp;

	if (dp[n] != 0 || n < 0)
		return ;
	dp_solve(n - 1);
	tmp = n >= 3 ? dp[n - 3] : 0;
	dp[n] = max(tmp + arr[n - 1] + arr[n], dp[n - 2] + arr[n]);
	dp[n] = max(dp[n - 1], dp[n]);
}

int		main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp_solve(n);
	printf("%d\n", dp[n]);
	return (0);
}