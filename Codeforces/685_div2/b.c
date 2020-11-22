#include <stdio.h>
#include <string.h>

char str[102];

int is_good_sub(char *str, int ql, int qr, int n)
{
	int flag = 0;

	if (n <= 2)
		return (0);
	for (int i = 0; i < ql; i++)
		if (str[i] == str[ql])
			flag = 1;
	for (int i = qr + 1; i < n; i++)
		if (str[i] == str[qr])
			flag = 1;
	return (flag ? 1 : 0);
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
			if (is_good_sub(str, --ql, --qr, n))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return (0);
}