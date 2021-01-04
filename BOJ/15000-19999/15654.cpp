/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <algorithm>

int m, n;
int arr[8];
int flag[8];
int str[8];

void print_solution(int num)
{
	if (num == m)
	{
		for (int i = 0; i < m - 1; i++)
			printf("%d ", str[i]);
		printf("%d\n", str[m - 1]);
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 0)
		{
			flag[i] = 1;
			str[num] = arr[i];
			print_solution(num + 1);
			flag[i] = 0;
		}
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
		flag[i] = 1;
		print_solution(1);
		flag[i] = 0;
	}
	return (0);
}