/*
Q. 종화는 유명한 방구쟁이다. 종화는 방구를 낄 때 “이러다 다 죽어!!” 를 왜치며 방구를 뀌는데 이렇게 방귀를 뀌었을 때 방귀는 상하좌우 네방향으로 뻗어나가며 종화와 연결된 육지는 모두 다 오염된다.
바다로는 방구가 갈 수 없다. 맵이 주어졌을 때 종화가 “ 이러다 다 죽어!!”를 최소한 몇 번 외쳐야 모든 육지를 오염시킬 수 있는지 말해보자.

- 입력
    - 맵의 세로길이 N과 가로길이 M이 주어지고 이어서 N*M의 맵이 주어진다.
- 출력
    - 몇 번 외쳐야 하는지 출력하라.
*/

#include <bits/stdc++.h>
using namespace std;

int N = 5, M = 5;

int mp[5][5] = {
    {1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 0, 1, 1, 0},
    {1, 0, 0, 0, 1},
};

int visited[5][5];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
  visited[y][x] = 1;
  cout << y << ':' << x << '\n';
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    // underflow
    if (ny < 0 || ny >= N || nx < 0 || nx >= M)
      continue;

    // overflow
    if (mp[ny][nx] == 0)
      continue;
    if (visited[ny][nx] != 0)
      continue;

    dfs(ny, nx);
  }
}

int cnt;

int main()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (visited[i][j] || !mp[i][j])
        continue;
      dfs(i, j);
      cnt++;
      cout << "-----" << '\n';
    }
  }
  cout << cnt << '\n';
  return 0;
}