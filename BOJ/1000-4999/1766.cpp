#include <cstdio>
#include <queue>

void solve(std::vector<std::vector<int> > &graph, std::vector<int> &edges)
{
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	int size = graph.size();
	for (int i = 1; i < size; i++)
		if (edges[i] == 0) // 진입 간선 없는 node만 push (=선수 문제 없는 문제)
			pq.push(i);

	while (!pq.empty())
	{
		int n = pq.top();
		pq.pop();
		printf("%d ", n);

		if (graph[n].size() == 0)
			continue;
		for (auto it = graph[n].begin(); it != graph[n].end(); it++)
		{
			edges[*it] -= 1; // pop된 node와 연결된 간선 모두 제거
			if (edges[*it] == 0) // 진입 간선 수가 0이 된 경우 push
				pq.push(*it);
		}
	}
}

int main(void)
{
	int n, m, a, b;

	scanf("%d %d", &n, &m);
	std::vector<std::vector<int> > graph(n + 1, std::vector<int>());
	std::vector<int> edges(n + 1, 0);
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		edges[b] += 1;
	}

	solve(graph, edges);
	return 0;
}
