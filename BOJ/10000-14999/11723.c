#include <stdio.h>
#include <string.h>

int arr[20];

void ft_add(int n)
{
	arr[n - 1] = n;
}

void ft_remove(int n)
{
	arr[n - 1] = -1;
}

void ft_toggle(int n)
{
	if (arr[n - 1] != -1)
		ft_remove(n);
	else
		ft_add(n);
}

void ft_check(int n)
{
	printf("%d\n", arr[n - 1] != -1 ? 1 : 0);
}

void ft_all(void)
{
	for (int i = 0; i < 20; i++)
		arr[i] = i + 1;
}

void ft_empty(void)
{
	memset(arr, -1, sizeof(arr));
}

int main(void)
{
	int		M, n;
	char	cmd[7];

	scanf("%d", &M);
	ft_empty();
	while (M--)
	{
		scanf("%s", cmd);
		if (!strcmp(cmd, "all"))
			ft_all();
		else if (!strcmp(cmd, "empty"))
			ft_empty();
		else
		{
			scanf("%d", &n);
			if (!strcmp(cmd, "add"))
				ft_add(n);
			else if (!strcmp(cmd, "remove"))
				ft_remove(n);
			else if (!strcmp(cmd, "check"))
				ft_check(n);
			else if (!strcmp(cmd, "toggle"))
				ft_toggle(n);
		}
	}
	return (0);
}
