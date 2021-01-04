#include <stdio.h>

int		n, m;
int		arr[9];
int		str[9];

void print_solution(int num)
{
	if (num > m)
	{
		for (int i = 1; i < m; i++)
			printf("%d ", str[i]);
		printf("%d\n", str[m]);
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = 1;
			str[num] = i;
			print_solution(num + 1);
			arr[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		str[1] = i;
		arr[i] = 1;
		print_solution(2);
		arr[i] = 0;
	}
	return (0);
}