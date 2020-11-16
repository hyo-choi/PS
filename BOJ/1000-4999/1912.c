#include <stdio.h>

int arr[100001];
int dp[100001];

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
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0] = arr[0];
	result = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}
	printf("%d\n", result);
	return (0);
}