/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <algorithm>

typedef struct	s_arr
{
	int origin;
	int renew;
	int idx;
}				t_arr;

t_arr arr[1000001];

int cmp_bef(const t_arr& p1, const t_arr& p2)
{
	return (p1.origin < p2.origin);
}

int cmp_aft(const t_arr& p1, const t_arr& p2)
{
	return (p1.idx < p2.idx);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].origin);
		arr[i].idx = i;
	}
	std::sort(arr, arr + n, cmp_bef);
	arr[0].renew = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].origin == arr[i - 1].origin)
			arr[i].renew = arr[i - 1].renew;
		else
			arr[i].renew = arr[i - 1].renew + 1;
	}
	std::sort(arr, arr + n, cmp_aft);
	for (int i = 0; i < n - 1; i++)
		printf("%d ", arr[i].renew);
	printf("%d\n", arr[n - 1].renew);
	return (0);
}