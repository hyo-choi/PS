#include <stdio.h>

int gcd(int a, int b)
{
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}

int main(void)
{
	int arr[100], t, n;
	unsigned long long sum;
	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sum += gcd(arr[i], arr[j]);
		printf("%llu\n", sum);
	}
	return (0);
}