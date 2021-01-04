/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <algorithm>

int m, n;
int arr[8];
int str[8];

void print_solution(int num, int k)
{
	if (num == m)
	{
		for (int i = 0; i < m - 1; i++)
			printf("%d ", str[i]);
		printf("%d\n", str[m - 1]);
		return ;
	}
	for (int i = k; i < n; i++)
	{
		str[num] = arr[i];
		print_solution(num + 1, i);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		str[0] = arr[i];
		print_solution(1, i);
	}
	return (0);
}