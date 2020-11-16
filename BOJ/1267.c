#include <stdio.h>

int main(void)
{
	int n, t, sum_y = 0, sum_m = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		sum_y += (t / 30 + 1) * 10;
		sum_m += (t / 60 + 1) * 15;
	}
	if (sum_m >= sum_y)
		printf("Y ");
	if (sum_m <= sum_y)
		printf("M ");
	printf("%d\n", sum_m < sum_y ? sum_m : sum_y);
	return (0);
}