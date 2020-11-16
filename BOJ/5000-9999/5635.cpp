/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <algorithm>

typedef struct	s_person
{
	int			dd;
	int			mm;
	int			yyyy;
	char		name[16];
}				t_person;

t_person	arr[100];

int cmp(const t_person& p1, const t_person& p2)
{
	if (p1.yyyy == p2.yyyy)
	{
		if (p1.mm == p2.mm)
			return (p1.dd < p2.dd);
		return(p1.mm < p2.mm);
	}
	return (p1.yyyy < p2.yyyy);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i].name);
		scanf("%d %d %d", &arr[i].dd, &arr[i].mm, &arr[i].yyyy);
	}
	std::sort(arr, arr + n, cmp);
	printf("%s\n%s\n", arr[n - 1].name, arr[0].name);
	return (0);
}