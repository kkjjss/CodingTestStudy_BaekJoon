#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long c[300000];
pair<long long, long long> a[300000];

long long res;

int main()
{
  cin >> n >> k;
  for (long long i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second;
  }
  for (long long i = 0; i < k; i++)
  {
    cin >> c[i];
  }

  sort(a, a + n);
  sort(c, c + k);

  priority_queue<long long> pq;

  long long temp = 0;
  for (long long i = 0; i < k; i++)
  {
    for (int j = temp; j < n; j++)
    {
      if (a[j].first > c[i])
        break;
      pq.push(a[j].second);
      temp++;
    }

    if (pq.size())
    {
      res += pq.top();
      pq.pop();
    }
  }

  cout << res << '\n';

  return 0;
}