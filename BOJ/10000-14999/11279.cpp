#include <cstdio>
#include <queue>

int main(void)
{
	int n, m;
	std::priority_queue<int> heap;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		if (m == 0)
		{
			if (heap.empty())
			{
				printf("0\n");
				continue;
			}
			printf("%d\n", heap.top());
			heap.pop();
			continue;
		}
		heap.push(m);
	}
	return 0;
}
