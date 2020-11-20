#include <stdio.h>

int main(void)
{
	int t, open_round, open_rect, result;
	char c;

	scanf("%d", &t);
	scanf("%c", &c);
	while (t--)
	{
		result = 0;
		open_round = 0;
		open_rect = 0;
		while (1)
		{
			scanf("%c", &c);
			if (c == '\n')
				break ;
			if (c == '(')
				open_round++;
			else if (c == '[')
				open_rect++;
			else if (c == ')' && open_round > 0)
			{
				open_round--;
				result++;
			}
			else if (c == ']' && open_rect > 0)
			{
				open_rect--;
				result++;
			}
		}
		printf("%d\n", result);	
	}
	return (0);
}