#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int mp[10][10];
int ret = INF, n = 10;
int p[] = {0, 5, 5, 5, 5, 5};

bool checkSize(int y, int x, int size)
{
  if (size + y > n || size + x > n)
    return false;

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (mp[y + i][x + j] == 0)
        return false;
    }
  }

  return true;
}

void cover(int y, int x, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      mp[y + i][x + j] = 0;
    }
  }
}

void discover(int y, int x, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      mp[y + i][x + j] = 0;
    }
  }
}

void dfs(int y, int x, int cnt)
{
  if (cnt >= ret)
    return;

  if (x == n)
  {
    dfs(y + 1, 0, cnt);
    return;
  }

  if (y == n)
  {
    ret = min(cnt, ret);
    return;
  }

  if (mp[y][x] == 0)
  {
    dfs(y, x + 1, cnt);
    return;
  }

  for (int i = 5; i >= 1; i--)
  {
    if (p[i] == 0)
      continue;
    if (checkSize(y, x, i))
    {
      cover(y, x, i);
      p[i]--;
      dfs(y, x + i, cnt + 1);
      discover(y, x, i);
      p[i]++;
    }
  }

  return;
}

int main()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cin >> mp[i][j];
    }
  }
  dfs(0, 0, 0);
  cout << (ret == INF ? -1 : ret) << '\n';
  return 0;
}