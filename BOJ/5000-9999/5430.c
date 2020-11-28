#include <stdio.h>

char str[100002];
int arr[100000];

int main(void)
{
	int t, n, head, tail, blank, flag;
	
	scanf("%d", &t);
	while (t--)
	{
		blank = 0;
		flag = 0;
		scanf("%s", str);
		scanf("%d", &n);
		head = 0;
		tail = n - 1;
		if (n == 0)
		{
			tail = 0;
			blank = 1;
		}
		getchar(); // flush newline
		getchar(); // flush '['
		for (int i = 0; i < n - 1; i++)
			scanf("%d,", &arr[i]);
		if (n != 0)
			scanf("%d]", &arr[n - 1]);
		getchar(); // flush newline
		for (int i = 0; str[i] != 0; i++)
		{
			if (str[i] == 'R')
			{
				int tmp;
				tmp = head;
				head = tail;
				tail = tmp;
			}
			else if (str[i] == 'D')
			{
				if (head < tail)
					head++;
				else if (tail < head)
					head--;
				else
				{
					if (blank == 0)
						blank = 1;
					else
					{
						flag = 1;
						break ;
					}
				}
			}
		}
		if (flag)
			printf("error\n");
		else
		{
			printf("[");
			if (head == tail)
			{
				if (!blank)
					printf("%d", arr[head]);
			}
			else if (head < tail)
			{
				for (int i = head; i < tail; i++)
					printf("%d,", arr[i]);
				printf("%d", arr[tail]);
			}
			else
			{
				for (int i = head; i > tail; i--)
					printf("%d,", arr[i]);
				printf("%d", arr[tail]);
			}
			printf("]\n");
		}
	}
	return (0);
}