#include <bits/stdc++.h>
using namespace std;

int n, s, e;
pair<int, int> m[100000];

bool comp(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

stack<pair<int, int>> res;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> e;
    m[i] = {s, e};
  }

  sort(m, m + n, comp);

  res.push(m[0]);

  for (int i = 1; i < n; i++)
  {
    if (m[i].first >= res.top().second)
      res.push(m[i]);
  }

  cout << res.size() << '\n';

  return 0;
}