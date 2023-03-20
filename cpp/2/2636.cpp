#include <bits/stdc++.h>
using namespace std;

int n, m, input;
int mp[101][101], visited[101][101];
int cnt, ret;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
      continue;
    if (visited[ny][nx] == 1)
      continue;
    if (mp[ny][nx] == 0)
      dfs(ny, nx);
    else
    {
      mp[ny][nx] = 0;
      visited[ny][nx] = 1;
    }
  }

  return;
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

  while (true)
  {
    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mp[i][j] != 1)
          continue;
        tmp++;
      }
    }
    if (tmp == 0)
      break;
    else
      ret = tmp;
    dfs(0, 0);
    cnt++;
  }

  cout << cnt << '\n'
       << ret << '\n';

  return 0;
}