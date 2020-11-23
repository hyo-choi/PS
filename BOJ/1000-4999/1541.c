#include <stdio.h>
#include <stdlib.h>

char str[51];
int arr[51];

int main(void)
{
	int j = 0, flag = 1, sum = 0;

	scanf("%s", str);
	for (int i = 0; str[j] != 0; i++)
	{
		arr[i] = atoi(&(str[j]));
		while (str[j] == '-' || str[j] == '+')
			j++;
		while (str[j] >= '0' && str[j] <= '9')
			j++;
		if (arr[i] < 0 && flag == -1)
			flag = 1;
		sum += flag * arr[i];
		if (arr[i] < 0 && flag == 1)
			flag = -1;
	}
	printf("%d\n", sum);
	return (0);
}