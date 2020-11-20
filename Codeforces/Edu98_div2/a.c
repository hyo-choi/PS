#include <stdio.h>

int ft_abs(int a)
{
	return (a > 0 ? a : -1 * a);
}

int main(void)
{
	int t, x, y, result;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &x, &y);
		if (ft_abs(x - y) <= 1)
			result = x + y;
		else
		{
			if (x > y)
				result = 2 * y + (x - y) + (x - y - 1);
			else
				result = 2 * x + (y - x) + (y - x - 1);
		}
		printf("%d\n", result);
	}
	return (0);
}