#include <bits/stdc++.h>
using namespace std;

int n;
int mp[101][101];
int visited[101][101];
int limit;
int res = 1;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int h)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
      continue;
    if (visited[ny][nx] != 0)
      continue;
    if (mp[ny][nx] <= h)
      continue;
    dfs(ny, nx, h);
  }

  return;
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> mp[i][j];
      if (limit < mp[i][j])
        limit = mp[i][j];
    }
  }

  for (int h = 1; h < limit; h++)
  {
    int cnt = 0;
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (visited[i][j] == 1 || mp[i][j] <= h)
          continue;
        dfs(i, j, h);
        cnt++;
      }
    }
    if (res < cnt)
      res = cnt;
  }

  cout << res << '\n';

  return 0;
}