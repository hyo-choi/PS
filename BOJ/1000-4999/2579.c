#include <stdio.h>

int arr[301];
int dp[301];

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int main(void)
{
	int n, tmp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	for (int i = 2; i < n; i++)
	{
		tmp = i - 3 >= 0 ? dp[i - 3] : 0;
		dp[i] = max(dp[i - 2] + arr[i], tmp + arr[i - 1] + arr[i]);
	}
	printf("%d\n", dp[n - 1]);
	return (0);
}