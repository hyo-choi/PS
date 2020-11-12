#include <stdio.h>

int arr[12] = {0, };

int dp(int n)
{
	if (arr[n] != 0)
		return (arr[n]);
	arr[n] = dp(n - 3) + dp(n - 2) + dp(n - 1);
	return (arr[n]);
}

int main(void)
{
	int T, n;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		printf("%d\n", dp(n));
	}
	return (0);
}