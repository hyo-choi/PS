#include <stdio.h>

int n, min, start_sum, link_sum;
int arr[21][21];
int start[10];
int link[10];

int ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int is_in_start(int num)
{
	for (int i = 0; i < n / 2; i++)
		if (num == start[i])
			return (1);
	return (0);
}

int calc_score(int *team)
{
	int sum;

	sum = 0;
	for (int j = 0; j < n / 2; j++)
		for (int i = 0; i < n / 2; i++)
			sum += arr[team[i]][team[j]];
	return (sum);
}

void fill_team(int idx, int num)
{
	int tmp;

	if (idx == n / 2)
	{
		tmp = 0;
		start_sum = calc_score(start);
		for (int i = 1; i <= n; i++)
			if (!is_in_start(i))
				link[tmp++] = i;
		link_sum = calc_score(link);
		if ((tmp = ft_abs(start_sum - link_sum)) < min)
			min = tmp;
		return ;
	}
	for (int i = num + 1; i <= n; i++)
	{
		start[idx] = i;
		fill_team(idx + 1, i);
		start[idx] = 0;
	}
}

int main(void)
{
	min = 2147483647;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= n; i++)
	{
		start[0] = i;
		fill_team(1, i);
		start[0] = 0;
	}
	printf("%d\n", min);
	return (0);
}
