#include <cstdio>
#include <queue>

int main(void)
{
	int n, m;
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(m);
		else
			minHeap.push(m);
		if (minHeap.size() == 0)
		{
			printf("%d\n", maxHeap.top());
			continue;
		}
		if (maxHeap.top() > minHeap.top())
		{
			int maxTop = maxHeap.top();
			int minTop = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}
		printf("%d\n", maxHeap.top());
	}
	return 0;
}
