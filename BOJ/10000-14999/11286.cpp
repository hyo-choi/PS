#include <cstdio>
#include <queue>
#include <cmath>
struct compare
{
	bool operator()(const int &a, const int &b) {
		int absA = abs(a);
		int absB = abs(b);
		if (absA == absB) return a > b;
		return absA > absB;
	}
};

int main(void)
{
	int n, m;
	std::priority_queue<int, std::vector<int>, compare> heap;

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
