/*
** I have never studied C++ yet.
** So C++ is used only for using algorithm header.
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef struct	s_str
{
	char		str[21];
}				t_str;

t_str hear[500000];
t_str see[500000];
int arr[500000];

int cmp(const t_str &s1, const t_str &s2)
{
	return (strcmp(s1.str, s2.str) < 0 ? 1 : 0);
}

int main(void)
{
	int n, m, cnt = 0;
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", hear[i].str);
	for (int i = 0; i < m; i++)
		scanf("%s", see[i].str);
	std::sort(hear, hear + n, cmp);
	std::sort(see, see + m, cmp);
	for (int i = 0; i < m; i++)
	{
		int low = 0, high = m - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int tmp = strcmp(hear[mid].str, see[i].str);
			if (tmp == 0)
			{
				arr[cnt++] = i;
				break ;
			}
			else if (tmp < 0)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%s\n", see[arr[i]].str);
	return (0);
}