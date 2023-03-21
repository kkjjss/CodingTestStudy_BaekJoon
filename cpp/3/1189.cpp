#include <bits/stdc++.h>
using namespace std;

int n, m, k, visited[5][5];
char mp[5][5];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x)
{
  if (y == 0 && x == m - 1)
  {
    if (visited[y][x] == k)
      return 1;
    else
      return 0;
  }
  int ret = 0;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx] == 'T' || visited[ny][nx])
      continue;
    visited[ny][nx] = visited[y][x] + 1;
    ret += dfs(ny, nx);
    visited[ny][nx] = 0;
  }
  return ret;
}

int main()
{
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mp[i][j];
    }
  }

  visited[n - 1][0] = 1;
  cout << dfs(n - 1, 0) << '\n';

  return 0;
}