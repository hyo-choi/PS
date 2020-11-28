#include <stdio.h>

int n;
int arr[11];
int max = -2147483648, min = 2147483647;

void solve(int i, int res, int add, int sub, int mul, int div)
{
	if (i == n - 1)
	{
		if (res < min)
			min = res;
		if (res > max)
			max = res;
		return ;
	}
	if (add > 0)
		solve(i + 1, res + arr[i + 1], add - 1, sub, mul, div);
	if (sub > 0)
		solve(i + 1, res - arr[i + 1], add, sub - 1, mul, div);
	if (mul > 0)
		solve(i + 1, res * arr[i + 1], add, sub, mul - 1, div);
	if (div > 0)
		solve(i + 1, res / arr[i + 1], add, sub, mul, div - 1);
}

int main(void)
{
	int sign[4];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d %d %d %d", &sign[0], &sign[1], &sign[2], &sign[3]);
	solve(0, arr[0], sign[0], sign[1], sign[2], sign[3]);
	printf("%d\n%d\n", max, min);
	return (0);
}