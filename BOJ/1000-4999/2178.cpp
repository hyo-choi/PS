#include <queue>
#include <cstdio>
#include <climits>

char map[101][101];
int dist[101][101];
int min = INT_MAX;

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

int bfs(int y, int x)
{
	std::queue<std::pair<int, int> > q;
	q.push(std::make_pair(1, 1));
	dist[1][1] = 1;

	while (!q.empty())
	{
		std::pair<int, int> cur = q.front();
		q.pop();
		if (cur.first == y && cur.second == x)
			return dist[y][x];
		for (int i = 0; i < 4; ++i)
		{
			int newY = cur.first + dy[i], newX = cur.second + dx[i];
			if (newY < 1 || newX < 1 || newY > y || newX > x
				|| map[newY][newX] == '0' || dist[newY][newX])
				continue ;
			dist[newY][newX] = dist[cur.first][cur.second] + 1;
			q.push(std::make_pair(newY, newX));
		}	
	}
	return (0);
}

int main(void)
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int c = getchar();
			map[i][j] = c;
		}
		getchar();
	}
	printf("%d\n", bfs(n, m));
	return (0);
}
