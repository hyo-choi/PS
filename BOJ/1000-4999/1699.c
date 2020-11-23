#include <stdio.h>
#include <math.h>

#define MIN(A, B) (A) < (B) ? (A) : (B)

int dp[100000] = {0, 1, 2, 3, };

int dp_solve(int n)
{
	int tmp, sqrt_val = (int)sqrt(n);

	if (dp[n] != 0 || n == 0)
		return (dp[n]);
	if (sqrt_val * sqrt_val == n)
		return (dp[n] = 1);
	for (int i = sqrt_val; i >= 2; i--)
	{
		tmp = dp_solve(i * i) + dp_solve(n - i * i);
		dp[n] = dp[n] != 0 ? MIN(tmp, dp[n]) : tmp;
	}
	return (dp[n]);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", dp_solve(n));
	return (0);
}