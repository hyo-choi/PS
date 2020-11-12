#include <stdio.h>
#include <string.h>

#define MOD 1000000000

int arr[101][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

void	dp(int N)
{
	for (int j = 2; j <= N; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
				arr[j][0] = arr[j - 1][1] % MOD;
			else if (i == 9)
				arr[j][9] = arr[j - 1][8] % MOD;
			else
				arr[j][i] = (arr[j - 1][i - 1] + arr[j - 1][i + 1]) % MOD;
		}
	}
}

int main(void)
{
	int		result = 0;
	int		N;

	scanf("%d", &N);
	if (N > 1)
		dp(N);
	for (int i = 0; i < 10; i++)
		result = (result + arr[N][i]) % MOD;
	printf("%d", result % MOD);
	return (0);
}