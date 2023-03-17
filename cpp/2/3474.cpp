#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n = 0;
    cin >> n;
    int res = 0;
    for (int j = 5; j <= n; j *= 5)
      res += n / j;
    cout << res << '\n';
  }

  return 0;
}