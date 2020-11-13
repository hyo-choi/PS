#include <stdio.h>
#include <string.h>

int		arr[100003][2];
int		dp[100003][2];

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int dp_solve(int n)
{
	if (dp[n][0] != 0 || dp[n][1] != 0)
		return (max(dp[n][0], dp[n][1]));
	if (n == 0)
	{
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
	}
	else if (n == 1)
	{
		dp_solve(0);
		dp[1][0] = arr[1][0] + dp[0][1];
		dp[1][1] = arr[1][1] + dp[0][0];
	}
	else
	{
		dp_solve(n - 1);
		dp[n][0] = max(dp[n - 2][1], dp[n - 1][1]) + arr[n][0];
		dp[n][1] = max(dp[n - 2][0], dp[n - 1][0]) + arr[n][1];
	}
	return (max(dp[n][0], dp[n][1]));
}

int main(void)
{
	int t, n;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		memset(arr, 0, sizeof(dp));
		memset(dp, 0, sizeof(arr));
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[j][0]);
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[j][1]);
		printf("%d\n", dp_solve(n));
	}
}