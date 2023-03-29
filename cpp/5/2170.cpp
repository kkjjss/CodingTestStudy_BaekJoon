// 라인스위핑
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<ll, ll> dot[1000000];
ll res;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    ll x, y;
    cin >> x >> y;
    dot[i] = {x, y};
  }

  sort(dot, dot + n);

  ll left = dot[0].first, right = dot[0].second;

  for (int i = 1; i < n; i++)
  {
    if (dot[i].first <= right && dot[i].second >= right)
    {
      right = dot[i].second;
    }
    else if (right < dot[i].first)
    {
      res += right - left;
      right = dot[i].second;
      left = dot[i].first;
    }
  }

  res += right - left;

  cout << res << '\n';

  return 0;
}