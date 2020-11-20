#include <stdio.h>
#include <algorithm>

unsigned long long arr[100001];

int main(void)
{
	int t, n;
	unsigned long long sum, result;

	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		result = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%llu", &arr[i]);
		if (n == 2)
		{
			printf("0\n");
			continue ;
		}
		std::sort(arr, arr + n);
		for (int i = 1; i < n - 1; i++)
			sum += arr[n - 1] - arr[i];
		if (sum > arr[0])
			result = sum - arr[0];
		else if (sum < arr[0])
			result = n - 1 - (arr[0] - sum) % (n - 1);
		printf("%llu\n", result);
	}
	return (0);
}