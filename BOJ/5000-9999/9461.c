#include <stdio.h>

unsigned long long arr[101] = {1, 1, 1, };
unsigned long long dp[101] = {1, 1, 1, };

unsigned long long solve(int n)
{
	if (dp[n] != 0)
		return (dp[n]);
	dp[n] = solve(n - 3) + solve(n - 2);
	return (dp[n]);
}

int main(void)
{
	int t, n;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%llu\n", solve(n - 1));
	}
	return (0);
}