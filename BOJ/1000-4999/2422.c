#include <stdio.h>

int arr[201][201];

int main(void)
{
	int n, m, result = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		arr[tmp1][tmp2] = 1;
		arr[tmp2][tmp1] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int k = j + 1; k <= n; k++)
					if (arr[i][k] == 0 && arr[j][k] == 0)
						result++;
			}
		}
	}
	printf("%d\n", result);
	return (0);
}