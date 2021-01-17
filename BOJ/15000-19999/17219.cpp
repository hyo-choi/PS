/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, m;

typedef struct	s_id
{
	char id[21];
	char pw[21];
}				t_id;

t_id book[100000];

int	cmp(const t_id &a, const t_id &b)
{
	if (strcmp(a.id, b.id) < 0)
		return (1);
	return (0);
}

char *bin_search(char *target)
{
	int low, high, mid, tmp;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		tmp = strcmp(book[mid].id, target);
		if (tmp > 0)
			high = mid - 1;
		else if (tmp < 0)
			low = mid + 1;
		else
			break ;
	}
	return (book[mid].pw);
}

int main(void)
{
	char target[21];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s %s", book[i].id, book[i].pw);
	std::sort(book, book + n, cmp);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", target);
		printf("%s\n", bin_search(target));
	}
	return (0);
}
