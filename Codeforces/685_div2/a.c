#include <stdio.h>

int main(void)
{
	int t, n, sum;

	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		scanf("%d", &n);
		while (n != 1)
		{
			if (n % 2 == 0 && n != 2)
			{
				sum++;
				n /= (n / 2);
			}
			else
			{
				sum++;
				n--;
			}
		}
		printf("%d\n", sum);
	}
	return (0);
}