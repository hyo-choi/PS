#include <stdio.h>

int n, m;
int arr[9];

void print_solution(int num, int k)
{
	if (num > m)
	{
		for (int i = 1; i < m; i++)
			printf("%d ", arr[i]);
		printf("%d\n", arr[m]);
		return ;
	}
	for (int i = k; i <= n; i++)
	{
		arr[num] = i;
		print_solution(num + 1, i);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		arr[1] = i;
		print_solution(2, i);
	}
	return (0);
}