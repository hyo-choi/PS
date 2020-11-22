/*
** Wrong ansswer due to problem misunderstanding
*/
#include <stdio.h>
#include <string.h>

char str[102];
char sub[102];

int is_good_sub(char *str, char *sub)
{
	int i, j, flag = 0, bef = -1;

	j = 0;
	while (sub[j])
	{
		i = bef + 1;
		while (str[i])
		{
			if (sub[j] == str[i])
			{
				if (flag)
				{
					i++;
					flag = 0;
					continue ;
				}
				if (bef + 1 == i && i != 0)
					flag = 1;
				break ;
			}
			else
				flag = 0;
			i++;
		}
		if (str[i] == 0)
			return (0);
		bef = i;
		j++;
	}
	return (1);
}

int main(void)
{
	int t, n, q, ql, qr;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &q);
		scanf("%s", str);
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d", &ql, &qr);
			ql--;
			qr--;
			strncpy(sub, str + ql, qr - ql + 1);
			sub[qr - ql + 1] = 0;
			if (is_good_sub(str, sub))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return (0);
}