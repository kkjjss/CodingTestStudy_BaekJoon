#include <bits/stdc++.h>
using namespace std;

int n, l, r, mp[100][100], visited[100][100];

vector<pair<int, int>> v;
int sum;
int res;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
  visited[y][x] = 1;
  v.push_back({y, x});
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
      continue;
    if (abs(mp[y][x] - mp[ny][nx]) < l || abs(mp[y][x] - mp[ny][nx]) > r)
      continue;
    dfs(ny, nx);
    sum += mp[ny][nx];
  }
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

  while (true)
  {
    bool flag = false;
    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!visited[i][j])
        {
          v.clear();
          sum = mp[i][j];
          dfs(i, j);
          if (v.size() <= 1)
            continue;
          for (auto a : v)
          {
            flag = true;
            mp[a.first][a.second] = sum / v.size();
          }
        }
      }
    }
    if (!flag)
      break;
    else
      res++;
  }

  cout << res << '\n';

  return 0;
}