#include <bits/stdc++.h>
using namespace std;

int n, res;
pair<int, int> dp[10000];

bool comp(pair<int, int> a, pair<int, int> b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return a.first > b.first;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int p, d;
    cin >> p >> d;
    dp[i] = {d, p};
  }

  sort(dp, dp + n, comp);

  priority_queue<int> pq;

  pq.push(dp[0].second);
  int d = dp[0].first;
  int temp = 1;

  while (temp < n - 1)
  {
    for (int i = temp; i < n; i++)
    {
      if (dp[i].first < d)
        break;
      pq.push(dp[i].second);
      temp++;
    }

    if (pq.size())
    {
      int i = d - dp[temp].first;
      while (i-- && pq.size())
      {
        cout << pq.top() << '\n';
        res += pq.top();
        pq.pop();
      }
      d = dp[temp].first;
    }
  }

  cout << res << '\n';

  return 0;
}