#include <bits/stdc++.h>
using namespace std;

int n, m, ret, visited[50][50];
char mp[50][50];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x)
{
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = 1;
  while (q.size())
  {
    pair<int, int> here;
    here = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = here.first + dy[i];
      int nx = here.second + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || mp[ny][nx] == 'W')
        continue;
      visited[ny][nx] = visited[here.first][here.second] + 1;
      q.push({ny, nx});
      ret = max(ret, visited[ny][nx] - 1);
    }
  }
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mp[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mp[i][j] == 'L')
      {
        fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
        bfs(i, j);
      }
    }
  }
  cout << ret << '\n';

  return 0;
}