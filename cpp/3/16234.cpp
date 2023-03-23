#include <bits/stdc++.h>
using namespace std;

int n, l, r, mp[100][100], visited[100][100];

vector<pair<int, int>> open[10000];
int cnt = 0;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x)
{
  int sum = mp[y][x];
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
      continue;
    if (abs(mp[y][x] - mp[ny][nx]) < l || abs(mp[y][x] - mp[ny][nx]) > r)
      continue;

    open[cnt].push_back({ny, nx});
    sum += dfs(ny, nx);
  }

  return sum;
}

int main()
{
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> mp[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (visited[i][j] != 0)
        continue;
      open[cnt].push_back({i, j});
      dfs(i, j);
      cnt++;
    }
  }

  for (int i = 0; i <= cnt; i++)
  {
    if (open[i].size() <= 1)
      continue;
    int s = 0;
    int sum = 0;
    for (pair<int, int> a : open[i])
    {
      s++;
      sum += mp[a.first][a.second];
    }
    printf("size: %d, sum: %d\n", s, sum);
  }

  return 0;
}