#include <stdio.h>

int dp[1000001] = {0, 1, 2, };

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746; 
	printf("%d\n", dp[n] % 15746);
	return (0);
}