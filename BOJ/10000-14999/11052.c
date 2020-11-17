#include <stdio.h>

int arr[1002];
int dp[1002];

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int main(void)
{
	int n, result, tmp;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	arr[0] = 0;
	dp[0] = 0;
	result = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
	}
	printf("%d\n", dp[n]);
}
