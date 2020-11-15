#include <stdio.h>

int arr[11][11];

int ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int main(void)
{
	int t, n, m, min, sum, minus;

	scanf("%d", &t);
	while (t--)
	{
		minus = 0;
		sum = 0;
		min = 101;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				scanf("%d", &arr[j][i]);
				if (ft_abs(arr[j][i]) < min)
					min = ft_abs(arr[j][i]);
				if (arr[j][i] < 0)
					minus++;
				sum += ft_abs(arr[j][i]);
			}
		}
		if (minus % 2 == 0)
			printf("%d\n", sum);
		else
			printf("%d\n", sum - min * 2);
	}
	return (0);
}