#include <stdio.h>

int n, ans;
int arr[16];

int can_put_queen(int num, int put)
{
	for (int i = 1; i < num; i++)
	{
		if (put - i > 0 && arr[put - i] == num - i)
			return (0);
		if (put + i <= n && arr[put + i] == num - i)
			return (0);
	}
	return (1);
}

void n_queen(int num)
{
	if (num == n + 1)
	{
		ans += 1;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0 && can_put_queen(num, i))
		{
			arr[i] = num;
			n_queen(num + 1);
			arr[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		arr[i] = 1;
		n_queen(2);
		arr[i] = 0;
	}
	printf("%d\n", ans);
	return (0);
}