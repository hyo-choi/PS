#include <stdio.h>
#define LEFT 0
#define RIGHT 1

char	arr[1001][1001];

void	find_heart(int N, int *x, int *y)
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[j][i] == '*')
			{
				*x = i;
				*y = j + 1;
				return ;
			}
		}
	}
}

int	calc_arm_length(int N, int x, int y, int num)
{
	int	minus, len = 0;

	minus = num == LEFT ? -1 : 1;
	for (int i = x + minus; i >= 0 && i < N && arr[y][i] == '*'; i += minus)
		len++;
	return (len);
}

int	calc_body_length(int N, int x, int y)
{
	int len = 0;

	for (int i = y + 1; i < N && arr[i][x] == '*'; i++)
		len++;
	return (len);
}

int calc_leg_length(int N, int x, int y, int num)
{
	int	minus, len = 0;

	minus = num == LEFT ? -1 : 1;
	for (int i = y + 1; i < N && arr[i][x + minus] == '*'; i++)
		len++;
	return (len);
}

int main(void)
{
	int N, x, y, arm_left, arm_right, body, leg_left, leg_right;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", arr[i]);
	find_heart(N, &x, &y);
	arm_left = calc_arm_length(N, x, y, LEFT);
	arm_right = calc_arm_length(N, x, y, RIGHT);
	body = calc_body_length(N, x, y);
	leg_left = calc_leg_length(N, x, y + body, LEFT);
	leg_right = calc_leg_length(N, x, y + body, RIGHT);
	printf("%d %d\n", y + 1, x + 1);
	printf("%d %d %d %d %d", arm_left, arm_right, body, leg_left, leg_right);
}