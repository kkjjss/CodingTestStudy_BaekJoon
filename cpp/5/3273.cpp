#include <bits/stdc++.h>
using namespace std;

int n, x, a[100000], res;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> x;

  int l = 0, r = n - 1;

  sort(a, a + n);

  for (; l < r; l++)
  {
    for (; r > l; r--)
    {
      if (a[l] + a[r] == x)
        res++;

      if (a[l] + a[r] < x)
        break;
    }
  }
  cout << res << '\n';
  return 0;
}