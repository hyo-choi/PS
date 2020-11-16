#include <stdio.h>
#include <string.h>
#include <math.h>

const char arr[10][10] = {"black", "brown", "red", "orange", "yellow",
				"green", "blue", "violet", "grey", "white"};

int main(void)
{
	char s[3][10];
	unsigned long long sum;

	scanf("%s %s %s", s[0], s[1], s[2]);
	for (int i = 0; i < 10; i++)
		if (!strcmp(arr[i], s[0]))
			sum = i;
	for (int i = 0; i < 10; i++)
		if (!strcmp(arr[i], s[1]))
			sum = sum * 10 + i;
	for (int i = 0; i < 10; i++)
		if (!strcmp(arr[i], s[2]))
			sum *= pow(10, i);
	printf("%llu\n", sum);
	return (0);
}