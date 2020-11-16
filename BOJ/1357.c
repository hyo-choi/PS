#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *rev(char *a)
{
	int len = strlen(a);

	for (int i = 0; i < len / 2; i++)
	{
		char tmp;
		tmp = a[i];
		a[i] = a[len - i - 1];
		a[len - i - 1] = tmp;
	}
	return (a);
}

char *itoa(int a, char *arr)
{
	int j = 0;

	arr[0] = 0;
	for (int i = 0; i < 4; i++)
	{
		int tmp = a / pow(10, 3 - i);
		if (arr[0] == 0 && tmp == 0)
			continue;
		arr[j++] = tmp + '0';
		a -= tmp * pow(10, 3 - i);
	}
	arr[j] = 0;
	return (arr);
}

int main(void)
{
	int result, a, b;
	char x[5], y[5], arr[5];

	scanf("%d %d", &a, &b);
	result = atoi(rev(itoa(a, x))) + atoi(rev(itoa(b, y)));
	printf("%d\n", atoi(rev(itoa(result, arr))));
	return (0);
}