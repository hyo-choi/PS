/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <algorithm>

int arr[100000];

int cmp(const int t1, const int t2)
{
	return (t1 > t2);
}

int main(void)
{
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
		arr[i] += i + 1;
	std::sort(arr, arr + N, cmp);
	printf("%d\n", arr[0] + 1);
	return (0);
}