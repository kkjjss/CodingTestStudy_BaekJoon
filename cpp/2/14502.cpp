#include <bits/stdc++.h>
using namespace std;

int n, m;
int mp[8][8];
int visited[8][8];
int mp_copy[8][8];
int res;

vector<pair<int, int>> z;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
      continue;
    if (mp_copy[ny][nx] != 0)
      continue;
    if (visited[ny][nx] == 1)
      continue;

    mp_copy[ny][nx] = 1;
    go(ny, nx);
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mp[i][j];
      if (mp[i][j] == 0)
        z.push_back({i, j});
    }
  }

  for (int i = 0; i < z.size(); i++)
  {
    for (int j = i + 1; j < z.size(); j++)
    {
      for (int k = j + 1; k < z.size(); k++)
      {
        fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
        for (int a = 0; a < n; a++)
        {
          for (int b = 0; b < m; b++)
          {
            if ((a == z[i].first && b == z[i].second) || (a == z[j].first && b == z[j].second) || (a == z[k].first && b == z[k].second))
              mp_copy[a][b] = 3;
            else
              mp_copy[a][b] = mp[a][b];
          }
        }
        for (int a = 0; a < n; a++)
        {
          for (int b = 0; b < m; b++)
          {
            if (mp_copy[a][b] == 2)
              go(a, b);
          }
        }
        int tmp = 0;
        for (int a = 0; a < n; a++)
        {
          for (int b = 0; b < m; b++)
          {
            if (mp_copy[a][b] == 0)
              tmp++;
          }
        }
        if (res < tmp)
          res = tmp;
      }
    }
  }

  cout << res << '\n';
  return 0;
}