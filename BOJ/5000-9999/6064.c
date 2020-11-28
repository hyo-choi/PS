#include <stdio.h>

int gcd(int a, int b)
{
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}

int lcm(int a, int b)
{
	return ((a * b) / gcd(a, b));
}

int main(void)
{
	int t, m, n, x, y, max, result, tmp;

	scanf("%d", &t);
	while (t--)
	{
		result = -1;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		max = lcm(m, n);
		for (int i = 0; m * i + x <= max; i++)
		{
			tmp = (m * i + x) % n;
			tmp = tmp == 0 ? n : tmp;
			if (tmp == y)
			{
				result = m * i + x;
				break ;
			}
		}
		printf("%d\n", result);
	}
	return (0);
}