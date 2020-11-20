/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <algorithm>

int arr[500001];

int main(void)
{
	int n, m, target, result;
	int low, high, mid;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &target);
		result = 0;
		low = 0;
		high = n - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] == target)
			{
				result = 1;
				break ;
			}
			else if (arr[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		printf("%d", result);
		if (i != m - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}