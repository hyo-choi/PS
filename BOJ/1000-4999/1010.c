#include <stdio.h>
#include <string.h>

unsigned long long dp[31][31];

unsigned long long dp_solve(int n, int m)
{
	if (dp[n][m] != 0 || n == 1)
		return (dp[n][m]);
	for (int i = 1; i <= m - n + 1; i++)
		dp[n][m] += dp_solve(n - 1, m - i);
	return (dp[n][m]);
}

int main(void)
{
	int t, n, m;

	for (int i = 0; i < 31; i++)
		dp[0][i] = 0;
	for (int i = 0; i < 31; i++)
		dp[1][i] = i;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		printf("%llu\n", dp_solve(n, m));
	}
	return (0);
}