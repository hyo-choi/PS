#include <stdio.h>

int arr[1000001];
int bin[1000001];

int lower_bound(int low, int high, int target)
{
	int mid;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (bin[mid] >= target)
			high = mid;
		else
			low = mid + 1;
	}
	return (high);
}

int main(void)
{
	int n, j;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	bin[0] = arr[0];
	j = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > bin[j - 1])
			bin[j++] = arr[i];
		else if (arr[i] < bin[j - 1])
			bin[lower_bound(0, j - 1, arr[i])] = arr[i];
	}
	printf("%d\n", j);
	return (0);
}