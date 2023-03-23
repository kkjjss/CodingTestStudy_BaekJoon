#include <bits/stdc++.h>
using namespace std;

int n, m, mp[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> v;
int res = 987654321;

int getDist(int y, int x, vector<pair<int, int>> v)
{
  int res = 987654321;
  for (auto a : v)
  {
    res = min(res, abs(a.first - y) + abs(a.second - x));
  }
  return res;
}

int go(vector<pair<int, int>> v)
{
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mp[i][j] == 1)
        res += getDist(i, j, v);
    }
  }
  return res;
}

void combination(int start, vector<pair<int, int>> v)
{
  // 3개의 구슬이 뽑아지면
  if (v.size() == m)
  {
    res = min(res, go(v));
    return;
  }
  for (int i = start + 1; i < chicken.size(); i++)
  {
    v.push_back(chicken[i]);
    combination(i, v);
    v.pop_back();
  }
  return;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> mp[i][j];
      if (mp[i][j] == 2)
        chicken.push_back({i, j});
    }
  }

  combination(-1, v);

  cout << res << '\n';

  return 0;
}