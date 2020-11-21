#include <stdio.h>

int main(void)
{
	unsigned long long result = 0;
	int arr[10], n, k, tmp;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = n - 1; i >= 0; i--)
	{
		if ((int)(k / arr[i]) > 0)
		{
			tmp = (int)(k / arr[i]);
			k -= arr[i] * tmp;
			result += tmp;
		}
	}
	printf("%llu\n", result);
	return (0);
}