#include <bits/stdc++.h>
using namespace std;

int N, M;
int maze[101][101];
int visited[101][101];

int y, x;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      scanf("%1d", &maze[i][j]); // 한자리씩 끊어서 받기
    }
  }

  q.push({0, 0});
  visited[0][0] = 1;

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
      if (maze[ny][nx] == 0)
        continue;
      if (visited[ny][nx])
        continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  cout << visited[N - 1][M - 1] << '\n';
  return 0;
}