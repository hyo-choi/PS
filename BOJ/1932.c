#include <stdio.h>

int arr[501][501];
int dp[501][501];

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int main(void)
{
	int n, result = 0;

	scanf("%d", &n);
	for (int j = 0; j < n; j++)
		for (int i = 0; i <= j; i++)
			scanf("%d", &arr[j][i]);
	dp[0][0] = arr[0][0];
	for (int j = 1; j < n; j++)
	{
		dp[j][0] = dp[j - 1][0] + arr[j][0];
		for (int i = 1; i < j; i++)
			dp[j][i] = max(dp[j - 1][i - 1], dp[j - 1][i]) + arr[j][i];
		dp[j][j] = dp[j - 1][j - 1] + arr[j][j];
	}
	for (int i = 0; i < n; i++)
		if (dp[n - 1][i] > result)
			result = dp[n - 1][i];
	printf("%d\n", result);
	return (0);
}