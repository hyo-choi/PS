#include <stdio.h>

#define MOD 10007

int arr[1001][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
					1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

void dp(int N)
{
	for (int j = 2; j <= N; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
				arr[j][0] = arr[j - 1][0] % MOD;
			else
				for (int k = 0; k <= i; k++)
					arr[j][i] = (arr[j][i] + arr[j - 1][k]) % MOD;
		}
	}
}

int main(void)
{
	int N, result = 0;

	scanf("%d", &N);
	dp(N);
	for (int i = 0; i < 10; i++)
		result = (result + arr[N][i]) % MOD;
	printf("%d\n", result);
	return (0);
}