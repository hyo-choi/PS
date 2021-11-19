#include <cstdio>
#include <iostream>
#include <queue>

int main(void)
{
	int n, m;
	unsigned long long sum = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int> > heap;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		heap.push(m);
	}
	if (heap.size() == 1)
	{
		printf("0\n");
		return 0;
	}
	while (heap.size() >= 2)
	{
		int min = heap.top();
		heap.pop();
		int next = heap.top();
		heap.pop();
		sum += min + next;
		if (heap.size() != 0)
			heap.push(min + next);
	}
	if (!heap.empty())
		sum += heap.top();
	printf("%llu\n", sum);
	return 0;
}
