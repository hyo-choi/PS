#include <stdio.h>

int dp[16];

int main(void)
{
	int N, T, P;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &T, &P);
		if (dp[i] > dp[i + 1])
			dp[i + 1] = dp[i];
		if (i + T < N + 1 && dp[i + T] < dp[i] + P)
			dp[i + T] = dp[i] + P;
	}
	printf("%d\n", dp[N]);
	return (0);
}