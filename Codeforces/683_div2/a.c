#include <stdio.h>

int main(void)
{
	int t, n, m, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", n - 1);
		for (int i = 1; i < n - 1; i++)
			printf("%d ", i + 1);
		printf("%d\n", n);
	}
}