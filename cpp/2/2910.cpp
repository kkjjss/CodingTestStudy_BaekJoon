#include <bits/stdc++.h>
using namespace std;
int n, c;
int m[1001];
map<int, int> cnt, order;

bool comp(int a, int b)
{
  if (cnt[a] == cnt[b])
    return order[a] < order[b];
  return cnt[a] > cnt[b];
}

int main()
{
  cin >> n >> c;

  for (int i = 1; i <= n; i++)
  {
    cin >> m[i];
    cnt[m[i]]++;
    if (order[m[i]] == 0)
      order[m[i]] = i;
  }

  sort(m + 1, m + n + 1, comp);

  for (int i = 1; i <= n; i++)
  {
    cout << m[i] << ' ';
  }
  cout << '\n';

  return 0;
}