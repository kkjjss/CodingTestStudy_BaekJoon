#include <bits/stdc++.h>
using namespace std;

int n, m, j;
int a[21];
pair<int, int> b;
int ret;

int main()
{
  cin >> n >> m >> j;

  b = {1, m};

  for (int i = 0; i < j; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < j; i++)
  {
    if (a[i] >= b.first && a[i] <= b.second)
      continue;
    if (a[i] < b.first)
    {
      ret += b.first - a[i];
      b.second -= b.first - a[i];
      b.first -= b.first - a[i];
    }
    if (a[i] > b.second)
    {
      ret += a[i] - b.second;
      b.first += a[i] - b.second;
      b.second += a[i] - b.second;
    }
  }

  cout << ret << '\n';

  return 0;
}