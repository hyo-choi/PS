/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef struct	s_time
{
	int start;
	int duration;
}				t_time;

t_time	time[100000];

int cmp(const t_time& t1, const t_time& t2)
{
	return (t1.start < t2.start);
}

int	find_time(int N, int M, int S)
{
	for (int i = 0; i < N - 1; i++)
	{
		if (time[i].start + time[i].duration + M <= time[i + 1].start)
			return (time[i].start + time[i].duration);
	}
	if (time[N - 1].start + time[N - 1].duration + M <= S)
		return (time[N - 1].start + time[N - 1].duration);
	return (-1);
}

int main(void)
{
	int N, M, S, result;

	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &time[i].start, &time[i].duration);
	std::sort(time, time + N, cmp);
	if (time[0].start < M)
		result = find_time(N, M, S);
	else
		result = 0;
	printf("%d", result);
}