#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt;

int main()
{
  cin >> n;
  cin >> m;

  int p[n];

  // 두 재료의 각 최대값은 100,000
  // 따라서 두 합의 최대값은 200,000이다.
  // 드물게 이런 조건을 처리해야 맞힐 수 있는 문제도 있으니 유의
  if (m > 200000)
    cout << 0 << '\n';
  else
  {
    for (int i = 0; i < n; i++)
    {
      cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (p[i] + p[j] == m)
          cnt++;
      }
    }
  }

  cout << cnt << '\n';

  return 0;
}