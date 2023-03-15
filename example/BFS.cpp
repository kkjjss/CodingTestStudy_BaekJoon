#include <bits/stdc++.h>
using namespace std;

int N, M;
int mp[103][103];
int visited[103][103];

int startX, startY;
int destX, destY;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void bfs(int x, int y)
{
  visited[x][y] = 1;
  q.push({x, y});

  while (q.size())
  {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M)
        continue;
      if (mp[ny][nx] == 0)
        continue;
      if (visited[ny][nx])
        continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
}

int main()
{
  cin >> N >> M;
  cin >> startX >> startY;
  cin >> destX >> destY;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> mp[i][j];
    }
  }

  bfs(startX, startY);
  cout << visited[destY][destX] << '\n';

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << visited[i][j];
    }
    cout << '\n';
  }

  return 0;
}