#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int> graph[101];
std::vector<bool> visited(101);
int num;

void dfs(int cur)
{
	visited[cur] = true;
	num += 1;
	for (auto it = graph[cur].begin(); it != graph[cur].end(); ++it)
		if (!visited[*it])
			dfs(*it);
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		std::sort(graph[i].begin(), graph[i].end());
	dfs(1);
	printf("%d\n", num - 1);
	return (0);
}
