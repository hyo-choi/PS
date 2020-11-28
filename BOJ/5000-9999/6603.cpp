/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <algorithm>

int arr[6];

void print_all(int i, int j, int *s, int k)
{
	arr[j - 1] = s[i];
	if (j == 6)
	{
		printf("%d %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
		return ;
	}
	for (; i < k - 6 + j; i++)
		print_all(i + 1, j + 1, s, k);
	return ;
}

int main(void)
{
	int k, s[13];

	while (1)
	{
		scanf("%d", &k);
		if (k == 0)
			break ;
		for (int i = 0; i < k; i++)
			scanf("%d", &s[i]);
		std::sort(s, s + k);
		for (int i = 0; i <= k - 6; i++)
			print_all(i, 1, s, k);
		printf("\n");
	}
	return (0);
}