#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

int n;
bool map[26][26];
bool visited[26][26];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int bfs(int y, int x)
{
	int num = 0;
	std::queue<std::pair<int, int> > q;
	visited[y][x] = true;
	q.push(std::make_pair(y, x));

	while (!q.empty())
	{
		num += 1;
		std::pair<int, int> cur = q.front();
		q.pop();
		int curX = cur.second, curY = cur.first;
		for (int i = 0; i < 4; ++i)
		{
			int newY = curY + dy[i], newX = curX + dx[i];
			if (newY < 1 || newX < 1 || newY > n || newX > n
				|| !map[newY][newX] || visited[newY][newX])
				continue ;
			visited[newY][newX] = true;
			q.push(std::make_pair(newY, newX));
		}
	}
	return (num);
}

int main(void)
{
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int c = getchar();
			map[i][j] = static_cast<bool>(c - '0');
		}
		getchar();
	}

	std::vector<int> num;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] && !visited[i][j])
				num.push_back(bfs(i, j));
		}
	}
	std::sort(num.begin(), num.end());
	printf("%zu\n", num.size());
	for (auto it = num.begin(); it != num.end(); ++it)
		printf("%d\n", *it);
	return (0);
}
