#include <bits/stdc++.h>
using namespace std;

int n, scv[3];
int res = 987654321;

void go(int *sum, int cnt)
{
  cnt++;
  if (cnt > res)
    return;
  int attack[] = {9, 3, 1};
  do
  {
    bool flag = true;
    int a[3];
    for (int i = 0; i < n; i++)
    {
      a[i] = sum[i] + attack[i];
      if (a[i] < scv[i])
        flag = false;
      cout << a[i] << " ";
    }
    cout << '\n';
    if (flag)
    {
      res = min(res, cnt);
      return;
    }
    go(a, cnt);
  } while (prev_permutation(attack, attack + 3));
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> scv[i];
  }

  int a[] = {0, 0, 0};

  go(a, 0);

  cout << res << '\n';

  return 0;
}