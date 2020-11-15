#include <stdio.h>

int arr[1001];
int dp[1001];

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
	for (int i = 0; i < n; i++)
	{
		dp[i] = arr[i];
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		result = max(dp[i], result);
	}
	printf("%d\n", result);
	return (0);
}