#include <bits/stdc++.h>
using namespace std;

// const int INF = 987654321;
int r, c, y, x, ret;
char mp[1000][1000];
int jihoon[1000][1000];
int fire[1000][1000];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main()
{
  queue<pair<int, int>> jq;
  queue<pair<int, int>> fq;
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      scanf("%1s", &mp[i][j]);
      if (mp[i][j] == 'J')
      {
        jihoon[i][j] = 1;
        jq.push({i, j});
      }
      else if (mp[i][j] == 'F')
      {
        fire[i][j] = 1;
        fq.push({i, j});
      }
    }
  }

  while (fq.size())
  {
    tie(y, x) = fq.front();
    fq.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= r || nx >= c)
        continue;
      if (fire[ny][nx])
        continue;
      if (mp[ny][nx] == '#')
        continue;
      fq.push({ny, nx});
      fire[ny][nx] = fire[y][x] + 1;
    }
  }

  while (jq.size())
  {
    tie(y, x) = jq.front();
    jq.pop();
    if (y == 0 || x == 0 || y == r - 1 || x == c - 1)
    {
      ret += jihoon[y][x];
      break;
    }
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (mp[ny][nx] == '#' || fire[ny][nx] <= jihoon[y][x] + 1)
        continue;
      jq.push({ny, nx});
      jihoon[ny][nx] = jihoon[y][x] + 1;
    }
  }

  if (ret)
    cout << ret << '\n';
  else
    cout << "IMPOSSIBLE\n";
  return 0;
}