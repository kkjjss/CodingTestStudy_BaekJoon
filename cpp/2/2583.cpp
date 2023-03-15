#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int mp[101][101];
int visited[101][101];
int sx, sy, ex, ey;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int dfs(int y, int x)
{
  int cnt = 1;
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
      continue;
    if (visited[ny][nx] == 1)
      continue;
    if (mp[ny][nx] != 1)
      continue;
    cnt += dfs(ny, nx);
  }

  return cnt;
}

int main()
{
  cin >> n >> m >> k;

  fill(&mp[0][0], &mp[0][0] + 101 * 101, 1);

  while (k--)
  {
    cin >> sx >> sy >> ex >> ey;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i >= sy && i < ey && j >= sx && j < ex)
          mp[i][j] = 0;
      }
    }
  }

  vector<int> ret;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (visited[i][j] == 1 || mp[i][j] == 0)
        continue;
      ret.push_back(dfs(i, j));
    }
  }

  sort(ret.begin(), ret.end());

  cout << ret.size() << '\n';
  for (auto i : ret)
  {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}