#include <stdio.h>

int arr[101];
int dp[10001] = {1, };

int dp_solve(int k, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = arr[i]; j <= k; j++)
			dp[j] += dp[j - arr[i]];
	return (dp[k]);
}

int main(void)
{
	int n, k, tmp;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", dp_solve(k, n));
	return (0);
}