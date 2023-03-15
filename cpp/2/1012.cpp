#include <bits/stdc++.h>
using namespace std;

int t, M, N, K, a, b;
int mp[51][51];
int visited[51][51];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= M)
      continue;
    if (mp[ny][nx] == 0)
      continue;
    if (visited[ny][nx])
      continue;

    dfs(ny, nx);
  }

  return;
}

int main()
{
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int ret = 0;
    fill(&mp[0][0], &mp[0][0] + 51 * 51, 0);
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    cin >> M >> N >> K;

    for (int j = 0; j < K; j++)
    {
      cin >> a >> b;
      mp[b][a] = 1;
    }

    for (int k = 0; k < N; k++)
    {
      for (int l = 0; l < M; l++)
      {
        if (visited[k][l] == 1 || mp[k][l] == 0)
          continue;
        dfs(k, l);
        ret++;
      }
    }

    cout << ret << '\n';
  }

  return 0;
}