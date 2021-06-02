#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> node[1001];
std::vector<bool> visited(1001, false);

void dfs(int curNode)
{
	visited[curNode] = true;

	printf("%d", curNode);
	for (auto it = node[curNode].begin(); it != node[curNode].end(); ++it)
		if (!visited[*it])
		{
			printf(" ");
			dfs(*it);
		}
}

void bfs(int curNode)
{
	std::queue<int> q;

	q.push(curNode);
	visited[curNode] = true;
	while (!q.empty())
	{
		curNode = q.front();
		q.pop();
		printf("%d", curNode);
		for (auto it = node[curNode].begin(); it != node[curNode].end(); ++it)
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		if (!q.empty())
			printf(" ");
	}
}

int main(void)
{
	int n, m, v;
	
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		std::sort(node[i].begin(), node[i].end());
	dfs(v);
	printf("\n");
	visited.assign(1001, false);
	bfs(v);
	printf("\n");
	return (0);
}
