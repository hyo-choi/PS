#include <stdio.h>

char str[1000001];

int main(void)
{
	int n, m, result = 0, io = 0;

	scanf("%d\n%d", &n, &m);
	scanf("%s", str);
	for (int i = 0; str[i + 1] != 0; i++)
	{
		if (str[i] == 'I' && str[i + 1] == 'O')
			io++;
		else if (str[i] == 'O' && str[i + 1] == 'I')
		{
			if (io >= n)
				result++;
		}
		else
			io = 0;
	}
	printf("%d\n", result);
	return (0);
}