/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <algorithm>
#include <string.h>
#include <stdio.h>

typedef struct	s_person
{
	int		score;
	char	name[11];
}				t_person;

t_person	list[100001];

int	cmp(const t_person& p1, const t_person& p2)
{
	if (p1.score == p2.score)
		return (strcmp(p1.name, p2.name) < 0);
	else
		return (p1.score > p2.score);
}

int main(void)
{
	int	N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s %d", list[i].name, &list[i].score);
	std::sort(list, list + N, cmp);
	printf("%s", list[0].name);
}